/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaabi <ichaabi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:04:43 by ichaabi           #+#    #+#             */
/*   Updated: 2024/03/05 00:04:21 by ichaabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

//liberation de touches du clavier dans une app graphique
#   define ON_KEYUP 17
#   define ON_KEYDOWN 2

# define A 5
# define S 1
# define D 2
# define W 3

# include <unistd.h>//open, close, read, write
# include <stdlib.h>//malloc, free, exit
# include <stdio.h>//perror
# include <string.h>//strerror
# include <stddef.h>//size_t
# include <limits.h>//int max min
# include <fcntl.h>
# include <mlx.h>

typedef struct t_position
{
	int		i;
	int		j;
}			t_position;

typedef struct s_mlx
{
	int		height;
	int		width;
	int 	w;
	int		h;
	void	*mlx_p;
	void	*win_p;
	void	*img_p;
	void	*player;
	void	*collect;
	void	*wall;
	void	*background;
	void	*exit;
	char	**map;
	int		i;
	int		j;
}			t_mlx;

//---------------------parsing-----------------
int		strcompare(const char *s1, const char *s2);
void	ft_putstr_fd(char *str, int fd);
int		check_maps(char **two_d);
void	check_valid_char(char **two_d);
int		check_empty(char **two_d);
char	*divising(char *s, char **reste);
char	*get_next_line(int fd);
int		ft_strlen(const char *s);
int		checknewline(char *s);
char	*ft_strdup(char *s);
char	*join4gnl(char const *stash, char const *buf);
char	*extraction(char const *s, unsigned int start, size_t len);
void	check_extension(char *str);
char	**read_maps(int fd, char *av);
void	check_walls_top_down(char **two_d);
void	check_walls_left_right(char **two_d);
int		map_count(char **two_d);
void	check_long_of_map(char **two_d);
char	**parse_maps(int ac, char **av, t_mlx *mlx);
int		max_line(int fd);

//------------------backtracking

char	**copy_map(char **two_d);
int		valid_P_C_E(char **two_d);
char	**copy_map(char **two_d);
void	recursive_fill(char **new_map, int i, int j);
void	checking_valid_path(char **new_map);
void	the_valid_path(char **two_d, t_position *r);
void	errors(char *str, int fd);
void	print_map(char **two_d);
int		how_many(char **two_d);
//---------------mlx
void	the_mlx(t_mlx *mlx_pointers);
void	put_image(t_mlx *mlx, int i, int j, void *img);
void	print_img(char **map, t_mlx mlx);
void	initialize(t_mlx *mlx);
void	init_mlx(t_mlx *mlx_pointers);
void	create_window(t_mlx *mlx_pointers);
void	load_and_display_image(t_mlx *mlx_pointers, char *filename, void **p);
void	print_img(char **map, t_mlx mlx);
//-----------------move
void	to_up(t_mlx *mlx);
void	to_down(t_mlx *mlx);
void	to_right(t_mlx *mlx);
void	to_left(t_mlx *mlx);
void	move_u_d_l_r(t_mlx *mlx, int keycode);
int		how_many(char **two_d);
void	close_map(t_mlx *mlx);
void	game_over(t_mlx *mlx);
void	destory_img(t_mlx *mlx);
int		hook(t_mlx *mlx, int keycode);
char	*ft_itoa(int n);
void find_player(char **two_d, int *i, int *j);

#endif