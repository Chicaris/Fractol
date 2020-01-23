/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 09:39:02 by cbruno            #+#    #+#             */
/*   Updated: 2019/01/24 12:31:45 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_bool		init_graphic(t_game *game)
{
	t_graphic	self;

	self.title = "Fractol";
	self.x_center = WIDTH / 2;
	self.y_center = HEIGHT / 2;
	self.x_min = -self.x_center;
	self.x_max = self.x_center;
	self.y_min = -self.y_center + 200;
	self.y_max = self.y_center - 120;
	if (!(self.mlx_ptr = mlx_init()))
		print_error(game, ERROR_MLX_INIT);
	if (!(self.win_ptr = mlx_new_window(self.mlx_ptr,
					WIDTH, HEIGHT, self.title)))
		print_error(game, ERROR_NEW_WIN);
	game->graphic = self;
	return (true);
}

void		mainloop(t_game *game)
{
	paint(game);
	mlx_key_hook(game->graphic.win_ptr, deal_key, game);
	mlx_hook(game->graphic.win_ptr, MOUSEPRESS, 0, mouse_press, game);
	mlx_hook(game->graphic.win_ptr, MOUSERELEASE, 0, mouse_release, game);
	mlx_hook(game->graphic.win_ptr, MOUSEMOVE, 0, mouse_move, game);
	mlx_loop(game->graphic.mlx_ptr);
}
