/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwarin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 10:18:10 by siwarin           #+#    #+#             */
/*   Updated: 2019/10/02 15:21:56 by siwarin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

// Suite de la fonction de translation de la caméra
void	move2(t_sdl *sdl)
{
	if (sdl->md == 1)
	{
		if (sdl->map[(int)(sdl->play.x - sdl->play.dirx * sdl->play.speed)]
			[(int)(sdl->play.y)] == 0)
			sdl->play.x -= sdl->play.dirx * sdl->play.speed;
		if (sdl->map[(int)(sdl->play.x)]
				[(int)(sdl->play.y - sdl->play.diry * sdl->play.speed)] == 0)
			sdl->play.y -= sdl->play.diry * sdl->play.speed;
	}
	if (sdl->mu == 1)
	{
		if (sdl->map[(int)(sdl->play.x + sdl->play.dirx * sdl->play.speed)]
				[(int)(sdl->play.y)] == 0)
			sdl->play.x += sdl->play.dirx * sdl->play.speed;
		if (sdl->map[(int)(sdl->play.x)]
				[(int)(sdl->play.y + sdl->play.diry * sdl->play.speed)] == 0)
			sdl->play.y += sdl->play.diry * sdl->play.speed;
	}
	turn(sdl);
}

// Fonction permettant la translation de la caméra 
int		move(t_sdl *sdl)
{
	if (sdl->ml == 1)
	{
		if (sdl->map[(int)(sdl->play.x - sdl->planex * sdl->play.speed)]
				[(int)(sdl->play.y)] == 0)
			sdl->play.x -= sdl->planex * sdl->play.speed;
		if (sdl->map[(int)(sdl->play.x)]
				[(int)(sdl->play.y - sdl->planey * sdl->play.speed)] == 0)
			sdl->play.y -= sdl->planey * sdl->play.speed;
	}
	if (sdl->mr == 1)
	{
		if (sdl->map[(int)(sdl->play.x + sdl->planex * sdl->play.speed)]
				[(int)(sdl->play.y)] == 0)
			sdl->play.x += sdl->planex * sdl->play.speed;
		if (sdl->map[(int)(sdl->play.x)]
				[(int)(sdl->play.y + sdl->planey * sdl->play.speed)] == 0)
			sdl->play.y += sdl->planey * sdl->play.speed;
	}
	move2(sdl);
	draw(sdl);
	return (0);
}

// Fonction permettant la rotation de la caméra
void	turn(t_sdl *sdl)
{
	double op;
	double od;

	if (sdl->rl == 1)
	{
		od = sdl->play.dirx;
		sdl->play.dirx = sdl->play.dirx * cos(sdl->play.rot)
			- sdl->play.diry * sin(sdl->play.rot);
		sdl->play.diry = od * sin(sdl->play.rot) + sdl->play.diry
			* cos(sdl->play.rot);
		op = sdl->planex;
		sdl->planex = sdl->planex * cos(sdl->play.rot) - sdl->planey
			* sin(sdl->play.rot);
		sdl->planey = op * sin(sdl->play.rot) + sdl->planey
			* cos(sdl->play.rot);
	}
	turn2(sdl);
}

// Gestion des relâchements de touche
int		keyrelease(t_sdl *sdl)
{
	if (sdl->e.key.keysym.sym == SDLK_w || sdl->e.key.keysym.sym == SDLK_UP)
		sdl->mu = 0;
	else if (sdl->e.key.keysym.sym == SDLK_s || sdl->e.key.keysym.sym == SDLK_DOWN)
		sdl->md = 0;
	else if (sdl->e.key.keysym.sym == SDLK_d)
		sdl->mr = 0;
	else if (sdl->e.key.keysym.sym == SDLK_a)
		sdl->ml = 0;
	else if (sdl->e.key.keysym.sym == SDLK_LEFT)
		sdl->rl = 0;
	else if (sdl->e.key.keysym.sym == SDLK_RIGHT)
		sdl->rr = 0;
	else if (sdl->e.key.keysym.sym == SDLK_LSHIFT || sdl->e.key.keysym.sym == SDLK_RSHIFT)
		sdl->play.speed = 0.05;
	else if (sdl->e.key.keysym.sym == SDLK_LALT || sdl->e.key.keysym.sym == SDLK_RALT)
		sdl->play.rot = 0.1;
	return (0);
}

// Gestion des appuis de touche
int		keyboard(t_sdl *sdl)
{
	if (sdl->e.key.keysym.sym == SDLK_ESCAPE)
		hook_keydown(sdl);
	else if (sdl->e.key.keysym.sym == SDLK_w || sdl->e.key.keysym.sym == SDLK_UP)
		sdl->mu = 1;
	else if (sdl->e.key.keysym.sym == SDLK_s || sdl->e.key.keysym.sym == SDLK_DOWN)
		sdl->md = 1;
	else if (sdl->e.key.keysym.sym == SDLK_d)
		sdl->mr = 1;
	else if (sdl->e.key.keysym.sym == SDLK_a)
		sdl->ml = 1;
	else if (sdl->e.key.keysym.sym == SDLK_LEFT)
		sdl->rl = 1;
	else if (sdl->e.key.keysym.sym == SDLK_RIGHT)
		sdl->rr = 1;
	else if (sdl->e.key.keysym.sym == SDLK_LSHIFT || sdl->e.key.keysym.sym == SDLK_RSHIFT)
		sdl->play.speed = 0.1;
	else if (sdl->e.key.keysym.sym == SDLK_LALT || sdl->e.key.keysym.sym == SDLK_RALT)
		sdl->play.rot = 0.005;
	keyboard2(sdl);
	return (1);
}
