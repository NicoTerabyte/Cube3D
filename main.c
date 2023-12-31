/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 23:04:18 by lnicoter          #+#    #+#             */
/*   Updated: 2023/11/15 00:05:05 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	t_cube	*game;

	game = malloc(1 * sizeof(t_cube));
	struct_init(game);
	read_and_build(game);
	free_struct(game);
	(void)game;
	return (0);
}
