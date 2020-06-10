/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwarin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 13:01:26 by siwarin           #+#    #+#             */
/*   Updated: 2019/10/18 10:44:36 by cduverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

// Fonction qui s'occupe de libérer toute la mémoire allouée pour ensuite quitter le programme par la touche echap
int		hook_keydown(t_sdl *sdl)
{
	int		y;

	y = 0;
	SDL_FreeSurface(sdl->ren);
	SDL_DestroyWindow(sdl->win);
	while (y < sdl->y_max)
	{
		free(sdl->map[y]);
		++y;
	}
	free(sdl->map);
	sdl->map = NULL;
	exit(EXIT_SUCCESS);
	return (0);
}

// Toute les initialisations de la SDL sont faites ici
void	ft_init(t_sdl *sdl)
{
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) != 0)
	{
		ft_putstr(SDL_GetError());
		ft_putstr("\n\n");
	}
	sdl->win = SDL_CreateWindow("Doom-Nukem", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGTH, 0);
	if (!sdl->win)
	{
		ft_putstr(SDL_GetError());
		ft_putstr("\n\n");
	}
	if ((sdl->ren = SDL_GetWindowSurface(sdl->win)) == NULL)
	{
		ft_putstr(SDL_GetError());
		ft_putstr("Surface error.\n");
	}
	sdl->f.step = 0.0;
	sdl->f.current = 0.0;
	sdl->f.delta = 0.0;
	sdl->f.last = 0.0;
	sdl->f.count = 0.0;
}

void	init_keyboard(t_keyboard *k)
{
	k->state = SDL_GetKeyboardState(NULL);
}

// Début du programme graphique, initialisation de SDL et des inputs clavier 
void	wolf(t_sdl *sdl)
{
	init_keyboard(&sdl->k);
	ft_init(sdl);
	sdl->i = 0;
	sdl->j = 0;
	sdl->o = 0;
	sdl->m = 0;
	while (1) // Cette première boucle sert à faire tourner le programme même sans interaction de la part de l'utilisateur
	{// La différence est moindre ici, mais dans le cas où un ennemi voudrait s'approcher, il ne bougerais pas si le joueur ne bouge pas
		sdl->f.last = sdl->f.current;
		sdl->f.current = SDL_GetTicks();
		sdl->f.delta = sdl->f.current - sdl->f.last;
		sdl->f.count += sdl->f.delta;
		while (sdl->f.count >= sdl->f.step)
		{
			while(SDL_PollEvent(&sdl->e))
			{
				if (sdl->e.type == SDL_KEYDOWN)
					keyboard(sdl);
				if (sdl->e.type == SDL_KEYUP)
					keyrelease(sdl);
			}
			draw(sdl); // Fonction des calculs de dessin à l'écran
			move(sdl); // Fonction qui gère les changements de coordonnées du joueur quand il se déplace
			SDL_UpdateWindowSurface(sdl->win); // Mise à jour de l'écran 
			sdl->f.count -= sdl->f.step;
		}
	}
}

// Début du programme, vérification des arguments et passage par le parsing
int		main(int argc, char **argv)
{
	t_sdl	sdl;

	if (argc == 1)
	{
		ft_putendl_fd("./wolf3d <map> <coordinate x> <coordinate y>", 2);
		return (0);
	}
	else if (argc != 4)
	{
		ft_putendl_fd("I said : USAGE : ./wolf3d <map> <x> <y>", 2);
		return (0);
	}
	else
	{
		if (parsing(argv[1], argv[2], argv[3], &sdl) == -1)
		{
			ft_putendl_fd("Invalid map or coordinates.", 2);
			return (0);
		}
		wolf(&sdl);
		return (0);
	}
}
