/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_building.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:58:28 by lnicoter          #+#    #+#             */
/*   Updated: 2023/11/17 09:55:52 by lnicoter         ###   ########.fr       */
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
	while(game->all_map[++i])
	{
		if (!ft_strncmp(game->all_map[i], "NO", 2)
			&& check_mark[0] == 0)
			check_mark[0] = 1;
		else if (!ft_strncmp(game->all_map[i], "SO", 2)
			&& check_mark[1] == 0)
			check_mark[1] = 1;
		else if (!ft_strncmp(game->all_map[i], "EA", 2)
			&& check_mark[2] == 0)
			check_mark[2] = 1;
		else if (!ft_strncmp(game->all_map[i], "WE", 2)
			&& check_mark[3] == 0)
			check_mark[3] = 1;
	}
	if (check_mark[0] && check_mark[1]
		&& check_mark[2] && check_mark[3])
		return (1);
	return (0);
}

void	take_colors(t_cube *game)
{
	int	i;
	int	floor_flag;
	int	ceiling_flag;

	floor_flag = 0;
	ceiling_flag = 0;
	i = -1;
	while (game->all_map[++i])
		set_colors(game, i, floor_flag, ceiling_flag);
	color_convertion_int(game);
}
/*
qui salverai con mlx_xpm_file_to_image appena
avrai gli sprite però prima finisci i check mappa
void	save_cardinals(t_cube *game)
{
	int	i;

	i = -1;
	while (game->all_map[++i])
	{
		if(!ft_strncmp(game->all_map[i], "NO", 2))
			game->card->north_wall = mlx_xpm_file_to_image()
		if(!ft_strncmp(game->all_map[i], "SO", 2))
			game->south_wall = mlx_xpm_file_to_image()
		if(!ft_strncmp(game->all_map[i], "EA", 2))
			game->east_wall = mlx_xpm_file_to_image()
		if(!ft_strncmp(game->all_map[i], "WE", 2))
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
	game->all_map = ft_split(line, '\n');
	close(fd);
	free(line);
	if (!check_cardinals(game))
	{
		printf("There are not enough cardinals point\n");
		free_struct(game);
	}
	take_real_map(game);
	take_colors(game);
}
