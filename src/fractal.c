/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 15:18:17 by cbruno            #+#    #+#             */
/*   Updated: 2019/01/24 16:17:19 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	fractal_iter(t_game *game)
{
	int		i;

	i = -1;
	while (++i < game->fractal.iter_max)
	{
		game->fractal.tmp = game->fractal.zr;
		game->fractal.zr = game->fractal.zr * game->fractal.zr -
			game->fractal.zi * game->fractal.zi + game->fractal.cr;
		game->fractal.zi = 2 * game->fractal.zi * game->fractal.tmp +
			game->fractal.ci;
		if (game->fractal.zr * game->fractal.zr + game->fractal.zi *
				game->fractal.zi >= 4)
			return (i);
	}
	return (i);
}

void		fractal(t_game *game)
{
	int		x;
	int		y;

	x = game->x;
	while (x < WIDTH + game->x)
	{
		y = game->y;
		while (y < HEIGHT + game->y)
		{
			game->fractal.zr = (long double)x / game->zoom + game->fractal.x1;
			game->fractal.zi = (long double)y / game->zoom + game->fractal.y1;
			put_pxl(game, (x - game->x), (y - game->y),
					get_color(game, fractal_iter(game)));
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(game->graphic.mlx_ptr, game->graphic.win_ptr,
			game->image.img_ptr, 0, 0);
}

t_bool		init_fractal(t_game *game)
{
	t_fractal	self;

	self.iter_max = 50;
	self.name = 0;
	self.x1 = -2.1;
	self.x2 = 0.6;
	self.y1 = -1.2;
	self.y2 = 1.2;
	self.zr = 0;
	self.zi = 0;
	self.cr = -1.476;
	self.ci = 0.;
	self.tmp = 0;
	game->fractal = self;
	game->function = fractal;
	return (true);
}
