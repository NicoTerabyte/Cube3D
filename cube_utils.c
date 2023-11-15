/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:08:03 by lnicoter          #+#    #+#             */
/*   Updated: 2023/11/15 00:03:52 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	struct_init(t_cube *game)
{
	//non serve per ora
	game->ceiling_color = 0;
	game->floor_color = 0;
}

void	print_mat(char **mat)
{
	int	i;

	i = 0;
	while (mat[i])
	{
		printf("mat value %s\n\n", mat[i]);
		i++;
	}

}

void	free_struct(t_cube *game)
{
	int	i;

	i = -1;
	while (game->all_map[++i])
		free(game->all_map[i]);
	free(game->all_map);
	i = -1;
	if (game->real_map)
	{
		while(game->real_map[++i])
			free(game->real_map[i]);
		free(game->real_map);
	}
	free(game);
	exit(0);
}

void	ft_error(char *str_err, t_cube *game)
{
	printf("%s\n", str_err);
	free_struct(game);
}
