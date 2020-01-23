/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_rotation_y.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 13:18:42 by cbruno            #+#    #+#             */
/*   Updated: 2019/01/21 13:30:10 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	get_rotate_y(float dst[4][4], float angle)
{
	matrix_unit(dst);
	dst[0][0] = cos(angle);
	dst[2][2] = dst[0][0];
	dst[0][2] = sin(angle);
	dst[2][0] = -dst[0][2];
}
