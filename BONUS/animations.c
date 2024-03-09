/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaabi <ichaabi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 00:56:51 by ichaabi           #+#    #+#             */
/*   Updated: 2024/03/09 02:28:24 by ichaabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	animate_exit(t_mlx *mlx_pointers)
{
	t_animation	*animation;

	animation = (t_animation *)(mlx_pointers->exit);
	put_image(mlx_pointers, mlx_pointers->i, mlx_pointers->j, animation->images[animation->current]);
	animation->current = (animation->current + 1) % 5;//Incrémenter l'indice de l'image actuelle pour afficher la suivante
	usleep(200000);//200 000 microsecondes = 0.2 seconde
	return (0);
}

void	the_exit_animation(t_mlx *mlx_pointers)
{
	t_animation	*animation;

	animation = malloc(sizeof(t_animation));
	if (!animation)
		errors("Error\nAllocate memory for animation", 2);
	load_and_display_image(mlx_pointers, "exit_1.xpm", &(animation->images[2]));
	load_and_display_image(mlx_pointers, "exit_2.xpm", &(animation->images[3]));
	load_and_display_image(mlx_pointers, "exit_3.xpm", &(animation->images[4]));
	load_and_display_image(mlx_pointers, "exit_4.xpm", &(animation->images[5]));
	load_and_display_image(mlx_pointers, "thexit.xpm", &(animation->images[1]));

	animation->current = 0;//initialise l indice de l image actuelle
	mlx_pointers->exit = animation;
	mlx_loop_hook(mlx_pointers->mlx_p, animate_exit, mlx_pointers);
}