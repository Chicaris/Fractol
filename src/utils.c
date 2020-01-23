/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 13:25:34 by cbruno            #+#    #+#             */
/*   Updated: 2019/01/24 16:22:56 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	zoom_in(t_game *game, float zoom)
{
	game->zoom *= zoom;
	game->x *= zoom;
	game->y *= zoom;
	game->x += WIDTH / 20;
	game->y += HEIGHT / 20;
	game->fractal.iter_max += 2;
}

void	zoom_out(t_game *game, float zoom)
{
	game->zoom /= zoom;
	game->x /= zoom;
	game->y /= zoom;
	game->x -= WIDTH / 20;
	game->y -= HEIGHT / 20;
	game->fractal.iter_max -= 2;
}
