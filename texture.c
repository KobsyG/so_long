/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeco <gbeco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 16:01:57 by gbeco             #+#    #+#             */
/*   Updated: 2021/06/21 17:52:14 by gbeco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_guy(t_vars *vars)
{
	int	i;
	int	j;
	int	x;
	int	y;
	int	k;

	x = vars->guy.x * vars->pixel_x;
	y = vars->guy.y * vars->pixel_y;
	i = -1;
	while (++i < vars->pixel_x)
	{
		j = -1;
		while (++j < vars->pixel_y)
		{
			k = (j * vars->guy.text.height / vars->pixel_y) * \
			vars->guy.text.width + (i * vars->guy.text.width / vars->pixel_x);
			if (vars->guy.text.addr[k] >= 0)
				my_mlx_pixel_put(vars, x + i, y + j, vars->guy.text.addr[k]);
		}
	}
}

void	print_floor(t_vars *vars, int y, int x)
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
			k = (j * vars->floor.height / vars->pixel_y) * \
			vars->floor.width + (i * vars->floor.width / vars->pixel_x);
			if (vars->floor.addr[k] != 0)
				my_mlx_pixel_put(vars, x + i, y + j, vars->floor.addr[k]);
		}
	}
}

void	print_wall(t_vars *vars, int y, int x)
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
			k = (j * vars->wall.height / vars->pixel_y) * \
			vars->wall.width + (i * vars->wall.width / vars->pixel_x);
			if (vars->wall.addr[k] >= 0)
				my_mlx_pixel_put(vars, x + i, y + j, vars->wall.addr[k]);
		}
	}
}

void	print_collect(t_vars *vars, int y, int x)
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
			k = (j * vars->collect.height / vars->pixel_y) * \
			vars->collect.width + (i * vars->collect.width / vars->pixel_y);
			if (vars->collect.addr[k] >= 0)
				my_mlx_pixel_put(vars, x + i, y + j, vars->collect.addr[k]);
		}
	}
}

void	print_exit(t_vars *vars, int y, int x)
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
			k = (j * vars->exit.height / vars->pixel_y) * \
			vars->exit.width + ((vars->exit.width / 4) * \
			(vars->count % 3) + i * (vars->exit.width / 4) / vars->pixel_x);
			if (vars->exit.addr[k] >= 0)
				my_mlx_pixel_put(vars, x + i, y + j, vars->exit.addr[k]);
		}
	}
}
