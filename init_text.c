/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_text.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeco <gbeco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 11:08:35 by gbeco             #+#    #+#             */
/*   Updated: 2021/06/21 15:26:28 by gbeco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_guy(t_vars *vars)
{
	vars->guy.text.path = ft_strdup(PATH_GUY);
	if (vars->guy.text.path == NULL)
		return (error(vars, "path to player's texture missing\n"));
	vars->guy.text.img.img = mlx_xpm_file_to_image(vars->mlx, \
	vars->guy.text.path, &vars->guy.text.width, &vars->guy.text.height);
	if (vars->guy.text.img.img == NULL)
		return (error(vars, "mlx_xpm_file_to_image failed\n"));
	vars->guy.text.addr = (int *)mlx_get_data_addr(vars->guy.text.img.img, \
	&vars->guy.text.img.bits_per_pixel, &vars->guy.text.img.line_length, \
	&vars->guy.text.img.endian);
	if (vars->guy.text.addr == NULL)
		return (error(vars, "mlx_get_data_addr failed\n"));
	return (0);
}

int	init_floor(t_vars *vars)
{
	vars->floor.path = ft_strdup(PATH_FLOOR);
	if (vars->floor.path == NULL)
		return (error(vars, "path to floor's texture missing\n"));
	vars->floor.img.img = mlx_xpm_file_to_image(vars->mlx, vars->floor.path, \
	&vars->floor.width, &vars->floor.height);
	if (vars->floor.img.img == NULL)
		return (error(vars, "mlx_xpm_file_to_image failed\n"));
	vars->floor.addr = (int *)mlx_get_data_addr(vars->floor.img.img, \
	&vars->floor.img.bits_per_pixel, &vars->floor.img.line_length, \
	&vars->floor.img.endian);
	if (vars->floor.addr == NULL)
		return (error(vars, "mlx_get_data_addr failed\n"));
	return (0);
}

int	init_wall(t_vars *vars)
{
	vars->wall.path = ft_strdup(PATH_WALL);
	if (vars->wall.path == NULL)
		return (error(vars, "path to wall's texture missing\n"));
	vars->wall.img.img = mlx_xpm_file_to_image(vars->mlx, vars->wall.path, \
	&vars->wall.width, &vars->wall.height);
	if (vars->wall.img.img == NULL)
		return (error(vars, "mlx_xpm_file_to_image failed\n"));
	vars->wall.addr = (int *)mlx_get_data_addr(vars->wall.img.img, \
	&vars->wall.img.bits_per_pixel, &vars->wall.img.line_length, \
	&vars->wall.img.endian);
	if (vars->wall.addr == NULL)
		return (error(vars, "mlx_get_data_addr failed\n"));
	return (0);
}

int	init_collect(t_vars *vars)
{
	vars->collect.path = ft_strdup(PATH_COLLECT);
	if (vars->collect.path == NULL)
		return (error(vars, "path to collectibles' texture missing\n"));
	vars->collect.img.img = mlx_xpm_file_to_image(vars->mlx, \
	vars->collect.path, &vars->collect.width, &vars->collect.height);
	if (vars->collect.img.img == NULL)
		return (error(vars, "mlx_xpm_file_to_image failed\n"));
	vars->collect.addr = (int *)mlx_get_data_addr(vars->collect.img.img, \
	&vars->collect.img.bits_per_pixel, &vars->collect.img.line_length, \
	&vars->collect.img.endian);
	if (vars->collect.addr == NULL)
		return (error(vars, "mlx_get_data_addr failed\n"));
	return (0);
}

int	init_exit(t_vars *vars)
{
	vars->exit.path = ft_strdup(PATH_EXIT);
	if (vars->exit.path == NULL)
		return (error(vars, "path to exit's texture missing\n"));
	vars->exit.img.img = mlx_xpm_file_to_image(vars->mlx, vars->exit.path, \
	&vars->exit.width, &vars->exit.height);
	if (vars->exit.img.img == NULL)
		return (error(vars, "mlx_xpm_file_to_image failed\n"));
	vars->exit.addr = (int *)mlx_get_data_addr(vars->exit.img.img, \
	&vars->exit.img.bits_per_pixel, &vars->exit.img.line_length, \
	&vars->exit.img.endian);
	if (vars->exit.addr == NULL)
		return (error(vars, "mlx_get_data_addr failed\n"));
	return (0);
}
