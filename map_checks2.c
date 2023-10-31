/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atasyure <atasyure@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:19:10 by atasyure          #+#    #+#             */
/*   Updated: 2023/10/31 16:32:50 by atasyure         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	linelen_check(t_vars *data, int y)
{
	int	temp;
	int	temp2;

	temp = 0;
	temp2 = 0;
	while (data->map[y] && data->map[y + 1])
	{
		temp = ft_strlen(data->map[y]);
		temp2 = ft_strlen(data->map[y + 1]);
		if (temp != temp2)
		{
			ft_printf("Error\nMap is not rectangular\n");
			free_map_exit(data);
		}
		y++;
	}
}

void	corner_check(t_vars *data, int y, int x)
{
	while (data->map[y][++x])
		if (data->map[y][x] != '1')
			free_map_exit(data);
	x = -1;
	while (data->map[data->map_height_index][++x])
		if (data->map[data->map_height_index][x] != '1')
			free_map_exit(data);
	while (data->map[++y][0] && y < data->map_height_index)
		if (data->map[y][0] != '1')
			free_map_exit(data);
	y = 0;
	while (data->map[++y][data->map_width_index] && y < data->map_height_index)
		if (data->map[y][data->map_width_index] != '1')
			free_map_exit(data);
	value_check_pre(data);
}

void	value_check_pre(t_vars *data)
{
	data->player_count = 0;
	data->coin_count = 0;
	data->exit_count = 0;
	data->door_reach = 0;
	data->coin_reach = 0;
	value_check(data, -1, -1);
}
