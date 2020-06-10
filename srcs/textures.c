/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwarin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 10:33:26 by siwarin           #+#    #+#             */
/*   Updated: 2019/10/15 13:46:30 by siwarin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

// Fichier qui gère le chargement des différentes textures pour le programme

void	load2(t_sdl *sdl, int a, int b)
{
	sdl->tex[5].img = mlx_xpm_file_to_image(sdl->ren, "ress/mossy.xpm", &a, &b);
	sdl->tex[5].data = (uint32_t *)mlx_get_data_addr(sdl->tex[5].img,
			&sdl->tex[5].bpp, &sdl->tex[5].s_l, &sdl->tex[5].endian);
	sdl->tex[6].img = mlx_xpm_file_to_image(sdl->ren, "ress/wood.xpm", &a, &b);
	sdl->tex[6].data = (uint32_t *)mlx_get_data_addr(sdl->tex[6].img,
			&sdl->tex[6].bpp, &sdl->tex[6].s_l, &sdl->tex[6].endian);
	sdl->tex[7].img = mlx_xpm_file_to_image(sdl->ren, "ress/cs.xpm", &a, &b);
	sdl->tex[7].data = (uint32_t *)mlx_get_data_addr(sdl->tex[7].img,
			&sdl->tex[7].bpp, &sdl->tex[7].s_l, &sdl->tex[7].endian);
}

void	load_t(t_sdl *sdl)
{
	int		a;
	int		b;

	a = 64;
	b = 64;
	sdl->tex[0].img = mlx_xpm_file_to_image(sdl->ren, "ress/eagle.xpm", &a, &b);
	sdl->tex[0].data = (uint32_t *)mlx_get_data_addr(sdl->tex[0].img,
			&sdl->tex[0].bpp, &sdl->tex[0].s_l, &sdl->tex[0].endian);
	sdl->tex[1].img = mlx_xpm_file_to_image(sdl->ren, "ress/rb.xpm", &a, &b);
	sdl->tex[1].data = (uint32_t *)mlx_get_data_addr(sdl->tex[1].img,
			&sdl->tex[1].bpp, &sdl->tex[1].s_l, &sdl->tex[1].endian);
	sdl->tex[2].img = mlx_xpm_file_to_image(sdl->ren, "ress/ps.xpm", &a, &b);
	sdl->tex[2].data = (uint32_t *)mlx_get_data_addr(sdl->tex[2].img,
			&sdl->tex[2].bpp, &sdl->tex[2].s_l, &sdl->tex[2].endian);
	sdl->tex[3].img = mlx_xpm_file_to_image(sdl->ren, "ress/st.xpm", &a, &b);
	sdl->tex[3].data = (uint32_t *)mlx_get_data_addr(sdl->tex[3].img,
			&sdl->tex[3].bpp, &sdl->tex[3].s_l, &sdl->tex[3].endian);
	sdl->tex[4].img = mlx_xpm_file_to_image(sdl->ren, "ress/bs.xpm", &a, &b);
	sdl->tex[4].data = (uint32_t *)mlx_get_data_addr(sdl->tex[4].img,
			&sdl->tex[4].bpp, &sdl->tex[4].s_l, &sdl->tex[4].endian);
	load2(sdl, a, b);
}
