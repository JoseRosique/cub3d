/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 16:26:08 by joslopez          #+#    #+#             */
/*   Updated: 2024/01/08 19:41:30 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "../../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include "../minilibx/mlx.h"
# include <math.h>
# include <stdio.h>

typedef struct s_rgb
{
	int				r;
	int				g;
	int				b;
}					t_rgb;

typedef struct s_map
{
	char			*line;
	struct s_map	*next;
}					t_map;

typedef struct s_arg
{
	int				screen_w;
	int				screen_h;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*door;
	t_rgb			floor;
	t_rgb			ceil;
	t_map			*map;
	int				fcounter;
	int				ccounter;
	int				linecounter;
}					t_arg;

typedef struct s_tex
{
	void			*tex_ptr;
	int				*tex_data;
	int				bpp;
	int				size_line;
	int				endian;
	int				width;
	int				height;
	char			*type;
}					t_tex;

typedef struct s_img
{
	void			*img_ptr;
	int				*img_data;
	int				bpp;
	int				size_line;
	int				endian;
	int				width;
	int				height;
}					t_img;

typedef struct s_move
{
	int				up;
	int				down;
	int				left;
	int				right;
	int				move_left;
	int				move_right;
}					t_move;

typedef struct s_ray
{
	double			planex;
	double			planey;
	double			stepx;
	double			stepy;
	double			dirx;
	double			diry;
	int				tex_x;
	int				tex_y;
	double			rposx;
	double			rposy;
	double			rdirx;
	double			rdiry;
	double			rdisdx;
	double			rdisdy;
	double			rdistx;
	double			rdisty;
	int				rmapx;
	int				rmapy;
	int				wall;
	int				wstart;
	int				wend;
	double			camera;
	int				hit;
	double			rh;
	double			step_tex;
	double			tex_pos;
	double			dist;
	double			speed;
	double			*zbuffer;
	double			sprite_dist;
	double			spstart;
	double			spend;
	int				door;
}					t_ray;

typedef struct s_pos
{
	int				x;
	int				y;
}					t_pos;

typedef struct s_env
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_arg			arg;
	char			**map;
	int				map_height;
	int				map_width;
	double			player_x;
	double			player_y;
	char			orientation;
	int				height;
	int				width;
	int				error;
	unsigned int	floor;
	unsigned int	ceil;
	t_move			move;
	t_ray			ray;
	t_img			*img;
	t_tex			*tex_s;
	t_tex			*tex_n;
	t_tex			*tex_w;
	t_tex			*tex_e;
	t_tex			*tex_door;
	unsigned int	color;
}					t_env;

int					check_identifier(t_arg *arg, char *buff);

int					check_orientation(t_arg *arg, char *buff);
int					check_orientation2(char *orientation, char *buff, int i,
						t_arg *arg);

int					check_map(t_map *map);

t_tex				*create_texture(t_env *env, char *file, char *type);
int					init_items(t_env *env);
t_env				start_environment(t_arg arg);
t_img				*ft_new_img(t_env *env, char *file);

void				start_position(t_env *env, t_arg a, int y, int x);

int					free_walls(t_env *env);
int					events(t_env env);

void				movement(t_env *env);

int					display_screen(t_env *env, int x);

t_map				*ft_lstlast_map(t_map *lst);
t_map				*ft_lstnew_map(void *content);
char				*map_without_spaces(char *str, char c, int i, int j);
void				ft_lstadd_back_map(t_map **alst, t_map *new);
int					ft_lstsize_map(t_map *lst);
void				ft_lstclear_map(t_map **lst);
char				**from_lst_to_tab(t_map *lst);
double				ft_abs(double x);

void				ft_free_tex(t_env *env, t_tex *tex);
void				ft_free_img(t_env *env, t_img *img);

int					start_textures(t_env *env);

int					ft_exit(t_env *env);
int					keypress(int key, t_env *env);
int					leave_key(int key, t_env *env);
void				free_texture(t_env *env, t_tex *tex);
void				free_image(t_env *env, t_img *img);

int					check_floor_ceil(t_arg *variables, char *buffer);

void				init_ray(t_env *env, int x);
void				direction_ray(t_env *env);
char				hit_ray(t_env *env, char wall_tex);
void				size_ray(t_env *env);
char				*display_column(t_env *env, int x, char tex, int y);
size_t				check_last_wall(char *tmp, size_t len);
int					check_characters(t_map *tmp, int i, t_map *prev);
int					check_last_wall_map(t_map *tmp, t_map *aux);
int					extra_map_check(t_map *map);
int					create_tmp_map(t_map *map, int len, int rows);

# define KEY_UP 13
# define KEY_RIGHT 2
# define KEY_LEFT 0
# define KEY_DOWN 1
# define ROTATE_LEFT 123
# define ROTATE_RIGHT 124
# define KEYPRESS 2
# define KEYRELEASE 3
# define KEYPRESSMASK 1
# define KEYRELEASEMASK 10
# define KEY_EXIT 53
# define STRUCTURENOTIFYMASK 10001
#endif