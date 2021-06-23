/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeco <gbeco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 12:23:11 by gbeco             #+#    #+#             */
/*   Updated: 2021/06/23 14:18:42 by gbeco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		freemap(vars->map);
		if (vars->nbr_patrol_hori > 0)
			freetab_int(vars->patrol_hori);
		if (vars->nbr_patrol_vert > 0)
			freetab_int(vars->patrol_vert);
		if (CLEAN == 1)
			system("clear");
		ft_putstr_fd("step at exit : ", 1);
		ft_putstr_fd(vars->step, 1);
		ft_putstr_fd("\n", 1);
		free(vars->step);
		exit(0);
	}
	if (keycode == 13)
		move_up(vars);
	if (keycode == 1)
		move_down(vars);
	if (keycode == 0)
		move_left(vars);
	if (keycode == 2)
		move_right(vars);
	return (0);
}

void	move_up(t_vars *vars)
{
	if (vars->map[vars->guy.y - 1][vars->guy.x] != '1')
	{
		vars->guy.y--;
		vars->nbr_step++;
		free(vars->step);
		vars->step = ft_itoa(vars->nbr_step);
		if (CLEAN == 1)
			system("clear");
		ft_putstr_fd("Actual Step = ", 1);
		ft_putstr_fd(vars->step, 1);
		ft_putstr_fd("\n", 1);
	}
}

void	move_down(t_vars *vars)
{
	if (vars->map[vars->guy.y + 1][vars->guy.x] != '1')
	{
		vars->guy.y++;
		vars->nbr_step++;
		free(vars->step);
		vars->step = ft_itoa(vars->nbr_step);
		if (CLEAN == 1)
			system("clear");
		ft_putstr_fd("Actual Step = ", 1);
		ft_putstr_fd(vars->step, 1);
		ft_putstr_fd("\n", 1);
	}
}

void	move_left(t_vars *vars)
{
	if (vars->map[vars->guy.y][vars->guy.x - 1] != '1')
	{
		vars->guy.x--;
		vars->nbr_step++;
		free(vars->step);
		vars->step = ft_itoa(vars->nbr_step);
		if (CLEAN == 1)
			system("clear");
		ft_putstr_fd("Actual Step = ", 1);
		ft_putstr_fd(vars->step, 1);
		ft_putstr_fd("\n", 1);
	}
}

void	move_right(t_vars *vars)
{
	if (vars->map[vars->guy.y][vars->guy.x + 1] != '1')
	{
		vars->guy.x++;
		vars->nbr_step++;
		free(vars->step);
		vars->step = ft_itoa(vars->nbr_step);
		if (CLEAN == 1)
			system("clear");
		ft_putstr_fd("Actual Step = ", 1);
		ft_putstr_fd(vars->step, 1);
		ft_putstr_fd("\n", 1);
	}
}
