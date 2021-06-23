/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeco <gbeco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 16:36:44 by gbeco             #+#    #+#             */
/*   Updated: 2021/06/23 14:23:44 by gbeco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	red_cross(t_vars *vars)
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
	return (0);
}

int	frame_gen(t_vars *vars)
{
	char	*step;

	vars->time++;
	if (vars->time == 2147483647)
		vars->time = -1;
	if (vars->time % ANIMATION_SPEED == 0)
		vars->count++;
	if (vars->count == 2147483647)
		vars->count = -1;
	print_img(vars);
	check_collect_and_exit(vars);
	check_patrol(vars);
	if (vars->time % PATROL_SPEED == 0)
		move_patrol(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	step = ft_strjoin("STEP : ", vars->step);
	mlx_string_put(vars->mlx, vars->win, 10, 10, 0x000000, step);
	free(step);
	return (0);
}

int	main(int ac, char **av)
{
	t_vars	vars;

	if (ac > 2)
	{
		ft_putstr_fd("too many arguments\n", 2);
		return (-1);
	}
	if (ac == 1 || ft_strncmp((av[1] + (ft_strlen(av[1]) - 4)), ".ber", 4) != 0)
	{
		ft_putstr_fd("1 argument .ber needed\n", 2);
		return (-1);
	}
	vars.path_map = av[1];
	if (parse_map(&vars))
		return (-1);
	if (init_vars(&vars))
		return (-1);
	mlx_hook(vars.win, 2, 1L << 0, key_hook, &vars);
	mlx_hook(vars.win, 17, 1L << 15, red_cross, &vars);
	mlx_loop_hook(vars.mlx, frame_gen, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
