/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 13:15:33 by cbruno            #+#    #+#             */
/*   Updated: 2019/01/24 16:18:36 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void		show_line(t_graphic self, int y, char *str)
{
	int		i;

	i = 0;
	while (i <= WIDTH)
	{
		mlx_string_put(self.mlx_ptr, self.win_ptr, i, y, YELLOW, str);
		i++;
	}
}

void			show_menu(t_game *game)
{
	show_line(game->graphic, 0, "=");
	mlx_string_put(game->graphic.mlx_ptr, game->graphic.win_ptr, WIDTH / 2 - 60,
			50, YELLOW, "Project : Fractol");
	mlx_string_put(game->graphic.mlx_ptr, game->graphic.win_ptr, 10,
			HEIGHT - 185, YELLOW, "Press ESC to exit");
	mlx_string_put(game->graphic.mlx_ptr, game->graphic.win_ptr, 10,
			HEIGHT - 105, YELLOW,
			"Use QA to change the precision of the fractal");
	mlx_string_put(game->graphic.mlx_ptr, game->graphic.win_ptr, 10,
			HEIGHT - 85,
			YELLOW, "Press C to change color");
	mlx_string_put(game->graphic.mlx_ptr, game->graphic.win_ptr, 10,
			HEIGHT - 45,
			YELLOW, "Use the mouse or the arrow to move");
	mlx_string_put(game->graphic.mlx_ptr, game->graphic.win_ptr,
			WIDTH - 200,
			HEIGHT - 50, YELLOW, "By Bruno Cornil");
	show_line(game->graphic, 100, "=");
	show_line(game->graphic, HEIGHT - 200, "=");
	mlx_string_put(game->graphic.mlx_ptr, game->graphic.win_ptr, 10,
			HEIGHT - 125,
			YELLOW, "Use the scroll or + and - to zoom ");
}
