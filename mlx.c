/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaabi <ichaabi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 21:42:26 by ichaabi           #+#    #+#             */
/*   Updated: 2024/03/01 20:02:22 by ichaabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	the_mlx()
// {
// 	t_mlx	mlx_pointers;

// 	mlx_pointers.mlx_p = mlx_init();
// 	if (mlx_pointers.mlx_p == NULL)
// 		errors("Error init connexion with graphical server\n", 2);
// 	mlx_pointers.win_p = mlx_new_window(mlx_pointers.mlx_p, 1920, 1080, "ROBIOOOOO");
// 	if (mlx_pointers.win_p == NULL)
// 		errors("Error for window\n", 2);
// 	mlx_pointers.img_p = mlx_xpm_file_to_image(mlx_pointers.mlx_p, "galaxy.xpm",&mlx_pointers.height, &mlx_pointers.width);
// 	mlx_put_image_to_window(mlx_pointers.mlx_p, mlx_pointers.win_p, mlx_pointers.img_p, 0, 0);

// 	mlx_pointers.img_p = mlx_xpm_file_to_image(mlx_pointers.mlx_p, "collectibles.xpm",&mlx_pointers.height, &mlx_pointers.width);
// 	mlx_put_image_to_window(mlx_pointers.mlx_p, mlx_pointers.win_p, mlx_pointers.img_p, 0, 0);

// 	mlx_pointers.img_p = mlx_xpm_file_to_image(mlx_pointers.mlx_p, "walll.xpm",&mlx_pointers.height, &mlx_pointers.width);
// 	mlx_put_image_to_window(mlx_pointers.mlx_p, mlx_pointers.win_p, mlx_pointers.img_p, 64, 64);//x ou y kitzado b 64
// 	mlx_pointers.img_p = mlx_xpm_file_to_image(mlx_pointers.mlx_p, "walll.xpm",&mlx_pointers.height, &mlx_pointers.width);
// 	mlx_put_image_to_window(mlx_pointers.mlx_p, mlx_pointers.win_p, mlx_pointers.img_p, 64, 128);

// 	mlx_pointers.img_p = mlx_xpm_file_to_image(mlx_pointers.mlx_p, "p1.xpm",&mlx_pointers.height, &mlx_pointers.width);
// 	mlx_put_image_to_window(mlx_pointers.mlx_p, mlx_pointers.win_p, mlx_pointers.img_p, 128, 128);

// 	mlx_pointers.img_p = mlx_xpm_file_to_image(mlx_pointers.mlx_p, "exitt.xpm",&mlx_pointers.height, &mlx_pointers.width);
// 	mlx_put_image_to_window(mlx_pointers.mlx_p, mlx_pointers.win_p, mlx_pointers.img_p, 256, 256);
// 	if (mlx_pointers.img_p  == NULL)
// 		errors("Error put image\n", 2);
// 	if (mlx_pointers.img_p == NULL)
// 		errors("Error loading XPM image\n", 2);
// 	mlx_loop(mlx_pointers.mlx_p);
// }
