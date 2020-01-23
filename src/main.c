/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 11:38:38 by cbruno            #+#    #+#             */
/*   Updated: 2019/01/24 15:39:57 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static t_bool	set_fractal(t_game *game)
{
	if (ft_strcmp(game->file, "Mandelbrot") == 0)
	{
		if (!(init_mandelbrot(game)))
			return (false);
	}
	else if (ft_strcmp(game->file, "Julia") == 0)
	{
		if (!(init_julia(game)))
			return (false);
	}
	else if (ft_strcmp(game->file, "Fractal") == 0)
	{
		if (!(init_fractal(game)))
			return (false);
	}
	else
	{
		print_usage();
		free_all(game);
	}
	return (true);
}

static t_bool	init_game(t_game *game, char *file)
{
	game->file = ft_strdup(file);
	game->color_max = 0x000000;
	game->color_value = 1;
	game->zoom = 400;
	game->x = -game->graphic.x_center / 2;
	game->y = -game->graphic.y_center / 2;
	game->option_x = WIDTH / 2;
	game->option_y = HEIGHT / 2;
	if (!(set_fractal(game)))
		return (false);
	if (!(init_graphic(game)))
		return (false);
	if (!(init_image(game)))
		return (false);
	return (true);
}

int				main(int argc, char *argv[])
{
	t_game *game;

	game = NULL;
	if (argc != 2)
		return (print_usage());
	else
	{
		if (!(game = (t_game *)malloc(sizeof(t_game))))
			return (false);
		if (!(init_game(game, argv[1])))
			print_error(game, ERROR_INIT_GAME);
		mainloop(game);
	}
	return (true);
}
