/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 13:35:13 by cbruno            #+#    #+#             */
/*   Updated: 2019/01/24 13:47:05 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void			put_pxl(t_game *game, int x, int y, unsigned int color)
{
	int		i;

	i = (x * 4) + (y * game->image.size_x);
	if (y > 120 && y < HEIGHT - 200)
	{
		game->image.img[i] = color;
		game->image.img[++i] = color >> 8;
		game->image.img[++i] = color >> 16;
	}
}

void			paint(t_game *game)
{
	mlx_destroy_image(game->graphic.mlx_ptr, game->image.img_ptr);
	mlx_clear_window(game->graphic.mlx_ptr, game->graphic.win_ptr);
	if (!init_image(game))
		free_all(game);
	game->function(game);
	show_menu(game);
}
