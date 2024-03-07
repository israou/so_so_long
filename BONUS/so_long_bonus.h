/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaabi <ichaabi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 20:39:46 by ichaabi           #+#    #+#             */
/*   Updated: 2024/03/07 20:39:56 by ichaabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

# define ON_KEYPRESS 2
# define BOUTON_CLOSE 17

# define A 0
# define S 1
# define D 2
# define W 13

# include <unistd.h>//open, close, read, write
# include <stdlib.h>//malloc, free, exit
# include <stdio.h>//perror
# include <string.h>//strerror
# include <stddef.h>//size_t
# include <limits.h>//int max min
# include <fcntl.h>
# include <mlx.h>

typedef struct s_mlx
{
	int		height;
	int		width;
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
	int		moves;
}			t_mlx;

//---------------------parsing-----------------
int		strcompare(const char *s1, const char *s2);
void	ft_putstr_fd(char *str, int fd);
void	check_maps(char **two_d);
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
void	check_maps2(int efound, int cfound, int pfound);

//------------------backtracking

char	**copy_map(char **two_d);
int		valid_p_c_e(char **two_d);
char	**copy_map(char **two_d);
void	recursive_fill(char **new_map, int i, int j);
void	checking_valid_path(char **new_map);
void	the_valid_path(char **two_d);
void	errors(char *str, int fd);
int		how_many(char **two_d);
char	**ft_free(char **two_d);
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
int		close_map(void);
int		move(int keycode, t_mlx *mlx);
void	find_player(char **two_d, int *i, int *j);
void	ft_putnbr_fd(int nb, int fd);
#endif