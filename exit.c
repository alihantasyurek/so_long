/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atasyure <atasyure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:13:20 by atasyure          #+#    #+#             */
/*   Updated: 2023/10/31 17:13:07 by atasyure         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_no_free(void)
{
	exit(1);
}

void	free_map_exit(t_vars *data)
{
	int	i;

	i = 0;
	while (data->map[i])
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
	exit(1);
}

void	game_exit(t_vars *data)
{
	if (data->background)
		mlx_destroy_image(data->mlx_ptr, data->background);
	if (data->coin)
		mlx_destroy_image(data->mlx_ptr, data->coin);
	if (data->door)
		mlx_destroy_image(data->mlx_ptr, data->door);
	if (data->character)
		mlx_destroy_image(data->mlx_ptr, data->character);
	if (data->wall)
		mlx_destroy_image(data->mlx_ptr, data->wall);
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	free_map_exit(data);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free (map[i]);
		i++;
	}
	free(map);
}
