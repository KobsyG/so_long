/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeco <gbeco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 15:21:46 by gbeco             #+#    #+#             */
/*   Updated: 2021/06/23 12:50:02 by gbeco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	size_map(int fd, t_vars *vars)
{
	char	*line;
	int		oct;

	oct = get_next_line(fd, &line);
	if (check_first_line(vars, line) == -1)
		return (-1);
	while (oct != 0)
	{
		if (oct == -1)
		{
			free(line);
			return (error(vars, "read error\n"));
		}
		if (vars->length_map != 0 && vars->length_map != ft_strlen(line))
		{
			free(line);
			return (error(vars, "map invalid\n"));
		}
		vars->height_map++;
		vars->length_map = ft_strlen(line);
		free(line);
		line = NULL;
		oct = get_next_line(fd, &line);
	}
	return (check_last_line(vars, line));
}

int	complete_and_check_char(char *line, t_vars *vars, int nbr_line)
{
	int	i;

	if (ft_salloc(&vars->map[nbr_line], sizeof(char) * (vars->length_map + 1)))
		return (error(vars, "allocation error\n"));
	vars->map[nbr_line][vars->length_map] = 0;
	i = -1;
	while (line[++i])
	{
		if (allowed_char(line[i]) != 0)
			return (freemap_unfinished(vars->map, nbr_line + 1));
		if (line[i] == 'C')
			vars->nbr_collect++;
		if (line[i] == 'E')
			vars->nbr_exit++;
		if (line[i] == 'M')
			set_patrol_hori(vars, nbr_line, i);
		if (line[i] == 'm')
			set_patrol_vert(vars, nbr_line, i);
		if (line[i] == 'P')
			get_guy_pos(vars, i, nbr_line);
		else
			vars->map[nbr_line][i] = line[i];
	}
	return (0);
}

int	complete_map(int fd, t_vars *vars)
{
	char	*line;
	int		i;
	int		oct;

	fd = open(vars->path_map, O_RDONLY);
	if (ft_talloc(&vars->map, sizeof(char *) * (vars->height_map + 1)))
		return (-1);
	vars->map[vars->height_map] = 0;
	i = -1;
	oct = 1;
	while (++i < vars->height_map)
	{
		oct = get_next_line(fd, &line);
		if (oct == -1)
			return (error(vars, "read error\n"));
		if (complete_and_check_char(line, vars, i) != 0)
		{
			free(line);
			return (-1);
		}
		free(line);
		line = NULL;
	}
	return (check_nbr_elem(vars));
}

int	check_wall_closed(t_vars *vars, char **tab)
{
	int	height;
	int	lenght;

	lenght = -1;
	while (++lenght < vars->length_map - 1)
	{
		if (tab[0][lenght] == '*' || tab[vars->height_map - 1][lenght] == '*')
			return (error(vars, "map not closed\n"));
	}
	height = -1;
	while (++height < vars->height_map - 1)
	{
		if (tab[height][0] == '*' || tab[height][vars->length_map - 1] == '*')
			return (error(vars, "map not closed\n"));
	}
	return (0);
}

int	parse_map(t_vars *vars)
{
	int		fd;
	char	**tmp;

	init_vars_map(vars);
	fd = open(vars->path_map, O_RDWR);
	if (fd == -1)
	{
		ft_putstr_fd("map not found\n", 2);
		return (-1);
	}
	if (size_map(fd, vars) != 0)
		return (-1);
	close(fd);
	if (complete_map(fd, vars) != 0)
		return (-1);
	tmp = copy_map(vars);
	flood_fill(vars, tmp, vars->guy.x, vars->guy.y);
	if (check_wall_closed(vars, tmp))
	{
		freemap(tmp);
		exit(0);
		return (-1);
	}
	freemap(tmp);
	return (0);
}
