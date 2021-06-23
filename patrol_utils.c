/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patrol_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeco <gbeco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 15:50:41 by gbeco             #+#    #+#             */
/*   Updated: 2021/06/23 10:58:44 by gbeco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_change_side_hori(t_vars *vars, int i)
{
	char	c;

	c = vars->map[(int)(vars->patrol_hori[i][0])][(int)(\
	vars->patrol_hori[i][1] + vars->patrol_hori[i][2])];
	if (c == '1' || c == 'E' || c == 'C' || c == 'M' || c == 'm')
		return (1);
	else
		return (0);
}

void	check_collision_patrol_hori(t_vars *vars, int i)
{
	if (vars->map[(int)(vars->patrol_hori[i][0])][(int)(\
	vars->patrol_hori[i][1] + vars->patrol_hori[i][2])] == '*')
	{
		vars->map[(int)(vars->patrol_hori[i][0])][(int)(\
		vars->patrol_hori[i][1] + vars->patrol_hori[i][2])] = '0';
		vars->patrol_hori[i][2] *= -1;
	}
	if (vars->map[(int)(vars->patrol_hori[i][0])][(int)(\
	vars->patrol_hori[i][1] + vars->patrol_hori[i][2])] == 'M' \
	|| vars->map[(int)(vars->patrol_hori[i][0])][(int)(\
	vars->patrol_hori[i][1] + vars->patrol_hori[i][2])] == 'm')
	{
		vars->map[(int)(vars->patrol_hori[i][0])][(int)(\
		vars->patrol_hori[i][1])] = '*';
		vars->patrol_hori[i][2] *= -1;
	}
	else
		vars->map[(int)(vars->patrol_hori[i][0])][(int)(\
		vars->patrol_hori[i][1])] = '0';
}

int	check_change_side_vert(t_vars *vars, int i)
{
	char	c;

	c = vars->map[(int)(vars->patrol_vert[i][0] + \
	vars->patrol_vert[i][2])][(int)(vars->patrol_vert[i][1])];
	if (c == '1' || c == 'E' || c == 'C' || c == 'M' || c == 'm')
		return (1);
	else
		return (0);
}

void	check_collision_patrol_vert(t_vars *vars, int i)
{
	if (vars->map[(int)(vars->patrol_vert[i][0] + \
	vars->patrol_vert[i][2])][(int)(vars->patrol_vert[i][1])] == '*')
	{
		vars->map[(int)(vars->patrol_vert[i][0] + \
		vars->patrol_vert[i][2])][(int)(vars->patrol_vert[i][1])] = '0';
		vars->patrol_vert[i][2] *= -1;
	}
	if (vars->map[(int)(vars->patrol_vert[i][0] + \
	vars->patrol_vert[i][2])][(int)(vars->patrol_vert[i][1])] == 'm' \
	|| vars->map[(int)(vars->patrol_vert[i][0] + \
	vars->patrol_vert[i][2])][(int)(vars->patrol_vert[i][1])] == 'M')
	{
		vars->map[(int)(vars->patrol_vert[i][0])][(int)(\
		vars->patrol_vert[i][1])] = '*';
		vars->patrol_vert[i][2] *= -1;
	}
	else
		vars->map[(int)(vars->patrol_vert[i][0])][(int)(\
		vars->patrol_vert[i][1])] = '0';
}

void	check_patrol(t_vars *vars)
{
	if (vars->map[vars->guy.y][vars->guy.x] == 'M' \
	|| vars->map[vars->guy.y][vars->guy.x] == 'm')
	{
		mlx_destroy_window(vars->mlx, vars->win);
		freemap(vars->map);
		if (vars->nbr_patrol_hori > 0)
			freetab_int(vars->patrol_hori);
		if (vars->nbr_patrol_vert > 0)
			freetab_int(vars->patrol_vert);
		if (CLEAN == 1)
			system("clear");
		ft_putstr_fd("You died -RIP in Peace-\n", 1);
		ft_putstr_fd("\n", 1);
		exit(0);
	}
}
