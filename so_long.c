/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaabi <ichaabi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 20:49:55 by ichaabi           #+#    #+#             */
/*   Updated: 2024/02/29 04:15:03 by ichaabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main (int ac, char **av)
{
	char	**two_d;
	t_mlx	mlx_pointers;

	two_d = parse_maps(ac, av);
	mlx_pointers.mlx_p = mlx_init();
	// if (mlx_pointers.mlx_p == NULL)
	// 	errors("Error init connexion with graphical server\n", 2);
	mlx_pointers.win_p = mlx_new_window(mlx_pointers.mlx_p, 1920, 1080, "ROBIOOOOO");
	// if (mlx_pointers.win_p == NULL)
	// 	errors("Error for window\n", 2);
	// mlx_pointers.img_p = mlx_new_image(mlx_pointers.mlx_p, 1920, 1080);
	mlx_pointers.img_p = mlx_xpm_file_to_image(mlx_pointers.mlx_p, "galaxy.xpm",&mlx_pointers.height, &mlx_pointers.width);
		if (mlx_pointers.img_p  == NULL)
			errors("Error put image\n", 2);
	mlx_put_image_to_window(mlx_pointers.mlx_p, mlx_pointers.win_p, mlx_pointers.img_p, 0, 0);
	mlx_pointers.img_p = mlx_xpm_file_to_image(mlx_pointers.mlx_p, "ice.xpm",&mlx_pointers.height, &mlx_pointers.width);
	mlx_put_image_to_window(mlx_pointers.mlx_p, mlx_pointers.win_p, mlx_pointers.img_p, 0, 0);
	mlx_pointers.img_p = mlx_xpm_file_to_image(mlx_pointers.mlx_p, "last.xpm",&mlx_pointers.height, &mlx_pointers.width);
	mlx_put_image_to_window(mlx_pointers.mlx_p, mlx_pointers.win_p, mlx_pointers.img_p, 64, 64);//x ou y kitzado b 64
	mlx_pointers.img_p = mlx_xpm_file_to_image(mlx_pointers.mlx_p, "player.xpm",&mlx_pointers.height, &mlx_pointers.width);
	mlx_put_image_to_window(mlx_pointers.mlx_p, mlx_pointers.win_p, mlx_pointers.img_p, 128, 128);

	if (mlx_pointers.img_p == NULL)
		errors("Error loading XPM image\n", 2);
	mlx_loop(mlx_pointers.mlx_p);


	return (0);
}

