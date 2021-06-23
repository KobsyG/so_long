/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeco <gbeco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 16:30:12 by gbeco             #+#    #+#             */
/*   Updated: 2021/06/23 12:58:14 by gbeco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	freemap_unfinished(char **tab, int i)
{
	while (--i >= 0)
	{
		free(tab[i]);
		tab[i] = NULL;
	}
	free(tab);
	tab = NULL;
	ft_putstr_fd("Error\ncharracter invalid\n", 2);
	return (-1);
}

void	freemap(char **tab)
{
	int	i;

	i = -1;
	while (tab && tab[++i] != NULL)
	{
		free(tab[i]);
		tab[i] = NULL;
	}
	free(tab);
	tab = NULL;
}

int	error(t_vars *vars, char *s)
{
	freemap(vars->map);
	if (vars->nbr_patrol_hori > 0)
		freetab_int(vars->patrol_hori);
	if (vars->nbr_patrol_vert > 0)
		freetab_int(vars->patrol_vert);
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(s, 2);
	exit (0);
	return (-1);
}

void	freetab_int(int **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

int	check_first_line(t_vars *vars, char *line)
{
	if (line[0] == 0)
	{
		free(line);
		return (error(vars, "map invalid\n"));
	}
	return (0);
}
