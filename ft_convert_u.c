/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 06:06:10 by wta               #+#    #+#             */
/*   Updated: 2018/11/24 06:20:41 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_intlen_base_u(unsigned long long n, int base)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n)
	{
		len--;
		n /= base;
	}
	return (len);
}

static char	*ft_itoa_u(unsigned long long n, t_lpf *node)
{
	char	*output;
	int		len;

	output = NULL;
	len = ft_intlen_base_u(n, 10);
	len += ((node->flag & PLUS) || node->flag & SPACE);
	if (!(output = ft_strnew(len)))
		return (NULL);
}


char	*ft_convert_u(unsigned long long n, t_lpf *node)
{
	char	*str;

	str = NULL;
	return (str);
}
