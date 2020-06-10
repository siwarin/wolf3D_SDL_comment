/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwarin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 11:32:59 by siwarin           #+#    #+#             */
/*   Updated: 2019/10/15 16:55:59 by cduverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

//initialisation des variables nécessaires au bon fonctionnement de l'algorithme de dessin du programme
void	wolfinit(t_sdl *sdl)
{
	sdl->play.dirx = -1;
	sdl->play.diry = 0;
	sdl->planex = 0;
	sdl->planey = 0.66;
	sdl->i = 1;
	sdl->play.speed = 0.05;
	sdl->play.rot = 0.1;
	sdl->mu = 0;
	sdl->md = 0;
	sdl->mr = 0;
	sdl->ml = 0;
	sdl->t = 0;
	sdl->textx = 0;
	sdl->texty = 0;
	//load_t(sdl); // Si vous souhaitez essayer les textures de mon programme, décommentez cette ligne
}

// Préparation des différents lancers de rayons, notamment par le calcul du champs de vision
void	raycasting(t_sdl *sdl)
{
	sdl->play.camx = 2 * sdl->cx / (double)(WIDTH) - 1;
	sdl->play.rayposx = sdl->play.x;
	sdl->play.rayposy = sdl->play.y;
	sdl->play.raydirx = sdl->play.dirx + sdl->planex * sdl->play.camx;
	sdl->play.raydiry = sdl->play.diry + sdl->planey * sdl->play.camx;
	sdl->mapx = (int)sdl->play.rayposx;
	sdl->mapy = (int)sdl->play.rayposy;
}
// La DDA, qui permet de diriger le rayon vers son objectif précis
void	dda(t_sdl *sdl)
{
	sdl->ddistx = sqrt(1 + (sdl->play.raydiry * sdl->play.raydiry)
						/ (sdl->play.raydirx * sdl->play.raydirx));
	sdl->ddisty = sqrt(1 + (sdl->play.raydirx * sdl->play.raydirx)
						/ (sdl->play.raydiry * sdl->play.raydiry));
	sdl->hit = 0;
	if (sdl->play.raydirx < 0)
	{
		sdl->stepx = -1;
		sdl->sdistx = (sdl->play.rayposx - sdl->mapx) * sdl->ddistx;
	}
	else
	{
		sdl->stepx = 1;
		sdl->sdistx = (sdl->mapx + 1.0 - sdl->play.rayposx) * sdl->ddistx;
	}
	if (sdl->play.raydiry < 0)
	{
		sdl->stepy = -1;
		sdl->sdisty = (sdl->play.rayposy - sdl->mapy) * sdl->ddisty;
	}
	else
	{
		sdl->stepy = 1;
		sdl->sdisty = (sdl->mapy + 1.0 - sdl->play.rayposy) * sdl->ddisty;
	}
}
// Détection du mur par un rayon
void	wall(t_sdl *sdl)
{
	while (sdl->hit == 0)
	{
		if (sdl->sdistx < sdl->sdisty)
		{
			sdl->sdistx += sdl->ddistx;
			sdl->mapx += sdl->stepx;
			sdl->side = 0;
		}
		else
		{
			sdl->sdisty += sdl->ddisty;
			sdl->mapy += sdl->stepy;
			sdl->side = 1;
		}
		if (sdl->map[sdl->mapx][sdl->mapy] >= 1)
			sdl->hit = 1;
	}
}
// Le moteur raycasting, le nerf du programme
void	draw(t_sdl *sdl)
{
	sdl->cx = 0;
	sdl->cy = 0;
	if (sdl->i == 0)
		wolfinit(sdl);
	while (sdl->cx <= WIDTH)
	{
		raycasting(sdl);
		dda(sdl);
		wall(sdl);
		fisheye(sdl);
		sdl->hl = (int)(HEIGTH / sdl->pwalldist);
		sdl->ds = -sdl->hl / 2 + HEIGTH / 2;
		if (sdl->ds < 0)
			sdl->ds = 0;
		sdl->de = sdl->hl / 2 + HEIGTH / 2;
		if (sdl->de >= HEIGTH)
			sdl->de = HEIGTH;
		draw_color(sdl);
		sdl->cx++;
	}
	if (sdl->m == 1)
		minimap(sdl);
	//options(sdl);
}
