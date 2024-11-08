/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 14:39:48 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/09/25 16:38:49 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <signal.h>
# include <limits.h>
# include <fcntl.h>
# include <stdbool.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/ioctl.h>
# include <math.h>
# include <time.h>
# include "../mlx_linux/mlx.h"

/* Errors */
# define ER_EMPTY_FILE "Scene description file is empty or is a directory!"
# define ER_OPEN_FAILED "Can't open scene description file!"
# define ER_ARGC "Cub3d must receive a parameter with scene description!"
# define ER_EXTENSION_FILE "Cub3d must receive a file endeding in .cub!"
# define ER_ONLY_ONE "Directions must receive only one information, and that\
 must to be a path!"
# define ER_SCENE_EL "The file does not have all and correct specifications for the\
 scene elements before map!"
# define ER_INCOMPLET "The file does not contain all the necessary information!"
# define ER_TEXTURE "The texture elements can only have the path without spaces as\
 information!"
# define ER_RGB_NBR "RGB color requires three numeric values, an integer\
 between 0 and 255, separated only by a comma!"
# define ER_INV_CHAR "The map contains invalid characters!"
# define ER_NOT_PLAYER "The map does not contain the player's position!"
# define ER_ONE_PLAYER "The map can only contain one position for the player!"

# define TILESIZE 15
# define VISUAL_ANGLE 60
# define VISUAL_ANGLE_RAD 1.04719767
# define VISUAL_LENGTH 10
# define MOVE_SPEED 0.08
# define PI 3.1415926
# define IMAGE_WIDTH 1000
# define IMAGE_HEIGHT 800
# define WALL_HEIGHT 20
# define MINIMAP_W 300
# define MINIMAP_H 210
# define ROTATION_SPEED 0.04
# define RAYS_NUMBER 200
// # define TEXTURE_SIZE 512
# define TX_SIZE 512
# define DEMO_SPRITE_COUNT 13
# define CAT_SPRITE_COUNT 8
# define ANIMATION_SPEED 10 
# define SHRIMP_FRAMES 10

typedef struct s_pos
{
	float	x;
	float	y;
}			t_pos;

typedef struct s_coord
{
	int	x;
	int	y;
}			t_coord;

typedef struct s_sprite
{
	int		type;
	double	dist;
	t_pos	pos;
	t_pos	transform;
	int		screen_x;
	int		height;
	int		width;
	t_coord	draw_start;
	t_coord	draw_end;
	t_coord	tex;
	int		frame;
	float	frame_time;
	float	current_time;
}	t_sprite;

typedef enum s_sp_type
{
	CAT = 0,
	DEMO = 1
}	t_sp_type;

typedef struct s_draw
{
	int	line_height;
	int	start;
	int	end;
	int	i;
	int	wall_x;
}	t_draw;

typedef struct s_ray
{
	int		ray_nbr;
	int		mapx;
	int		mapy;
	int		stepx;
	int		stepy;
	int		side;
	bool	hit;
	float	ray_pos;
	float	wall_dist;
	float	w_distance[IMAGE_WIDTH];
	t_pos	pl_dir;
	t_pos	dir;
	t_pos	ray_dir;
	t_pos	dist;
	t_pos	side_dist;
	t_draw	draw;
}	t_ray;

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_image;

typedef struct s_map
{
	char	**map_rect;
	int		height;
	int		width;
	t_pos	*p_position;
	t_pos	*m_position;
	float	p_direction;
	char	p_orientation;
	int		square_length;
}			t_map;

typedef struct s_shrimp
{
	bool	visible;
	int		current_frame;
	float	frame_time;
	float	current_time;
	t_coord	pos;
}	t_shrimp;

typedef struct s_game
{
	void		*mlx;
	void		*mlx_win;
	bool		key_a;
	bool		key_w;
	bool		key_s;
	bool		key_d;
	bool		key_left;
	bool		key_right;
	bool		mouse;
	t_image		*image;
	t_map		*map;
	t_sprite	*cats;
	t_shrimp	shrimp;
	int			nbr_cats;
	int			demo_cats;
	int			good_cats;
	int			colectables;
	int			exorcise_cat_index;
}	t_game;

typedef struct s_intro
{
	int		current_frame;
	float	frame_time;
	float	current_time;
	bool	is_intro_active;
}	t_intro;

