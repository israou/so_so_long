/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaabi <ichaabi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:04:43 by ichaabi           #+#    #+#             */
/*   Updated: 2024/02/26 18:01:58 by ichaabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

# include <unistd.h>//open, close, read, write
# include <stdlib.h>//malloc, free, exit
# include <stdio.h>//perror
# include <string.h>//strerror
# include <stddef.h>//size_t
# include <limits.h>//int max min
# include <fcntl.h>

typedef struct s_positions
{
	int		height;
	int		width;
	int		i;
	int		j;
}			t_position;

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
char	**parse_maps(int ac, char **av);
int		max_line(int fd);
char	**copy_map(char **two_d);
int		checking_valid_path(char **two_d);
#endif