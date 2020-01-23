/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 12:17:54 by cbruno            #+#    #+#             */
/*   Updated: 2019/01/24 16:24:58 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void		zoom_mouse(t_game *game, int x, int y)
{
	game->mouse.button = 5;
	game->x += y / 5;
	game->y += x / 5;
	game->zoom = game->zoom * 1.2;
	game->y = game->y * 1.2;
	game->x = game->x * 1.2;
}

int				mouse_press(int button, int x, int y, t_game *game)
{
	game->mouse.status = true;
	if (button == 1)
	{
		game->mouse.button = 1;
		game->mouse.last[0] = x;
		game->mouse.last[1] = y;
	}
	if (button == 5)
		zoom_mouse(game, x, y);
	if (button == 4)
	{
		game->mouse.button = 4;
		game->x += y / 5;
		game->y += x / 5;
		game->zoom = game->zoom / 1.2;
		game->y = game->y / 1.2;
		game->x = game->x / 1.2;
	}
	paint(game);
	return (0);
}

int				mouse_release(int button, int x, int y, t_game *game)
{
	if (game->mouse.button == 1)
	{
		game->mouse.status = false;
		game->mouse.current[0] = x;
		game->mouse.current[1] = y;
	}
	game->mouse.button = 0;
	return (0);
}

int				mouse_move(int x, int y, t_game *game)
{
	int		delta_x;
	int		delta_y;
	float	theta;
	float	sigma;

	if (game->mouse.status == true)
	{
		if (game->mouse.button == 1)
		{
			if ((x > 0 || x < WIDTH) && (y > 0 || x < HEIGHT))
			{
				delta_x = game->mouse.last[0] - x;
				delta_y = game->mouse.last[1] - y;
				game->x += delta_x;
				game->y += delta_y;
				game->mouse.last[0] = x;
				game->mouse.last[1] = y;
			}
		}
	}
	paint(game);
	return (0);
}

t_bool			init_mouse(t_game *game)
{
	t_mouse		self;

	self.status = false;
	self.button = 0;
	self.current[0] = 0;
	self.current[1] = 0;
	self.last[0] = 0;
	self.last[1] = 0;
	game->mouse = self;
	return (true);
}
