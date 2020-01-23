/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 16:31:53 by cbruno            #+#    #+#             */
/*   Updated: 2019/01/24 16:33:47 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "./libft/libft.h"
# include "./minilibx_macos/include/mlx.h"
# include <math.h>
# include <stdio.h>
# include <dirent.h>

# define ROUGE				0xFF0000
# define LIME				0x00FF00
# define MAGENTA			0xFF00FF
# define CYAN				0x00FFFF
# define YELLOW				0xFFFF00

# define ERROR_MALLOC		0
# define ERROR_OPEN			1
# define ERROR_CLOSE		2
# define ERROR_MLX_INIT		3
# define ERROR_NEW_WIN		4
# define ERROR_INIT_GAME	5

# define KEY_ESC			53
# define KEY_UP				126
# define KEY_DOWN			125
# define KEY_LEFT			123
# define KEY_RIGHT			124
# define KEY_C				8
# define KEY_R				15
# define KEY_P				35
# define KEY_PLUS			24
# define KEY_MINUS			27
# define KEY_Q				12
# define KEY_E				14
# define KEY_W				13
# define KEY_S				1
# define KEY_A				0
# define KEY_D				2

# define MOUSE_LEFT			1
# define MOUSE_RIGHT		2
# define MOUSE_UP			5
# define MOUSE_DOWN			4

# define KEYPRESS			2
# define MOUSEPRESS			4
# define MOUSERELEASE		5
# define MOUSEMOVE			6

# define WIDTH				1600
# define HEIGHT				1200

/*
 ** Structures
*/

typedef enum		e_bool
{
	false, true
}					t_bool;

typedef struct		s_image
{
	void			*img_ptr;
	char			*img;
	int				bpp;
	int				size_x;
	int				endian;
}					t_image;

typedef struct		s_graphic
{
	char			*title;
	void			*mlx_ptr;
	void			*win_ptr;
	int				x_min;
	int				x_max;
	int				y_min;
	int				y_max;
	int				x_center;
	int				y_center;
}					t_graphic;

typedef struct		s_mouse
{
	t_bool			status;
	int				button;
	int				current[2];
	int				last[2];
}					t_mouse;

typedef struct		s_fractal
{
	int				name;
	int				iter_max;
	float			x1;
	float			x2;
	float			y1;
	float			y2;
	float			zr;
	float			zi;
	float			cr;
	float			ci;
	float			tmp;
}					t_fractal;

typedef struct		s_game
{
	char			*file;
	t_graphic		graphic;
	t_image			image;
	t_fractal		fractal;
	t_mouse			mouse;
	void			(*function)();
	int				color_max;
	int				color_value;
	int				x;
	int				y;
	int				zoom;
	int				option_x;
	int				option_y;
}					t_game;

/*
 ** Print.c
*/

t_bool				print_usage(void);

t_bool				print_error(t_game *game, int error);

/*
 ** Key.c
*/

int					deal_key(int key, void *param);

/*
 ** Mouse.c
*/

int					mouse_press(int button, int x, int y, t_game *game);

int					mouse_release(int button, int x, int y, t_game *game);

int					mouse_move(int x, int y, t_game *game);

t_bool				init_mouse(t_game *game);

/*
 ** Paint.c
*/

void				put_pxl(t_game *game, int x, int y, unsigned int color);

void				paint(t_game *game);

/*
 ** Graphic.c
*/

t_bool				init_graphic(t_game *game);

void				mainloop(t_game *game);

/*
 ** Free.c
*/

void				free_all(t_game *game);

/*
 ** Image.c
*/

t_bool				init_image(t_game *game);

/*
 ** Mandelbrot.c
*/

void				mandelbrot(t_game *game);

t_bool				init_mandelbrot(t_game *game);

/*
 ** Julia.c
*/

void				julia_change(t_game *game);

void				julia(t_game *game);

t_bool				init_julia(t_game *game);

/*
 ** Mandelbrot.c
*/

void				fractal(t_game *game);

t_bool				init_fractal(t_game *game);

/*
 ** Color.c
*/

unsigned int		get_color(t_game *game, int a);

/*
 ** Menu.c
*/

void				show_menu(t_game *game);

/*
 ** Utils.c
*/

void				zoom_in(t_game *game, float zoom);

void				zoom_out(t_game *game, float zoom);

/*
 ** Debug.c
*/

void				debug_graphic(t_graphic self);

void				debug_image(t_image self);

void				debug_fractal(t_fractal self);

#endif
