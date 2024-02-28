/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaabi <ichaabi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 20:49:55 by ichaabi           #+#    #+#             */
/*   Updated: 2024/02/28 19:08:08 by ichaabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main (int ac, char **av)
{
	char	**two_d;
	t_mlx	mlx_pointers;

	two_d = parse_maps(ac, av);
	mlx_pointers.mlx_p = mlx_init();
	if (mlx_pointers.mlx_p == NULL)
		errors("Error init connexion with graphical server\n", 2);
	mlx_pointers.win_p = mlx_new_window(mlx_pointers.mlx_p, 1000, 1000, "ROBIOOOOO");
	if (mlx_pointers.win_p == NULL)
		errors("Error for window\n", 2);
	mlx_loop(mlx_pointers.mlx_p);

	mlx_pointers.img_p = mlx_xpm_file_to_image(mlx_pointers.mlx_p, "", &mlx_pointers.width, &mlx);
	return (0);
}
