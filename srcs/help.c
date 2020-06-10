/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwarin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 13:27:58 by siwarin           #+#    #+#             */
/*   Updated: 2019/10/10 14:06:18 by siwarin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

// Fonctions gérant l'affichage des différentes options possible dans le programme
// Etant faites avec l'ancienne Bibliothèque graphique, ces fonctions ne fonctionnent pas sur ce programme
// Cependant, elle contient toute les actions possibles avec le programme original
void		help2(t_sdl *sdl)
{
	mlx_string_put(sdl->ren, sdl->win, 5, 160, WHITE,
		"Switch Graphic/Economic mode : T");
	mlx_string_put(sdl->ren, sdl->win, 5, 200, WHITE, // Pas possible, Ancienne Bibliothèque graphique
		"Show/Hide this help : !");
	mlx_string_put(sdl->ren, sdl->win, 5, 220, WHITE,
		"Close and leave the game : Esc");
}

void		options(t_sdl *sdl)
{
	if (sdl->o == 1)
	{
		mlx_string_put(sdl->ren, sdl->win, 5, 0, WHITE,
			"Move Up : W or UpArrow");
		mlx_string_put(sdl->ren, sdl->win, 5, 20, WHITE,
			"Move Down : S or DownArrow");
		mlx_string_put(sdl->ren, sdl->win, 5, 40, WHITE,
			"Straf : A and D");
		mlx_string_put(sdl->ren, sdl->win, 5, 60, WHITE,
			"Straf : A and D");
		mlx_string_put(sdl->ren, sdl->win, 5, 80, WHITE,
			"Turn : Right/Left Arrow");
		mlx_string_put(sdl->ren, sdl->win, 5, 100, WHITE,
			"Sprint : Hold Shift");
		mlx_string_put(sdl->ren, sdl->win, 5, 120, WHITE,
			"Slow rotation : Hold option");
		mlx_string_put(sdl->ren, sdl->win, 5, 140, WHITE,
			"Show/Hide minimap : Tab");
		help2(sdl);
	}
}
