/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atasyure <atasyure@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:36:39 by atasyure          #+#    #+#             */
/*   Updated: 2023/10/31 16:59:37 by atasyure         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_map(t_vars *data)
{
	mlx_initialize(data);
	data->character = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/character_front.xpm", &data->w, &data->h);
	data->background = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/background.xpm", &data->w, &data->h);
	data->coin = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/coin.xpm", &data->w, &data->h);
	data->door = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/door.xpm", &data->w, &data->h);
	data->wall = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/wall.xpm", &data->w, &data->h);
	if (!data->character || !data->background || !data->coin
		|| !data->door || !data->wall)
		return (ft_printf("Error\nTextures couldn't load\n"), game_exit(data));
	display_win(data, -1, -1);
	mlx_hook(data->win_ptr, 2, 0, movement, data);
	mlx_hook(data->win_ptr, 17, 0, exit_window, data);
	mlx_loop(data->mlx_ptr);
}

void	display_win(t_vars *data, int x, int y)
{
	ft_printf("Current number of movements: %d\n", data->step_count);
	while (data->map[++y])
	{
		x = -1;
		while (data->map[y][++x])
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->background, x * data->w, y * data->h);
			if (data->map[y][x] == '1')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->wall, x * data->w, y * data->h);
			if (data->map[y][x] == '0')
				mlx_put_image_to_window(data->mlx_ptr,
					data->win_ptr, data->background, x * data->w, y * data->h);
			if (data->map[y][x] == 'E')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->door, x * data->w, y * data->h);
			if (data->map[y][x] == 'C')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->coin, x * data->w, y * data->h);
		}
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->character,
		data->player_x * data->w, data->player_y * data->h);
}

int	movement(int key, t_vars *data)
{
	if (key == ESC)
		return (ft_printf("Error\nEscape is pressed\n"), game_exit(data), 1);
	else if (key == W)
	{
		display_character(data, 'w');
		player_movement(data, 0, -1);
	}
	else if (key == S)
	{
		display_character(data, 's');
		player_movement(data, 0, 1);
	}
	else if (key == A)
	{
		display_character(data, 'a');
		player_movement(data, -1, 0);
	}
	else if (key == D)
	{
		display_character(data, 'd');
		player_movement(data, 1, 0);
	}
	check_door(data);
	return (0);
}

void	display_character(t_vars *data, char c)
{
	if (c == 'w')
		data->character = mlx_xpm_file_to_image(data->mlx_ptr,
				"textures/character_background.xpm", &data->w, &data->h);
	if (c == 's')
		data->character = mlx_xpm_file_to_image(data->mlx_ptr,
				"textures/character_front.xpm", &data->w, &data->h);
	if (c == 'a')
		data->character = mlx_xpm_file_to_image(data->mlx_ptr,
				"textures/character_left.xpm", &data->w, &data->h);
	if (c == 'd')
		data->character = mlx_xpm_file_to_image(data->mlx_ptr,
				"textures/character_right.xpm", &data->w, &data->h);
	if (!data->character)
	{
		ft_printf("Error\nCharacter textures couldn't load");
		game_exit(data);
	}
}

void	player_movement(t_vars *data, int x, int y)
{
	if (data->map[data->player_y + y][data->player_x + x] == '1')
		return ;
	if (data->map[data->player_y + y][data->player_x + x] == 'E'
			&& data->coin_count == 0)
	{
		ft_printf("Total steps: %d\nCongratulations!!\n", data->step_count + 1);
		game_exit(data);
	}
	if (data->map[data->player_y + y][data->player_x + x] == 'C')
		data->coin_count--;
	data->step_count++;
	if (data->map[data->player_y][data->player_x] != 'E')
		data->map[data->player_y][data->player_x] = '0';
	data->player_y += y;
	data->player_x += x;
	display_win(data, -1, -1);
}
