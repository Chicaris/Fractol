/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_cross.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 12:59:59 by cbruno            #+#    #+#             */
/*   Updated: 2019/01/21 13:00:01 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		vector_cross(float dest[3], float a[3], float b[3])
{
	dest[0] = a[1] * b[2] - a[2] * b[1];
	dest[1] = a[2] * b[0] - a[0] * b[2];
	dest[2] = a[0] * b[1] - a[1] * b[0];
}
