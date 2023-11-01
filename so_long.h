/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atasyure <atasyure@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:52:39 by atasyure          #+#    #+#             */
/*   Updated: 2023/11/01 14:49:28 by atasyure         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "minilibx/mlx.h"

# define W	13
# define A	0
# define S	1
# define D	2
# define ESC	53
# define PIXEL	64

typedef struct s_vars
{
	char	**map;
	int		map_width_index;
	int		map_height_index;
	int		player_count;
	int		coin_count;
	int		exit_count;
	int		step_count;
	int		player_y;
	int		player_x;
	int		door_reach;
	int		coin_reach;
	int		w;
	int		h;
	void	*win_ptr;
	void	*mlx_ptr;
	void	*character;
	void	*wall;
	void	*background;
	void	*coin;
	void	*door;
}	t_vars;

void	exit_no_free(void);
void	name_check(char *name);
void	name_check2(char *name);
void	exit_free_name(char *name);
void	check_line(int fd);
void	create_map(t_vars *data, char *temp_map);
void	free_map_exit(t_vars *data);
void	corner_check(t_vars *data, int x, int y);
void	linelen_check(t_vars *data, int y);
void	value_check_pre(t_vars *data);
void	value_check(t_vars *data, int y, int x);
void	value_check_post(t_vars *data);
void	reach_check(t_vars *data, char **map, int y, int x);
void	display_map(t_vars *data);
void	game_exit(t_vars *data);
void	free_map(char **map);
void	display_win(t_vars *data, int x, int y);
void	player_movement(t_vars *data, int x, int y);
int		movement(int key, t_vars *data);
int		exit_window(t_vars *data);
void	mlx_initialize(t_vars *data);

#endif
