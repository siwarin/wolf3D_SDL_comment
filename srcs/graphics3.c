/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwarin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 14:32:39 by siwarin           #+#    #+#             */
/*   Updated: 2019/10/16 10:31:34 by siwarin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

// Cette partie sers a dessiner le sol et le plafond, suite et fin des calculs de dessin
void		calcul(t_sdl *sdl)
{
	sdl->cd = HEIGTH / (2.0 * sdl->cy - HEIGTH);
	sdl->w = (sdl->cd - sdl->dp) / (sdl->dw - sdl->dp);
	sdl->cfx = sdl->w * sdl->fx + (1.0 - sdl->w) * sdl->play.rayposx;
	sdl->cfy = sdl->w * sdl->fy + (1.0 - sdl->w) * sdl->play.rayposy;
	sdl->ftx = (int)(sdl->cfx * 64) % 64;
	sdl->fty = (int)(sdl->cfy * 64) % 64;
	sdl->cbp = ((int)(sdl->cfx) * (int)(sdl->cfy)) % 2;
}

void		next_floor(t_sdl *sdl)
{
	sdl->dw = sdl->pwalldist;
	sdl->dp = 0.0;
	if (sdl->de < 0)
		sdl->de = HEIGTH;
	sdl->cy = sdl->de;
	while (sdl->cy < HEIGTH)
	{
		calcul(sdl);
		if (sdl->cbp == 0)
			sdl->ft = 3;
		else
			sdl->ft = 4;
		sdl->color = sdl->tex[sdl->ft].data[64 * sdl->fty + sdl->ftx]
			>> 1 & 8355711;
		pixel(sdl, sdl->cx, sdl->cy);
		sdl->color = sdl->tex[6].data[64 * sdl->fty + sdl->ftx];
		sdl->j = sdl->cy;
		sdl->cy = HEIGTH - sdl->cy;
		pixel(sdl, sdl->cx, sdl->cy);
		sdl->cy = sdl->j;
		sdl->cy++;
	}
}
