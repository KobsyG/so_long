/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patrol.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeco <gbeco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 11:40:42 by gbeco             #+#    #+#             */
/*   Updated: 2021/06/23 14:55:38 by gbeco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	set_patrol_hori(t_vars *vars, int x, int y)
{
	int		**new;
	int		i;

	vars->nbr_patrol_hori++;
	if (ft_talloc_int(&new, sizeof(int *) * (vars->nbr_patrol_hori + 1)))
		return (error(vars, "allocation error\n"));
	new[vars->nbr_patrol_hori] = NULL;
	i = -1;
	while (++i < vars->nbr_patrol_hori - 1)
	{
		if (ft_salloc_int(&new[i], sizeof(int) * 3))
			return (error(vars, "allocation error\n"));
		new[i][0] = vars->patrol_hori[i][0];
		new[i][1] = vars->patrol_hori[i][1];
		new[i][2] = vars->patrol_hori[i][2];
	}
	if (ft_salloc_int(&new[i], sizeof(int) * 3))
			return (error(vars, "allocation error\n"));
	new[i][0] = x;
	new[i][1] = y;
	new[i][2] = 1;
	if (vars->nbr_patrol_hori > 1)
		freetab_int(vars->patrol_hori);
	vars->patrol_hori = new;
	return (0);
}

int	set_patrol_vert(t_vars *vars, int x, int y)
{
	int		**new;
	int		i;

	vars->nbr_patrol_vert++;
	new = malloc(sizeof(int *) * (vars->nbr_patrol_vert + 1));
	new[vars->nbr_patrol_vert] = NULL;
	i = -1;
	while (++i < vars->nbr_patrol_vert - 1)
	{
		new[i] = malloc(sizeof(int) * 3);
		new[i][0] = vars->patrol_vert[i][0];
		new[i][1] = vars->patrol_vert[i][1];
		new[i][2] = vars->patrol_vert[i][2];
	}
	new[i] = malloc(sizeof(int) * 2);
	new[i][0] = x;
	new[i][1] = y;
	new[i][2] = 1;
	if (vars->nbr_patrol_vert > 1)
		freetab_int(vars->patrol_vert);
	vars->patrol_vert = new;
	return (0);
}

void	move_patrol(t_vars *vars)
{
	int	i;

	i = -1;
	if (vars->nbr_patrol_hori > 0)
	{
		while (vars->patrol_hori[++i] != 0)
			move_patrol_hori(vars, i);
	}
	i = -1;
	if (vars->nbr_patrol_vert > 0)
	{
		while (vars->patrol_vert[++i] != 0)
			move_patrol_vert(vars, i);
	}
}

void	move_patrol_hori(t_vars *vars, int i)
{
	if (check_change_side_hori(vars, i) == 1)
		vars->patrol_hori[i][2] *= -1;
	if (check_change_side_hori(vars, i) == 1)
		return ;
	check_collision_patrol_hori(vars, i);
	vars->patrol_hori[i][1] += vars->patrol_hori[i][2];
	if (vars->patrol_hori[i][1] == vars->length_map - 1 \
	|| vars->patrol_hori[i][1] == 0)
	{
		vars->map[(int)(vars->patrol_hori[i][0])][(int)(\
		vars->patrol_hori[i][1])] = '1';
		vars->patrol_hori[i][2] = 0;
	}
	else
		vars->map[(int)(vars->patrol_hori[i][0])][(int)(\
		vars->patrol_hori[i][1])] = 'M';
}

void	move_patrol_vert(t_vars *vars, int i)
{
	if (check_change_side_vert(vars, i) == 1)
		vars->patrol_vert[i][2] *= -1;
	if (check_change_side_vert(vars, i) == 1)
		return ;
	check_collision_patrol_vert(vars, i);
	vars->patrol_vert[i][0] += vars->patrol_vert[i][2];
	if (vars->patrol_vert[i][0] == vars->height_map - 1 \
	|| vars->patrol_vert[i][0] == 0)
	{
		vars->map[(int)(vars->patrol_vert[i][0])][(int)(\
		vars->patrol_vert[i][1])] = '1';
		vars->patrol_vert[i][2] = 0;
	}
	else
		vars->map[(int)(vars->patrol_vert[i][0])][(int)(\
		vars->patrol_vert[i][1])] = 'm';
}
