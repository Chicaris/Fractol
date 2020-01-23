/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 12:07:09 by cbruno            #+#    #+#             */
/*   Updated: 2019/01/24 16:27:19 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void		key_bis(t_game *self, int key)
{
	if (key == KEY_LEFT)
		self->x += 50;
	if (key == KEY_RIGHT)
		self->x -= 50;
	if (key == KEY_UP)
		self->y += 50;
	if (key == KEY_DOWN)
		self->y -= 50;
}

int				deal_key(int key, void *param)
{
	t_game		*self;

	self = (t_game *)param;
	if (key == KEY_ESC)
		free_all(self);
	if (key == KEY_PLUS)
		zoom_in(self, 1.1);
	if (key == KEY_MINUS)
		zoom_out(self, 1.1);
	if (key == KEY_A)
		self->fractal.iter_max *= 1.25;
	if (key == KEY_Q)
		self->fractal.iter_max /= 1.25;
	if (key == KEY_P)
		if (ft_strcmp(self->file, "Julia") == 0)
			julia_change(self);
	if (key == KEY_C)
		self->color_value += 1;
	key_bis(self, key);
	paint(self);
	return (0);
}
