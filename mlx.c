/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaabi <ichaabi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 21:42:26 by ichaabi           #+#    #+#             */
/*   Updated: 2024/02/28 21:59:30 by ichaabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	*my_mlx(t_mlx	mlx)
// {
// 	mlx.mlx_p = mlx_init();
// 	if (mlx.mlx_p == NULL)
// 		errors("Error init connexion with graphical server\n", 2);
// 	mlx.win_p = mlx_new_window(mlx.mlx_p, 1920, 1080, "ROBIOOOOO");
// 	if (mlx.win_p == NULL)
// 		errors("Error for window\n", 2);
// 	mlx.img_p = mlx_new_image(mlx.mlx_p, 1920, 1080);
// 	//apres avoir cree une image on appelle mlx_get_data_addr
// 	//on passe bits_par_pixel, longueur de ligne..
// 	mlx.addr = mlx_get_data_addr(mlx.img_p, &mlx.bpp, &mlx.length, &mlx.endian);
// 	mlx_pixel_put(mlx.mlx_p, mlx.win_p, 5, 5, 0x00FF0000);//representation hexadecimale de ARGB(0,255,0,0)
// 	mlx_put_image_to_window(mlx.mlx_p, mlx.win_p, mlx.img_p, 0, 0);
// 	mlx_loop(mlx.mlx_p);
// }
