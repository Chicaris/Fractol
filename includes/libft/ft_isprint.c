/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbruno <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 11:59:18 by cbruno            #+#    #+#             */
/*   Updated: 2018/10/04 11:38:34 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isprint(int c)
{
	int		res;

	res = 0;
	if (c >= 32 && c <= 126)
		res = 1;
	return (res);
}
