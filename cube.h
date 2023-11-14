/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 22:55:48 by lnicoter          #+#    #+#             */
/*   Updated: 2023/11/13 22:22:04 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include "./mlx_linux/mlx.h"
# include "./libft/libft.h" //fare modifiche per l'atoi???
# include <math.h>
# include <error.h>

typedef struct s_cube
{
	void	*mlx;
	char	**map;
	void	*north_wall;
	void	*south_wall;
	void	*east_wall;
	void	*west_wall;
}	t_cube;

void	struct_init(t_cube *game);
void	read_and_build(t_cube *game);
void	print_mat(t_cube *game);
void	free_struct(t_cube *game);
int		check_cardinals(t_cube *game);

#endif
