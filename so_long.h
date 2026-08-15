/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iskaraag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 18:22:13 by iskaraag          #+#    #+#             */
/*   Updated: 2024/09/06 18:22:14 by iskaraag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define IMG_SIZE 64

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_map
{
	char			*mtxt;
	char			*tmp;
	struct s_map	*prev;
	struct s_map	*nxt;
}					t_map;

typedef struct s_data
{
	int				x;
	int				y;
	int				c;
	int				posx;
	int				posy;
	void			*ptry;
	int				extx;
	int				exty;
	void			*exptry;
	void			*mlx_ptr;
	void			*win_ptr;
	void			*textures[5];
	t_map			*map;
}					t_data;
//draw.c
void	ft_draw(t_data *data);
void	draw_helper(t_data *data, t_map *mapy, int y);

//errors.c
void	error_main(t_map **nodes, bool needtoexit);
void	error_param(void);
void	map_error_open(void);
void	error_texture(t_data *data);

//errors2.c
void	map_notreachable(t_map **nodes);
void	map_error_wrong_char(t_map **map);
void	map_error_collectives(t_map **map);
void	map_notrectangle(t_map **nodes);
void	map_notsurrounded(t_map **nodes);

//keyhandler.c
int		on_keypress(int keysym, t_data *data);

//mapchecker_utils.c
void	points2p(t_map *head, t_map *temp, int i, bool isitrun);
t_map	*get_last_node(t_map *head);
t_map	*map_opener(int fd, t_map *map);

//mapchecker.c
void	finder(t_map *head, t_map **nodes);
void	map_checker(t_map *head);

//maplen.c
int		mapwidth(t_map *map);
int		mapheight(t_map *map);

//open_free.c
int		free_data(t_data *data);
void	free_nodes(t_map **nodes);
char	*map_name_check(char *name);
void	finish(t_data *data);

#endif
