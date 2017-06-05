/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Wolf3D.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpachy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 13:39:00 by hpachy            #+#    #+#             */
/*   Updated: 2017/01/30 12:59:08 by hpachy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <mlx.h>
# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# define SCREEMWIDTH 800
# define SCREEMHEIGHT 800
# define TEXWIDTH 64
# define TEXHEIGHT 64
# define MAPWIDTH 30
# define MAPHEIGHT 36

typedef	struct	s_test
{
	float		x;
	float		y;
	float		dx;
	float		dy;
	int			i;
	float		xinc;
	float		yinc;
	float		cumul;
}				t_test;

typedef	struct	s_board
{
	float		x;
	float		y;
	int			wall;
	int			r;
	int			g;
	int			b;
	int			trans;
}				t_board;

typedef struct	s_multtouch
{
	int			keycode124;
	int			keycode123;
	int			keycode125;
	int			keycode126;
	int			keycode49;
	int			keycode53;
}				t_multtouch;

typedef	struct	s_data
{
	void		*mlx;
	void		*win;
	void		*img;
	void		*sky;
	void		*blue_sky;
	void		*start;
	void		*fin;
	void		*knife1;
	void		*knife2;
	void		*knife3;
	void		*knife4;
	void		*lotus;
	char		*lotus_text;
	void		*green;
	char		*green_text;
	void		*blue;
	char		*blue_text;
	void		*brown;
	char		*brown_text;
	void		*key;
	char		*key_text;
	void		*key2;
	char		*key2_text;
	void		*blue_orange;
	char		*blue_orange_text;
	void		*greystone;
	char		*greystone_text;
	void		*door;
	char		*door_text;
	void		*metal;
	char		*metal_text;
	void		*wood;
	char		*wood_text;
	void		*bush;
	char		*bush_text;
	void		*barrel;
	char		*barrel_text;
	void		*eagle;
	char		*eagle_text;
	void		*trollcat;
	char		*trollcat_text;
	void		*cat;
	char		*cat_text;
	void		*youmad;
	char		*youmad_text;
	void		*bedrock;
	char		*bedrock_text;
	void		*brique;
	char		*brique_text;
	void		*bluestone;
	char		*bluestone_text;
	char		*picture;
	char		*argc;
	double		floorxwall;
	double		floorywall;
	double		distwall;
	double		distplayer;
	double		currentdist;
	int			y_floor;
	double		weight;
	double		currentfloorx;
	double		currentfloory;
	int			definition_texture;
	int			int_key;
	int			width_hd;
	int			height_hd;
	int			bits_wall_hd;
	int			dian_wall_hd;
	int			width_wall_hd;
	int			height_wall_hd;
	int			size_line_wall_hd;
	int			nb_trollcat;
	int			width_start;
	int			height_start;
	int			x;
	int			y;
	int			nombre_x;
	int			bits;
	int			dian;
	int			size_line;
	int			bits_wall;
	int			dian_wall;
	int			size_line_wall;
	int			bits_wall_cat;
	int			dian_wall_cat;
	int			width_wall_cat;
	int			height_wall_cat;
	int			size_line_wall_cat;
	int			bits_wall_bedrock;
	int			dian_wall_bedrock;
	int			width_wall_bedrock;
	int			height_wall_bedrock;
	int			size_line_wall_bedrock;
	int			bits_wall_youmad;
	int			dian_wall_youmad;
	int			width_wall_youmad;
	int			height_wall_youmad;
	int			size_line_wall_youmad;
	int			bits_wall_metal;
	int			dian_wall_metal;
	int			width_wall_metal;
	int			height_wall_metal;
	int			size_line_wall_metal;
	int			width_knife1;
	int			height_knife1;
	int			width_knife2;
	int			height_knife2;
	int			width_knife3;
	int			height_knife3;
	int			width_knife4;
	int			height_knife4;
	t_board		**map;
	long	int	texx;
	long	int	texy;
	int			index_x;
	int			floortexx;
	int			floortexy;
	int			textnum;
	int			width;
	int			height;
	int			width_wall;
	int			height_wall;
	int			drawstart;
	int			drawend;
	int			index;
	t_board		wall_tex;
	t_board		point1;
	t_board		point2;
	t_multtouch	touch;
	int			destruction;
	double		wallx;
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		planex;
	double		planey;
	double		time;
	double		oldtime;
	double		camerax;
	double		rayposx;
	double		rayposy;
	double		raydirx;
	double		raydiry;
	int			mapx;
	int			mapy;
	double		sidedistx;
	double		sidedisty;
	double		deltadistx;
	double		deltadisty;
	double		perpwalldist;
	int			stepx;
	int			stepy;
	int			hit;
	int			side;
	int			fd;
	int			lineheight;
	int			wall_pos_x;
	int			wall_pos_y;
}				t_data;

int				error_shell(int error);
void			direction(t_data *p);
void			wall_detection(t_data *p);
void			wall_hit_box(t_data *p);
int				parser_map(t_data *p);
void			animation_knife(t_data *p);
int				knife_texture(t_data *p);
void			chose_texture_hd(t_data *p);
void			chose_texture(t_data *p);
void			print_wall_color_hd(t_data *p, int y);
void			print_wall_color(t_data *p, int y);
void			key2(t_data *p);
void			brown_key(t_data *p);
int				multi_touch_press(int keycode, void *param);
void			door(t_data *p);
void			print_floor_hd(t_data *p);
void			troll_cat_hd(t_data *p);
void			bush(t_data *p);
void			print_wall_hd(t_data *p);
void			green(t_data *p);
void			blue(t_data *p);
void			brown(t_data *p);
void			lotus(t_data *p);
void			sol_metal(t_data *p);
void			blue_orange(t_data *p);
int				load_hd_text(t_data *p);
int				load_text(t_data *p);
void			trollcat(t_data *p);
void			bedrock(t_data *p);
void			youmad(t_data *p);
void			wall_brique(t_data *p);
void			barrel(t_data *p);
void			blue_stone(t_data *p);
void			eagle(t_data *p);
void			grey_stone_wall(t_data *p);
void			print_wall(t_data *p);
void			print_floor(t_data *p);
int				texture(t_data *p);
void			detection(int x, int y, t_data *p);
int				key_hook(t_data *data);
void			ccinit(t_data *p);
void			init_while(t_data *p);
void			init_move_var(t_data *p);
void			light_on(int x, int y, t_data p, t_board board);
double			my_abs(double a);
int				ray_casting(t_data *p);
void			opti_line(t_data data, t_board board, t_board boardbis);
int				parsing(t_data *p, char *map);
int				key_release(int keycode, void *param);
#endif
