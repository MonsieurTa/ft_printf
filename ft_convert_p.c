/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 02:16:52 by wta               #+#    #+#             */
/*   Updated: 2018/11/23 02:36:52 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_plen(unsigned long ptr)
{
	int	len;

	len = (ptr == 0) ? 3 : 2;
	while (ptr)
	{
		len++;
		ptr /= 16;
	}
	return (len);
}

static char	*ft_ptoa(unsigned long ptr)
{
	char	*output;
	int		mod;
	int		len;

	output = NULL;
	len = ft_plen(ptr);
	if (!(output = ft_strnew(len)))
		return (NULL);
	output[0] = '0';
	output[1] = 'x';
	while (--len > 1)
	{
		mod = ptr % 16;
		output[len] = (mod > 9) ? 'a' + (mod % 10) : mod + '0';
		ptr /= 16;
	}
	return (output);
}

char	*ft_convert_p(unsigned long ptr, t_lpf *node)
{
	char	*output;
	int		len;

	output = NULL;
	if (!(output = ft_ptoa(ptr)))
		return (NULL);
	len = ft_strlen(output);
	if (node->width > len && node->flag & MINUS)
	{
		if (!(output = ft_strjoinfree(output, ft_strspace(node->width - len))))
			return (NULL);
	}
	else if (node->width > len)
		if (!(output = ft_strjoinfree(ft_strspace(node->width - len), output)))
			return (NULL);
	return (output);
}
