/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usefull.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cduverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 16:01:14 by cduverge          #+#    #+#             */
/*   Updated: 2019/10/18 10:15:39 by cduverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

// Fichier de parsing
void	free_pars(t_pars *pars)
{
	t_pars	*cur;

	while (pars)
	{
		cur = pars;
		pars = pars->next;
		free(cur);
		cur = NULL;
	}
	pars = NULL;
}

int		malloc_pars(t_pars *begin)
{
	t_pars	*cur;
	t_pars	*new;

	cur = begin;
	while (cur->next != NULL)
		cur = cur->next;
	if (!(new = (t_pars *)malloc(sizeof(t_pars))))
		return (-1);
	new->next = NULL;
	cur->next = new;
	return (0);
}

int		**ft_tabnew_two(size_t x, size_t y)
{
	size_t	i;
	int		**tab;

	i = 0;
	if (!(tab = (int **)malloc(sizeof(*tab) * y)))
		return (NULL);
	while (i < y)
	{
		if (!(tab[i] = malloc(sizeof(**tab) * x)))
			return (NULL);
		i++;
	}
	return (tab);
}

int		check_line(char *l)
{
	int		i;

	i = 0;
	while (l[i])
	{
		if ((l[i] >= '0' && l[i] <= '8') || l[i] == ' ' || l[i] == '-')
			++i;
		else
		{
			ft_putendl_fd("Wrong data.", 2);
			free(l);
			return (-1);
		}
	}
	return (1);
}

int		am_i_in_a_wall(t_sdl *sdl)
{
	int		x;
	int		y;
	double	center;

	center = 0.5;
	x = (int)sdl->play.x;
	y = (int)sdl->play.y;
	if (x >= sdl->x_max || y >= sdl->y_max || x <= 0 || y <= 0)
		return (-1);
	if (sdl->map[y][x] != 0)
		return (-1);
	sdl->play.x = sdl->play.x + center;
	sdl->play.y = sdl->play.y + center;
	return (1);
}
