/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cduverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 10:23:03 by cduverge          #+#    #+#             */
/*   Updated: 2019/10/18 10:34:02 by cduverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

int		is_there_floor(t_sdl *sdl)
{
	int		floor;
	int		x;
	int		y;

	y = 0;
	floor = 0;
	while (y < sdl->y_max)
	{
		x = 0;
		while (x < sdl->x_max)
		{
			if (sdl->map[y][x] == 0)
				floor = 1;
			++x;
		}
		++y;
	}
	if (floor == 0)
		return (-1);
	return (0);
}

void	fix_map(t_sdl *sdl)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (x < sdl->x_max)
	{
		sdl->map[0][x] = 1;
		sdl->map[sdl->y_max - 1][x] = 1;
		++x;
	}
	while (y < sdl->y_max)
	{
		sdl->map[y][0] = 1;
		sdl->map[y][sdl->x_max - 1] = 1;
		++y;
	}
}

int		check_wall(t_sdl *sdl)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (x < sdl->x_max)
	{
		if ((sdl->map[0][x] == 0) || (sdl->map[sdl->y_max - 1][x] == 0))
			return (-1);
		++x;
	}
	while (y < sdl->y_max)
	{
		if ((sdl->map[y][0] == 0) || (sdl->map[y][sdl->x_max - 1] == 0))
			return (-1);
		++y;
	}
	return (0);
}

int		parsing_3(t_sdl *sdl)
{
	if (check_wall(sdl) == -1)
	{
		ft_putendl_fd("Map without wall, I'm gonna fix that ...", 2);
		fix_map(sdl);
	}
	if (is_there_floor(sdl) == -1)
	{
		ft_putendl_fd("There is no floor on your map.", 2);
		return (-1);
	}
	return (0);
}