typedef struct s_data
{
	char	*data_file;
	char	*t_north;
	char	*t_south;
	char	*t_west;
	char	*t_east;
	char	*floor_color;
	char	*ceiling_color;
	char	**map;
	int		*finish_texture;
	int		*texture_buffer[6];
	int		*start_texture[4];
	int		*cat_sprite[8];
	int		*demo_sprite[13];
	int		*shrimp_sprite[11];
	t_intro	intro;
	bool	game_over;
	t_map	*map_inf;
	t_game	*game;
}				t_data;

typedef enum e_side
{
	WEST = 1,
	EAST = 2,
	NORTH = 3,
	SOUTH = 4,
	DOOR = 5,
	DOOR2 = 6
}	t_side;

typedef enum e_mask
{
	K_PRESS_MASK = (1L << 0),
	K_RELEASE_MASK = (1L << 1),
	CLOSE_MASK = (1L << 17),
	M_PRESS_MASK = (1L << 2),
	M_RELEASE_MASK = (1L<< 3),
	M_MOUTION_MASK = (1L << 6),
	ENTER_WIN = (1L << 4),
	LEAVE_WIN = (1L << 5)
}	t_mask;

typedef enum e_event
{
	K_PRESS = 2,
	K_RELEASE = 3,
	M_PRESS = 4,
	M_RELEASE = 5,
	M_NOTIFY = 6,
	E_WIN = 7,
	DESTROY = 17
}	t_event;

typedef enum e_key
{
	ESC = 65307,
	M = 1,
	Z = 122,
	A = 97,
	S = 115,
	D = 100,
	W = 119,
	Q = 113,
	E = 101,
	UP = 65362,
	DOWN = 65364,
	RIGHT = 65363,
	LEFT = 65361
}		t_key;

/* animation.c */
void	init_cats(t_game *game);
void	check_path(t_data *data);

/* move.c */
int		move(t_data *data);
int		key_release(int keycode, t_game *game);
int		key_press(int keycode, t_game *game);
float	get_direction(t_data *data);

/* colision */
void	update_position(t_data *data, float new_x, float new_y);
int		check_collision(t_data *data, float new_x, float new_y);

/* animate.c */
void	update_cats(t_sprite *sprites, int num_sprites);
void	draw_sprites(t_data *data, t_ray *ray, t_sprite *cats, int num_cats);
void	draw_single_sprite(t_data *data, t_ray *ray, t_sprite *cat);
void	draw_vertical_stripe(t_data *data, t_sprite *cat, int st);
int		get_sprite_color(t_data *data, t_sprite *cat, int tex_x, int tex_y);

/* animate_aux.c */
void	set_distances(t_data *data, t_ray *ray, t_sprite *sprites, int n);

/* minimap.c */
void	put_minimap(t_image *image);
void	draw_map_tile(t_image *image, t_pos coord, int color);
void	draw_player(t_image *image, t_pos player);
void	draw_tiles(t_image *image);
int		check_wall(char **map, t_pos start, t_pos pos, int *color);
void	calculate_map_bounds(t_data *data, t_pos *s, t_pos *end, t_pos *offset);
void	draw_tiles_loop(t_pos s, t_pos end, t_pos offset, t_pos pos);

/* get_textures.c */
int		*get_texture(t_ray *ray);
void	load_textures(t_data *data, int tx_i, char *path);
void	init_textures(t_data *data);
double	calculate_tex_pos(t_ray *ray, double step);

/*draw_beam.c*/
void	draw(t_coord center, t_coord end);
void	draw_ray_minimap(t_data *data, t_ray *ray);

/* get_textures.c */
int		*get_texture(t_ray *ray);
void	load_textures(t_data *data, int tx_i, char *path);
void	init_textures(t_data *data);

/* main.c */
void	my_clear_image(t_image *image);
int		close_window(void);
t_data	*get_data(void);
void	my_mlx_pixel_put(t_image *image, int x, int y, int color);
void	my_mlx_pixel_put_2(t_data *data, int x, int y, int color);

/* Main */
void	error_message(char *message);
void	init_data(t_data *data);

/* clean.c */
void	free_data(t_data *data);
void	*ptr_free(char **ptr);
void	deal_with_error(t_data *data, char *message);
void	free_map(t_map *map_inf);

