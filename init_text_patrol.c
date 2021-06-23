/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_text_patrol.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeco <gbeco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 15:26:05 by gbeco             #+#    #+#             */
/*   Updated: 2021/06/21 15:31:05 by gbeco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_patrol_hori(t_vars *vars)
{
	vars->text_patrol_hori.path = ft_strdup(PATH_PATROL_HORI);
	if (vars->text_patrol_hori.path == NULL)
		return (error(vars, "path to patrol_hori's texture missing\n"));
	vars->text_patrol_hori.img.img = mlx_xpm_file_to_image(vars->mlx, \
	vars->text_patrol_hori.path, &vars->text_patrol_hori.width, \
	&vars->text_patrol_hori.height);
	if (vars->text_patrol_hori.img.img == NULL)
		return (error(vars, "mlx_xpm_file_to_image failed\n"));
	vars->text_patrol_hori.addr = (int *)mlx_get_data_addr(\
	vars->text_patrol_hori.img.img, \
	&vars->text_patrol_hori.img.bits_per_pixel, \
	&vars->text_patrol_hori.img.line_length, \
	&vars->text_patrol_hori.img.endian);
	if (vars->text_patrol_hori.addr == NULL)
		return (error(vars, "mlx_get_data_addr failed\n"));
	return (0);
}

int	init_patrol_vert(t_vars *vars)
{
	vars->text_patrol_vert.path = ft_strdup(PATH_PATROL_VERT);
	if (vars->text_patrol_vert.path == NULL)
		return (error(vars, "path to patrol_vert's texture missing\n"));
	vars->text_patrol_vert.img.img = mlx_xpm_file_to_image(vars->mlx, \
	vars->text_patrol_vert.path, &vars->text_patrol_vert.width, \
	&vars->text_patrol_vert.height);
	if (vars->text_patrol_vert.img.img == NULL)
		return (error(vars, "mlx_xpm_file_to_image failed\n"));
	vars->text_patrol_vert.addr = (int *)mlx_get_data_addr(\
	vars->text_patrol_vert.img.img, \
	&vars->text_patrol_vert.img.bits_per_pixel, \
	&vars->text_patrol_vert.img.line_length, \
	&vars->text_patrol_vert.img.endian);
	if (vars->text_patrol_vert.addr == NULL)
		return (error(vars, "mlx_get_data_addr failed\n"));
	return (0);
}
