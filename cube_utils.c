/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:08:03 by lnicoter          #+#    #+#             */
/*   Updated: 2023/11/13 22:25:36 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	struct_init(t_cube *game)
{
	//non serve per ora
	return ;
}

void	print_mat(t_cube *game)
{
	int	i;

	i = 0;
	printf("la verità %p\n", game);
	while (game->map[i])
	{
		printf("mat value %s\n\n", game->map[i]);
		i++;
	}

}

void	free_struct(t_cube *game)
{
	int	i;

	i = -1;
	while (game->map[++i])
		free(game->map[i]);
	free(game->map);
	free(game);
	exit(0);
}
