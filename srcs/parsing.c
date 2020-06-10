/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cduverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 14:12:17 by cduverge          #+#    #+#             */
/*   Updated: 2019/10/18 10:45:04 by cduverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

// Toute la partie parsing a été effectuée par ma collègue cduverge, sans rentrer dans les détails, le parsing s'occupe de vérifier ligne par ligne que la
// map n'ai aucun trou vers le vide dans les murs et que la map soit conforme a quelques règles comme la formation de la map, que les caractères qui
// composent la map ne soient que des chiffres entre 0 et 8, etc...
int		first_line(char *av, t_sdl *sdl, char *line)
{
	int		fd;
	int		ret;

	fd = 0;
	ret = 0;
	if ((fd = open(av, O_RDONLY)) == -1)
	{
		ft_putendl_fd("File does not exist.", 2);
		return (-1);
	}
	if ((ret = get_next_line(fd, &line) <= 0))
	{
		ft_putendl_fd("Empty file.", 2);
		return (-1);
	}
	if (check_line(line) == -1)
		return (-1);
	sdl->x_max = ft_count_words(line, ' ');
	free(line);
	sdl->y_max = 1;
	return (fd);
}

void	fill_map(int y, char *line, t_sdl *sdl)
{
	int		x;
	int		i;

	x = 0;
	i = 0;
	while (i < (int)ft_strlen(line))
	{
		sdl->map[y][x] = ft_atoi((line + i));
		++x;
		while (line[i] == ' ')
			++i;
		while ((ft_isdigit(line[i]) == 1) || line[i] == '-')
			++i;
	}
	free(line);
}

int		create_map(int fd, t_sdl *sdl)
{
	int		y;
	int		ret;
	char	*line;

	ret = 0;
	y = 0;
	line = NULL;
	if (!(sdl->map = ft_tabnew_two(sdl->x_max, sdl->y_max)))
		return (-1);
	while ((ret = get_next_line(fd, &line)))
	{
		if (ret == -1)
			return (-1);
		fill_map(y, line, sdl);
		++y;
	}
	return (1);
}

int		parsing_2(char *av, t_sdl *sdl)
{
	int		fd;

	fd = 0;
	if ((fd = open(av, O_RDONLY)) == -1)
		return (-1);
	if (create_map(fd, sdl) == -1)
		return (-1);
	if (close(fd) == -1)
		return (-1);
	if (am_i_in_a_wall(sdl) == -1)
		return (-1);
	if (parsing_3(sdl) == -1)
		return (-1);
	return (1);
}

int		parsing(char *av, char *av1, char *av2, t_sdl *sdl)
{
	int		fd;
	int		ret;
	char	*line;

	sdl->play.x = ft_atoi(av1);
	sdl->play.y = ft_atoi(av2);
	fd = 0;
	ret = 0;
	line = NULL;
	if ((fd = first_line(av, sdl, line)) == -1)
		return (-1);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (check_line(line) == -1)
			return (-1);
		if (sdl->x_max != ft_count_words(line, ' '))
			return (-1);
		free(line);
		sdl->y_max++;
	}
	if (close(fd) == -1)
		return (-1);
	if (parsing_2(av, sdl) == -1)
		return (-1);
	return (1);
}
