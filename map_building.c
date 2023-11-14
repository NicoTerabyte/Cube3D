/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_building.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:58:28 by lnicoter          #+#    #+#             */
/*   Updated: 2023/11/13 22:25:44 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int		check_cardinals(t_cube *game)
{
	int	i;
	int	check_mark[4];

	i = -1;
	while (++i < 4)
		check_mark[i] = 0;
	i = -1;
	while(game->map[++i])
	{
		if (!ft_strncmp(game->map[i], "NO", 2)
			&& check_mark[0] == 0)
			check_mark[0] = 1;
		else if (!ft_strncmp(game->map[i], "SO", 2)
			&& check_mark[1] == 0)
			check_mark[1] = 1;
		else if (!ft_strncmp(game->map[i], "EA", 2)
			&& check_mark[2] == 0)
			check_mark[2] = 1;
		else if (!ft_strncmp(game->map[i], "WE", 2)
			&& check_mark[3] == 0)
			check_mark[3] = 1;
	}
	if (check_mark[0] && check_mark[1]
		&& check_mark[2] && check_mark[3])
		return (1);
	return (0);
}

/*
qui salverai con mlx_xpm_file_to_image appena
avrai gli sprite però prima finisci i check mappa
void	save_cardinals(t_cube *game)
{
	int	i;

	i = -1;
	while (game->map[++i])
	{
		if(!ft_strncmp(game->map[i], "NO", 2))
			game->north_wall = mlx_xpm_file_to_image()
		if(!ft_strncmp(game->map[i], "SO", 2))
			game->south_wall = mlx_xpm_file_to_image()
		if(!ft_strncmp(game->map[i], "EA", 2))
			game->east_wall = mlx_xpm_file_to_image()
		if(!ft_strncmp(game->map[i], "WE", 2))
			game->west_wall = mlx_xpm_file_to_image()
	}
}
*/

void	read_and_build(t_cube *game)
{
	int		fd;
	char	*line;

	fd = open("./maps/map1.cub", O_RDONLY);
	line = get_next_line(fd);
	game->map = ft_split(line, '\n');
	close(fd);
	free(line);
	if (!check_cardinals(game))
	{
		printf("There are not enough cardinals point\n");
		free_struct(game);
	}
}
