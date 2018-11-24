/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 05:56:16 by wta               #+#    #+#             */
/*   Updated: 2018/11/24 05:55:43 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_itoa_pf(long long n, t_lpf *node)
{
	char		*output;
	long long	nb;
	int			len;

	output = NULL;
	len = ft_intlen_base(n, 10);
	len += (n >= 0) ? ((node->flag & PLUS) || (node->flag & SPACE)) : 0;
	if (!(output = ft_strnew(len)))
		return (NULL);
	nb = n;
	while (len > 1)
	{
		len--;
		output[len] = ft_abs(n % 10) + '0';
		n /= 10;
	}
	if (nb >= 0 && node->flag & PLUS)
		output[0] = '+';
	else if (nb >= 0 && node->flag & SPACE)
		output[0] = ' ';
	else
		output[0] = (nb < 0) ? '-' : n % 10 + '0';
	return (output);
}

char	*ft_convert_acc(char *output, int len, t_lpf *node)
{
	char	*new;

	new = output;
	if (!ft_isdigit(output[0]))
	{
		if (!(new = ft_strinsert(output, ft_strzero(node->acc - len), 1)))
			return (NULL);
	}
	else
		if (!(new = ft_strjoinfree(ft_strzero(node->acc - len), output)))
			return (NULL);
	return (new);
}

char	*ft_format(char *output, int len, t_lpf *node)
{
	if (node->flag & MINUS)
	{
		if (!(output = ft_strjoinfree(output, ft_strspace(node->width - len))))
			return (NULL);
	}
	else if (node->flag & ZERO && node->acc == 0 && *output != '\0')
	{
		if (!(output = ft_strinsert(output, ft_strzero(node->width - len), !ft_isdigit(output[0]))))
			return (NULL);
	}
	else if (!(output = ft_strjoinfree(ft_strspace(node->width - len), output)))
		return (NULL);
	return (output);
}

char	*ft_convert_d(long long n, t_lpf *node)
{
	char	*output;
	int		len;

	output = NULL;
	if (node->flag & CHAR)
		n = (char)n;
	else if (node->flag & SHORT)
		n = (short)n;
	if (n == 0 && (node->flag & ACC) && node->acc == 0)
		output = ft_strdup("");
	else if (!(output = ft_itoa_pf(n, node)))
		return (NULL);
	len = ft_strlen(output);
	if (*output != '\0' && node->acc > len - (!ft_isdigit(output[0]))
	&& !(output = ft_convert_acc(output, len - !ft_isdigit(output[0]), node)))
		return (NULL);
	len = ft_strlen(output);
	if (node->width > len)
		output = ft_format(output, len, node);
	return (output);
}
