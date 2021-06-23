/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_patrol.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeco <gbeco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 17:52:02 by gbeco             #+#    #+#             */
/*   Updated: 2021/06/21 17:54:24 by gbeco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_patrol_hori(t_vars *vars, int y, int x)
{
	int	i;
	int	j;
	int	k;

	x = x * vars->pixel_x;
	y = y * vars->pixel_y;
	i = -1;
	while (++i < vars->pixel_x)
	{
		j = -1;
		while (++j < vars->pixel_y)
		{
			k = (j * vars->text_patrol_hori.height / vars->pixel_y) * \
			vars->text_patrol_hori.width + ((vars->text_patrol_hori.width / 4) \
			* (vars->count % 3) + i * (vars->text_patrol_hori.width / 4) / \
			vars->pixel_y);
			if (vars->text_patrol_hori.addr[k] >= 0)
				my_mlx_pixel_put(vars, x + i, y + j, \
				vars->text_patrol_hori.addr[k]);
		}
	}
}

void	print_patrol_vert(t_vars *vars, int y, int x)
{
	int	i;
	int	j;
	int	k;

	x = x * vars->pixel_x;
	y = y * vars->pixel_y;
	i = -1;
	while (++i < vars->pixel_x)
	{
		j = -1;
		while (++j < vars->pixel_y)
		{
			k = (j * vars->text_patrol_vert.height / vars->pixel_y) * \
			vars->text_patrol_vert.width + ((vars->text_patrol_vert.width / 4) \
			* (vars->count % 3) + i * (vars->text_patrol_vert.width / 4) / \
			vars->pixel_y);
			if (vars->text_patrol_vert.addr[k] >= 0)
				my_mlx_pixel_put(vars, x + i, y + j, \
				vars->text_patrol_vert.addr[k]);
		}
	}
}
