/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 13:06:03 by cbruno            #+#    #+#             */
/*   Updated: 2019/01/21 13:06:08 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		vector_add(float dest[3], float src[3])
{
	dest[0] += src[0];
	dest[1] += src[1];
	dest[2] += src[2];
}
