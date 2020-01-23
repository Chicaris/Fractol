/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 10:40:55 by cbruno            #+#    #+#             */
/*   Updated: 2019/01/24 16:12:02 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void			free_all(t_game *game)
{
	if (game->file != NULL)
		free(game->file);
	if (game->image.img != NULL)
		mlx_destroy_image(game->graphic.mlx_ptr, game->image.img_ptr);
	free(game);
	exit(0);
}
