/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 05:56:16 by wta               #+#    #+#             */
/*   Updated: 2018/11/23 10:27:58 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_itoa_pf(long long n, t_lpf *node)
{
	char	*str;
	int		sign;
	int		len;

	sign = (n < 0);
	len = ft_intlen_base(n, 10);
	if (n >= 0)
		len += ((node->flag & PLUS) > 0) || ((node->flag & SPACE) > 0);
	if (!(str = ft_strnew(len)))
		return (NULL);
	while (len > 1)
	{
		str[--len] = ft_abs(n % 10) + '0';
		n /= 10;
	}
	if (!sign && (node->flag & PLUS) > 0)
		str[0] = '+';
	else if (!sign && (node->flag & SPACE) > 0)
		str[0] = ' ';
	else
		str[0] = (sign) ? '-' : n % 10 + '0';
	return (str);
}

char		*ft_acc_filler(char *str, t_lpf *node)
{
	char	*output;
	int		len;
	int		gap;
	int		i;
	int		j;

	len = ft_strlen(str);
	if ((gap = node->acc - (len - (!ft_isdigit(str[0])))) == 0)
		return (str);
	if (!(output = ft_strnew((len + gap))))
		return (NULL);
	if (!(ft_isdigit(str[0])))
		output[0] = str[0];
	i = -1;
	while (++i < gap)
		output[!ft_isdigit(str[0]) + i] = '0';
	j = !ft_isdigit(str[0]) - 1;
	while (str[++j])
		output[!ft_isdigit(str[0]) + i++] = str[j];
	free(str);
	return (output);
}

char		*ft_convert_d(long long n, t_lpf *node)
{
	char	*output;
	output = NULL;
	return (output);
}
