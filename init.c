/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeco <gbeco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 15:41:05 by gbeco             #+#    #+#             */
/*   Updated: 2021/06/21 17:15:15 by gbeco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_text(t_vars *vars)
{
	if (init_guy(vars))
		return (-1);
	if (init_floor(vars))
		return (-1);
	if (init_wall(vars))
		return (-1);
	if (init_collect(vars))
		return (-1);
	if (init_exit(vars))
		return (-1);
	if (vars->nbr_patrol_hori > 0)
	{
		if (init_patrol_hori(vars))
			return (-1);
	}
	if (vars->nbr_patrol_vert > 0)
	{
		if (init_patrol_vert(vars))
			return (-1);
	}
	return (0);
}

int	init_win_img(t_vars *vars)
{
	vars->mlx = mlx_init();
	if (vars->mlx == NULL)
		return (error(vars, "mlx_init failed\n"));
	vars->win = mlx_new_window(vars->mlx, vars->pixel_x * vars->length_map, \
	vars->pixel_y * vars->height_map, "so_long");
	if (vars->win == NULL)
		return (error(vars, "mlx_new_window failed\n"));
	vars->img.img = mlx_new_image(vars->mlx, vars->pixel_x * vars->length_map, \
	vars->pixel_y * vars->height_map);
	if (vars->img.img == NULL)
		return (error(vars, "mlx_new_image failed\n"));
	vars->img.addr = mlx_get_data_addr(vars->img.img, \
	&vars->img.bits_per_pixel, &vars->img.line_length, &vars->img.endian);
	if (vars->img.addr == NULL)
		return (error(vars, "mlx_get_data_addr failed\n"));
	return (0);
}

int	init_vars(t_vars *vars)
{
	if (CLEAN == 1)
		system("clear");
	vars->time = 0;
	vars->nbr_step = 0;
	vars->step = ft_itoa(vars->nbr_step);
	ft_putstr_fd("Actual Step = ", 1);
	ft_putstr_fd(vars->step, 1);
	ft_putstr_fd("\n", 1);
	if (vars->length_map <= 51)
		vars->pixel_x = 50;
	else
		vars->pixel_x = 50 * 51 / vars->length_map;
	if (vars->height_map <= 27)
		vars->pixel_y = 50;
	else
		vars->pixel_y = 50 * 27 / vars->height_map;
	if (init_win_img(vars))
		return (-1);
	if (init_text(vars))
		return (-1);
	return (0);
}

void	init_vars_map(t_vars *vars)
{
	vars->length_map = 0;
	vars->height_map = 0;
	vars->nbr_collect = 0;
	vars->nbr_patrol_hori = 0;
	vars->nbr_patrol_vert = 0;
	vars->nbr_start = 0;
	vars->map = NULL;
	vars->patrol_hori = NULL;
	vars->patrol_vert = NULL;
	vars->nbr_exit = 0;
}
