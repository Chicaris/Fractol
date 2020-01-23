/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 12:06:45 by cbruno            #+#    #+#             */
/*   Updated: 2019/01/24 12:08:51 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

unsigned int	get_color(t_game *game, int a)
{
	unsigned int	c;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	if (a == game->fractal.iter_max)
		return (game->color_max);
	r = (a * 5) * game->color_value;
	g = (255 - (a * 10)) * game->color_value;
	b = (255 - (a * 2)) * game->color_value;
	c = (r << 16) + (g << 8) + b;
	return (c);
}
