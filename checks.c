/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atasyure <atasyure@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:34:15 by atasyure          #+#    #+#             */
/*   Updated: 2023/10/31 15:36:19 by atasyure         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>

void	name_check(char *name)
{
	int	len;

	len = ft_strlen(name);
	if (len == 4 || (name[len - 1] != 'r' && name[len - 2] != 'e'
			&& name[len - 3] != 'b' && name[len - 4] != '.'))
	{
		ft_printf("Error\nWrong format!\n");
		exit_no_free();
	}
	else
		name_check2(name);
}

void	name_check2(char *name)
{
	int	fd;

	fd = open(name, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\nThere is no map in this name!\n");
		exit_no_free();
	}
	check_line(fd);
}

void	check_line(int fd)
{
	char	*line;
	char	*temp_map;
	char	*temp_map2;
	t_vars	data;

	line = get_next_line(fd);
	if (!line)
		return (ft_printf("Error\nMap is empty!\n"), close(fd), exit(1));
	data.map_width_index = ft_strlen(line) - 2;
	data.map_height_index = 0;
	temp_map = ft_strdup("");
	while (line)
	{
		data.map_height_index++;
		temp_map2 = ft_strjoin(temp_map, line);
		free(line);
		free(temp_map);
		temp_map = temp_map2;
		line = get_next_line(fd);
	}
	close(fd);
	data.map_height_index -= 1;
	create_map(&data, temp_map);
}
