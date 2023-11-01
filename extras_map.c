/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atasyure <atasyure@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:19:10 by atasyure          #+#    #+#             */
/*   Updated: 2023/11/01 14:49:52 by atasyure         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mlx_initialize(t_vars *data)
{
	data->w = 0;
	data->h = 0;
	data->step_count = 0;
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		free_map_exit(data);
	data->win_ptr = mlx_new_window(data->mlx_ptr, (data->map_width_index + 1)
			* PIXEL, (data->map_height_index + 1) * PIXEL, "The Game");
	if (!data->win_ptr)
	{
		free(data->mlx_ptr);
		free_map_exit(data);
	}
}

int	exit_window(t_vars *data)
{
	ft_printf("Error\nWindow is closed\n");
	game_exit(data);
	return (1);
}
