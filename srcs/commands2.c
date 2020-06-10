/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwarin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 14:23:32 by siwarin           #+#    #+#             */
/*   Updated: 2019/10/16 10:28:25 by siwarin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

// fichier complémentaire a commands.c. Constitue un simple respect de la norme de 42

void	turn2(t_sdl *sdl)
{
	double op;
	double od;

	if (sdl->rr == 1)
	{
		od = sdl->play.dirx;
		sdl->play.dirx = sdl->play.dirx * cos(-sdl->play.rot)
			- sdl->play.diry * sin(-sdl->play.rot);
		sdl->play.diry = od * sin(-sdl->play.rot) + sdl->play.diry
			* cos(-sdl->play.rot);
		op = sdl->planex;
		sdl->planex = sdl->planex * cos(-sdl->play.rot) - sdl->planey
			* sin(-sdl->play.rot);
		sdl->planey = op * sin(-sdl->play.rot) + sdl->planey
			* cos(-sdl->play.rot);
	}
}

void	keyboard2(t_sdl *sdl)
{
	/*if (sdl->e.key.keysym.sym == SDLK_t)
	{
		if (sdl->t == 0)
			sdl->t = 1;
		else
			sdl->t = 0;
	}*/
	if (sdl->e.key.keysym.sym == SDLK_q)
	{
		if (sdl->o == 0)
			sdl->o = 1;
		else
			sdl->o = 0;
	}
	if (sdl->e.key.keysym.sym == SDLK_TAB)
	{
		if (sdl->m == 0)
			sdl->m = 1;
		else
			sdl->m = 0;
	}
}
