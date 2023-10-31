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

void	create_map(t_vars *data, char *temp_map)
{
	char	**mark_map;

	data->map = ft_split(temp_map, '\n');
	if (!data->map)
		exit_no_free();
	linelen_check(data, 0);
	corner_check(data, 0, -1);
	mark_map = ft_split(temp_map, '\n');
	free(temp_map);
	if (!mark_map)
		free_map_exit(data);
	reach_check(data, mark_map, data->player_y, data->player_x);
	free_map(mark_map);
	if (data->door_reach != 1)
	{
		ft_printf("Error\nDoor is not reachable\n");
		free_map_exit(data);
	}
	if (data->coin_reach != data->coin_count)
	{
		ft_printf("Error\nThere is no way to reach all of the coins\n");
		free_map_exit(data);
	}
	display_map(data);
}

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

void	value_check(t_vars *data, int y, int x)
{
	while (data->map[++y])
	{
		x = -1;
		while (data->map[y][++x])
		{
			if (data->map[y][x] == '1' || data->map[y][x] == '0'
			|| data->map[y][x] == 'P' || data->map[y][x] == 'C'
			|| data->map[y][x] == 'E')
			{
				if (data->map[y][x] == 'P')
				{
					data->player_y = y;
					data->player_x = x;
					data->player_count++;
				}
				if (data->map[y][x] == 'C')
					data->coin_count++;
				if (data->map[y][x] == 'E')
					data->exit_count++;
			}
			else
				free_map_exit(data);
		}
	}
	value_check_post(data);
}

void	value_check_post(t_vars *data)
{
	if (data->player_count != 1 || data->exit_count != 1
		|| data->coin_count == 0)
	{
		ft_printf("Error\nThe map values are not correct!\n");
		free_map_exit(data);
	}
}

void	reach_check(t_vars *data, char **map, int y, int x)
{
	if (x == -1 || y == -1
		|| !map[y][x] || map[y][x] == '1' || map[y][x] == '*')
		return ;
	if (map[y][x] == 'E')
		data->door_reach++;
	else if (map[y][x] == 'C')
		data->coin_reach++;
	map[y][x] = '*';
	reach_check(data, map, y + 1, x);
	reach_check(data, map, y - 1, x);
	reach_check(data, map, y, x + 1);
	reach_check(data, map, y, x - 1);
}
