/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwarin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 13:04:08 by siwarin           #+#    #+#             */
/*   Updated: 2019/10/16 10:33:13 by siwarin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void	next(t_sdl *sdl)
{
	sdl->cy = sdl->ds;
	while (sdl->cy <= sdl->de)
	{
		if (sdl->t == 1)
		{
			sdl->texty = (sdl->cy * 2 - HEIGTH + sdl->hl) * (64 / 2) / sdl->hl;
			sdl->color = sdl->tex[sdl->id].data[(sdl->texty * sdl->tex
				[sdl->id].s_l / 4) + sdl->textx];
			if (sdl->side == 1)
				sdl->color = (sdl->color >> 1) & 8355711;
		}
		pixel(sdl, sdl->cx, sdl->cy);
		sdl->cy++;
	}
}

// Les murs ayant été détectés et dessinés, le sol peut être dessiné sans soucis
void	draw_floor(t_sdl *sdl)
{
	if (sdl->side == 0 && sdl->play.raydirx > 0)
	{
		sdl->fx = sdl->mapx;
		sdl->fy = sdl->mapy + sdl->wallx;
	}
	if (sdl->side == 0 && sdl->play.raydirx < 0)
	{
		sdl->fx = sdl->mapx + 1.0;
		sdl->fy = sdl->mapy + sdl->wallx;
	}
	if (sdl->side == 1 && sdl->play.raydiry > 0)
	{
		sdl->fx = sdl->mapx + sdl->wallx;
		sdl->fy = sdl->mapy;
	}
	if (sdl->side == 1 && sdl->play.raydiry < 0)
	{
		sdl->fx = sdl->mapx + sdl->wallx;
		sdl->fy = sdl->mapy + 1.0;
	}
	next_floor(sdl);
}

// Les murs ayant été detecté, ils pourront être dessiner en fonction de la longueur du rayon pour que les proportions soient justes 
void	draw_wall(t_sdl *sdl)
{
	sdl->id = sdl->map[sdl->mapx][sdl->mapy] - 1;
	if (sdl->side == 0)
		sdl->wallx = sdl->play.rayposy + sdl->pwalldist * sdl->play.raydiry;
	else
		sdl->wallx = sdl->play.rayposx + sdl->pwalldist * sdl->play.raydirx;
	sdl->wallx -= floor(sdl->wallx);
	sdl->textx = (int)(sdl->wallx * 64);
	if (sdl->side == 0 && sdl->play.raydirx > 0)
		sdl->textx = 64 - sdl->textx - 1;
	if (sdl->side == 1 && sdl->play.raydiry < 0)
		sdl->textx = 64 - sdl->textx - 1;
	next(sdl);
	if (sdl->t == 1)
		draw_floor(sdl);
}
// Correctif d'un défaut visuel du raycasting, sans ce correctif, les murs sur la droite et la gauche de l'écran seront arrondit dût a un problème mathématique du lancer de rayon
void	fisheye(t_sdl *sdl)
{
	if (sdl->side == 0)
		sdl->pwalldist = (sdl->mapx - sdl->play.rayposx
				+ (1 - sdl->stepx) / 2) / sdl->play.raydirx;
	else
		sdl->pwalldist = (sdl->mapy - sdl->play.rayposy
				+ (1 - sdl->stepy) / 2) / sdl->play.raydiry;
}
// Initialisation des différentes couleurs pour le mode sans texture du programme
void	draw_color(t_sdl *sdl)
{
	if (sdl->t == 0)
	{
		while (sdl->cy <= HEIGTH)
		{
			sdl->color = SALMON;
			pixel(sdl, sdl->cx - 1, sdl->cy);
			sdl->color = STEEL_BLUE;
			sdl->j = sdl->cy;
			sdl->cy = HEIGTH - sdl->cy - 1;
			pixel(sdl, sdl->cx - 1, sdl->cy);
			sdl->cy = sdl->j;
			sdl->cy++;
		}
		if (sdl->side == 0)
			sdl->color = BEIGE;
		else
			sdl->color = WHEAT;
	}
	draw_wall(sdl);
	if (sdl->de < 0)
		sdl->de = HEIGTH;
	sdl->cy = sdl->de;
}
