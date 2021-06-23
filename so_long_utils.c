/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeco <gbeco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 13:28:01 by gbeco             #+#    #+#             */
/*   Updated: 2021/06/23 10:57:33 by gbeco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color)
{
	char	*dst;

	dst = vars->img.addr + \
	(y * vars->img.line_length + x * (vars->img.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	print_big_pixel(t_vars *vars, int y, int x, int color)
{
	int	i;
	int	j;

	x = x * (RES_X / vars->length_map);
	y = y * (RES_Y / vars->height_map);
	i = -1;
	while (++i < RES_X / vars->length_map)
	{
		j = -1;
		while (++j < RES_Y / vars->height_map)
			my_mlx_pixel_put(vars, x + i, y + j, color);
	}
}

void	print_img(t_vars *vars)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (vars->map[++i] && vars->map[i][j] != 0)
	{
		while (vars->map[i][j] != 0)
		{
			print_floor(vars, i, j);
			if (vars->map[i][j] == '1')
				print_wall(vars, i, j);
			print_guy(vars);
			if (vars->map[i][j] == 'C')
				print_collect(vars, i, j);
			if (vars->map[i][j] == 'E')
				print_exit(vars, i, j);
			if (vars->map[i][j] == 'M')
				print_patrol_hori(vars, i, j);
			if (vars->map[i][j] == 'm')
				print_patrol_vert(vars, i, j);
			j++;
		}
		j = 0;
	}
}

void	check_collect_and_exit(t_vars *vars)
{
	if (vars->map[vars->guy.y][vars->guy.x] == 'C')
	{
		vars->map[vars->guy.y][vars->guy.x] = '0';
		vars->nbr_collect--;
	}
	if (vars->map[vars->guy.y][vars->guy.x] == 'E' && vars->nbr_collect == 0)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		freemap(vars->map);
		if (vars->nbr_patrol_hori > 0)
			freetab_int(vars->patrol_hori);
		if (vars->nbr_patrol_vert > 0)
			freetab_int(vars->patrol_vert);
		if (CLEAN == 1)
			system("clear");
		ft_putstr_fd("Step total : ", 1);
		ft_putstr_fd(vars->step, 1);
		ft_putstr_fd("\n", 1);
		exit(0);
	}
}

void	get_guy_pos(t_vars *vars, int x, int y)
{
	vars->guy.x = x;
	vars->guy.y = y;
	vars->map[y][x] = '0';
	vars->nbr_start++;
}
