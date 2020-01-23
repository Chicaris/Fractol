/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 09:46:16 by cbruno            #+#    #+#             */
/*   Updated: 2019/01/24 16:12:41 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_bool		init_image(t_game *game)
{
	t_image		self;

	self.bpp = 0;
	self.size_x = 0;
	self.endian = 0;
	if (!(self.img_ptr = mlx_new_image(game->graphic.mlx_ptr, WIDTH, HEIGHT)))
		return (false);
	if (!(self.img = mlx_get_data_addr(self.img_ptr, &(self.bpp),
					&(self.size_x), &(self.endian))))
		return (false);
	game->image = self;
	return (true);
}
