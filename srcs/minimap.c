/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwarin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 16:11:04 by siwarin           #+#    #+#             */
/*   Updated: 2019/10/16 10:35:06 by siwarin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

// Fonction gérant l'affichage de la minimap

void		tiles(t_sdl *sdl, int x, int y)
{
	if (sdl->map[y][x] == 1)
		sdl->color = INDIAN_RED;
	else if (sdl->map[y][x] == 2)
		sdl->color = ORANGE_RED;
	else if (sdl->map[y][x] == 3)
		sdl->color = PURPLE;
	else if (sdl->map[y][x] == 4)
		sdl->color = DARK_GRAY;
	else if (sdl->map[y][x] == 5)
		sdl->color = BLUE;
	else if (sdl->map[y][x] == 6)
		sdl->color = SPRING_GREEN;
	else if (sdl->map[y][x] == 7)
		sdl->color = SADDLEBROWN;
	else if (sdl->map[y][x] == 8)
		sdl->color = DARK_GOLDEN_ROD;
	else if (sdl->map[y][x] >= 9)
		sdl->color = WHITE_SMOKE;
}

void		draws(t_sdl *sdl, int x, int y, int size)
{
	int	v;
	int	w;

	w = size * 2 + size * y;
	while (w < size * 2 + (size * (y + 1)))
	{
		v = size * 2 + size * x;
		while (v < size * 2 + (size * (x + 1)))
		{
			tiles(sdl, x, y);
			pixel(sdl, v, w);
			v++;
		}
		w++;
	}
}

void		minimap(t_sdl *sdl)
{
	int	x;
	int	y;
	int	size;

	sdl->color = WHITE;
	size = WIDTH / 10 / sdl->x_max;
	x = 0;
	while (x < sdl->x_max)
	{
		y = 0;
		while (y < sdl->y_max)
		{
			if (sdl->map[y][x] != 0)
				draws(sdl, x, y, size);
			y++;
		}
		x++;
	}
	sdl->color = GOLDEN_ROD;
	x = sdl->play.x;
	y = sdl->play.y;
	draws(sdl, y, x, size);
}