/* check_elements.c */
void	textures_check(t_data *data, char *element);
void	check_permission(t_data *data, char *element);
void	check_color_numbers(t_data *data, char **c_nbrs);
void	color_check(t_data *data, char *element);
bool	rgb_limits(char *c_nbrs);

/* check_first.c */
bool	is_exception(char *c);
void	check_argc(int argc, t_data *data);
void	check_file_name(char *file_name, t_data *data);
void	check_empty_file(t_data *data);
void	is_map(t_data *data);

/* check_map_char.c */
bool	is_player(char c);
bool	is_valid_character(int c);
bool	valid_player(t_data *data, char c, int i, int j);
void	largest_line(t_data *data, int size);
void	validate_map_characters(t_data *data);

/* check_map.c */
void	map_rect_construction(t_data *data);
void	floodfill(t_data *data, char **map_dup, int x, int y);
bool	look_for_zero(t_data *data, char **map_dup);
void	map_is_closed(t_data *data);
void	validate_map(t_data *data);

/* check.c */
void	check_scene_description(int argc, char **argv, t_data *data);
void	validate_elements(t_data *data);
bool	is_all_num(char *c_nbrs);

/* deal_with_map.c */
void	separate_map(t_data *data);
bool	empty_lines_in_map(char	*map);
bool	have_more(char *map);
bool	have_more_line(char *map);
char	*is_filled(t_data *data, char *id);

/* fill_struct.c */
char	*get_line(t_data *data, int j, int i);
void	copy_line(t_data *data, int j, int i, char *id);
void	get_scene_elements(t_data *data, int j, int i);
bool	is_element(char *str);
bool	fill_data(t_data *data, int j, int i);

/* read_scene_description.c */
void	read_scene_description(char *file_name, t_data *data);
char	*replace_tabs(char *line);
void	change_tabs(const char *line, char *new_line);
bool	check_quotes(char *str);
bool	is_exception(char *c);
int		have_tabs(char *line);

/* utils.c */
int		split_size(char **mtx);
int		move_space(char *src, int i);
bool	check_quotes(char *str);
bool	is_empty_line(char *src, int j);
bool	is_space(char c);

/* Raycasting Functions */
void	raycasting(t_data *data);
void	draw_view(t_data *data, t_ray *ray);

void	init_textures(t_data *data);
void	load_textures(t_data *data, int texture_index, char *path);
/* raycasting.c */
void	raycasting(t_data *data);
void	init_ray(t_ray *ray, t_data *data);
void	which_side(t_ray *ray);
void	step_and_distance(t_ray *ray, t_data *data);
void	get_directions(t_ray *ray, t_data *data);
/* raycasting_aux.c */
void	which_side(t_ray *ray);
void	get_directions(t_ray *ray, t_data *data);
void	init_ray(t_ray *ray, t_data *data);

/* calculate.c */
void	calculate_dda(t_ray *ray, t_data *data);
void	find_side(t_ray *ray, t_data *data);
void	check_next_step(t_ray *ray, t_data *data);
void	calculate_distance(t_ray *ray, t_data *data);

/* draw_view.c */
void	draw_view(t_data *data, t_ray *ray);
void	draw_column(int y, t_ray *ray, char *color);
void	draw_wall(t_data *data, t_ray *ray);
int		get_color(t_ray *ray);
int		rgb_to_int(char *color);

/* init.c */
void	game_loop(t_data *data);
void	init_data(t_data *data);
void	init_game(t_data *data);

/* ceiling_and_floor.c */
void	ceiling_shadow(t_ray *ray, int *color);
void	floor_shadow(t_ray *ray, int *color, int i);
void	draw_floor(int y, t_ray *ray, char *color);
void	draw_ceiling(int y, t_ray *ray, char *color);

void	draw_shrimp(t_data *data);
void	update_shrimp(t_game *game);
void	render_game(t_data *data);
void	finish_game(t_data *data);
void	handle_door_and_cats(void);
void	exorcise(t_coord location);
void	free_paths(t_data *data);
void	free_textures(t_data *data);
void	free_texture_array(int **textures, int count);
void	free_map(t_map *map_inf);

int		init_mouse(t_game *game);
int		close_window(void);
void	render_start_screen(t_data *data);

#endif