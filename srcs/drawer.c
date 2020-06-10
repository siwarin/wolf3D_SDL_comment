/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwarin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 12:28:36 by siwarin           #+#    #+#             */
/*   Updated: 2019/10/02 14:43:41 by siwarin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

// Fichier servant avec une ancienne bibliothèque graphique, inutile de le prendre en compte ici
void	pixel(t_sdl *sdl, int x, int y)
{
	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGTH)
		return ;
	*((int *)sdl->ren->pixels + (y * WIDTH + x)) = sdl->color;
}

/*void	clear_image(t_sdl *sdl)
{
	ft_bzero(sdl->adr, WIDTH * HEIGTH * 4);
}

void	del_image(t_sdl *sdl)
{
	if (sdl != NULL)
	{
		if (sdl->img != NULL)
			mlx_destroy_image(sdl->ren, sdl->img);
		ft_memdel((void **)&sdl->img);
	}
	return ;
}
*/
