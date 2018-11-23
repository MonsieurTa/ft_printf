/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_per.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 05:26:30 by wta               #+#    #+#             */
/*   Updated: 2018/11/23 08:53:20 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_convert_per(int c, t_lpf *node)
{
	char	*output;

	output = NULL;
	if (!(output = ft_strnew(1)))
		return (NULL);
	output[0] = (char)c;
	if (node->width > 1 && node->flag & MINUS)
	{
		if (!(output = ft_strjoinfree(output, ft_strspace(node->width - 1))))
			return (NULL);
	}
	else if (node->width > 1)
	{
		if (node->flag & ZERO)
		{
			if (!(output = ft_strjoinfree(ft_strzero(node->width - 1), output)))
				return (NULL);
		}
		else if (!(output = ft_strjoinfree(
		ft_strspace(node->width - 1), output)))
			return (NULL);
	}
	return (output);
}
