/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeco <gbeco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 13:22:45 by gbeco             #+#    #+#             */
/*   Updated: 2021/06/23 11:14:02 by gbeco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	allowed_char(char c)
{
	if (c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P' || c == '\n')
		return (0);
	if (BONUS == 1 && (c == 'M' || c == 'm'))
		return (0);
	return (1);
}

void	flood_fill(t_vars *vars, char **tab, int x, int y)
{
	if (x < 0 || y < 0 || x >= vars->length_map || y >= vars->height_map)
		return ;
	if (tab[y][x] != '1' && tab[y][x] != '*')
		tab[y][x] = '*';
	else
		return ;
	flood_fill(vars, tab, x + 1, y);
	flood_fill(vars, tab, x - 1, y);
	flood_fill(vars, tab, x, y + 1);
	flood_fill(vars, tab, x, y - 1);
	return ;
}

char	**copy_map(t_vars *vars)
{
	char	**new;
	int		i;

	if (ft_talloc(&new, sizeof(char *) * (vars->height_map + 1)))
		return (NULL);
	new[vars->height_map] = 0;
	i = -1;
	while (++i < vars->height_map)
		new[i] = ft_strdup(vars->map[i]);
	return (new);
}

int	check_nbr_elem(t_vars *vars)
{
	if (vars->nbr_collect < 1)
		return (error(vars, "at least one collectible needed\n"));
	if (vars->nbr_exit < 1)
		return (error(vars, "at least one exit needed\n"));
	if (vars->nbr_start == 0)
		return (error(vars, "start position missing\n"));
	if (vars->nbr_start > 1)
		return (error(vars, "too many start position\n"));
	return (0);
}

int	check_last_line(t_vars *vars, char *line)
{
	if (line[0] != 0)
	{
		vars->height_map++;
		if (vars->length_map != ft_strlen(line))
		{
			free(line);
			return (error(vars, "map invalid\n"));
		}
	}
	free(line);
	line = NULL;
	return (0);
}
