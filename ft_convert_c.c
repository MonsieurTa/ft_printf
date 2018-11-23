/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 01:52:03 by wta               #+#    #+#             */
/*   Updated: 2018/11/23 02:10:57 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_convert_c(int c, t_lpf *node)
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
	else if (node->width > 1
	&& !(output = ft_strjoinfree(ft_strspace(node->width - 1), output)))
		return (NULL);
	return (output);
}
