/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 05:56:16 by wta               #+#    #+#             */
/*   Updated: 2018/11/23 14:31:18 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_itoa_pf(long long n, char *output, int *maxl, t_lpf *node)
{
	while (n)
	{
		output[--(*maxl)] = ft_abs(n % 10) + '0';
		n /= 10;
	}
	return (output);
}
/*
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
*/
int		ft_maxlen(long long n, t_lpf *node, int *nbrlen, int offset)
{
	*nbrlen = ft_intlen_base(n, 10);
	if (node->acc > *nbrlen && node->acc > node->width)
		return (node->acc + offset);
	else if (node->width > node->acc && *nbrlen < node->width)
		return (node->width);
	return (*nbrlen);
}

char		*ft_convert_d(long long n, t_lpf *node)
{
	char	*output;
	int		offset;
	int		nbrlen;
	int		maxl;
	int		i;

	offset = (n < 0) || (node->flag & PLUS) || (node->flag & SPACE);
	maxl = ft_maxlen(n, node, &nbrlen, offset);
	if (!(output = ft_strnew(maxl)))
		return (NULL);
	output = ft_itoa_pf(n, output, &maxl, node);
		i = maxl;
		while (i > node->acc)
			output[i--] = '0';
		if (n < 0)
			output[i] = '-';
		else if (node->flag & PLUS)
			output[i] = '+';
		else if (node->flag & SPACE)
			output[i] = ' ';
	if ((node->flag & MINUS) && (node->width + node->acc) / 2 > nbrlen - offset)
	{
		output = ft_memmove(output, &output[maxl - i],);
	}
	else
		while (i)
			output[--i] = '0';




	/*
	if (node->acc > nbrlen)
	{
		i = maxl - node->acc;
		if (n < 0)
			output[i - offset] = '-';
		else if (node->flag & PLUS)
			output[i - offset] = '+';
		else if (node->flag & SPACE)
			output[i - offset] = ' ';
		while (i < maxl - nbrlen + offset)
			output[i++] = '0';
	}
	if ()
	*/
	return (output);
}
