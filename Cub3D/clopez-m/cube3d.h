/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clopez-m <clopez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 13:45:05 by clopez-m          #+#    #+#             */
/*   Updated: 2020/03/05 16:14:25 by clopez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H
# define BUFFER_SIZE 1
# define WIN_WIDTH 1024
# define WIN_HEIGHT 720
# define MAP_WIDTH 24
# define MAP_HEIGHT 24
# define XMAX 1920
# define YMAX 1080
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_W 13
# define KEY_ESQ 53
# define KEY_SHIFT 257
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define DIRN 30
# define DIRW 39
# define DIRE 21
# define DIRS 35
# include <unistd.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include "minilibx/mlx.h"
# include "libft/libft.h"
# include "gnl/get_next_line.h"

typedef struct	s_variables
{
	void		*img_ptr;
	void		*mlx_ptr;
	void		*win_ptr;
	int			*data;
	int			size_l;
	int			bpp;
	int			wbpp[8];
	int			endian;
	int			id;
	int			stepx;
	int			stepy;
	int			hit;
	int			side;
	int			lineheight;
	int			lineheightaux;
	int			drawstart;
	int			drawend;
	int			color;
	int			color2;
	int			j;
	int			cox;
	int			x;
	int			y;
	int			w[8];
	int			h[8];
	int			wendian[8];
	int			mapx;
	int			mapy;
	int			wsl[8];
	int			obj;
	int 		obstart;
	int			obend;
	int			objposx;
	int			objposy;
	int			objposxtwo;
	int			count;
	int			x_text;
	int			obx;
	int			oby;
	int			presedw;
	int			preseda;
	int			preseds;
	int			presedd;
	int			presedl;
	int			presedr;
	int			presedesq;
	int			initialdir;
	int			screenshot;
	int			fpposx;
	int			fpposy;
	int			sl;
	int			objbool;
	int			**mapn;
	int			width;
	int			height;
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		planex;
	double		planey;
	double		time;
	double		oldtime;
	double 		olddirx;
	double 		oldplanex;
	double		camerax;
	double		raydirx;
	double		raydiry;
	double		sidedistx;
	double		sidedisty;
	double		deltadistx;
	double		deltadisty;
	double		perpwalldist;
	double		objdist;
	double		x_wall;
	double		movespeed;
	double		frametime;
	double		rotspeed;
	char		*wdata[8];
	char		*map;
	char		*wlone[8];
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		*s;
	char		*f;
	char		*c;
	char		*img;
}				t_variables;

void		initiate(t_variables *s);
void		input_controller(t_variables *s);
int			presed(int key, t_variables *s);
int			nopresed(int key, t_variables *s);
void		file_processor(t_variables *s);
void		load_file_processor(t_variables *s);
void		first_raycast(t_variables *s);
void		second_raycast(t_variables *s);
void		third_raycast(t_variables *s);
void		fourth_raycast(t_variables *s);
void		fifth_raycast(t_variables *s);
void		first_verline(t_variables *s);
void		second_verline(t_variables *s);
void		third_verline(t_variables *s);
void		maparray_converter(t_variables *s);
void		second_maparray_converter(t_variables *s, int x, int n, int y);
void		free_array(t_variables *s);
int			name_checker(char **argv);
int			checker_controller(t_variables *s);
void		read_map(t_variables *s, char **argv, int argc);
void		put_pxl_to_img(t_variables *s, int x, int y);
void		info_controller(t_variables *s, char *buffer);
void		executor(t_variables *s);
void		object_calculator(t_variables *s);
int			key_handler(t_variables *s);
void		image_converter(t_variables *s);
#endif
