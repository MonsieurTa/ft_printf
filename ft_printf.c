/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 09:38:55 by wta               #+#    #+#             */
/*   Updated: 2018/11/23 06:44:01 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_convert_type(t_lpf *node, char type, va_list ap)
{
	char	*output;

	output = NULL;
	if (type == '%')
		if (!(output = ft_convert_per(type, node)))
			return (NULL);
	if (type == 's')
		if (!(output = ft_convert_s(va_arg(ap, char*), node)))
			return (NULL);
	if (type == 'c')
		if (!(output = ft_convert_c(va_arg(ap, int), node)))
			return (NULL);
	if (type == 'p')
		if (!(output = ft_convert_p(va_arg(ap, unsigned long), node)))
			return (NULL);
	if (type == 'd' || type == 'i')
		if (!(output = ft_convert_d(va_arg(ap, int), node)))
			return (NULL);
	return (output);
}

int		ft_parse_pf(t_lpf **lpf, char *fmt, va_list ap, int *index)
{
	t_lpf	*node;
	char	type;
	
	node = NULL;
	if (!(node = ft_pf_new()))
		return (0);
	if (!(type = ft_parse_flag(node, fmt, index)))
		return (0);
	if (!(node->str = ft_convert_type(node, type, ap)))
		return (0);
	(*index)++;
	node->ret = ft_strlen(node->str);
	lpf = ft_lpf_append(lpf, node);
	return (1);
}

int		ft_get_str_pf(t_lpf **lpf, const char *fmt, int index)
{
	t_lpf	*node;
	int		nindex;

	node = NULL;
	nindex = index;
	if (!(node = ft_pf_new()))
		return (0);
	while (fmt[nindex] && fmt[nindex] != '%')
		nindex++;
	if (!(node->str = ft_strndup(&fmt[index], nindex - index)))
		free(node);
	node->ret = ft_strlen(node->str);
	lpf = ft_lpf_append(lpf, node);
	return (nindex);
}

int		ft_printf(const char *fmt, ...)
{
	t_lpf		*lpf;
	va_list		ap;
	int			index;
	int			ret;

	lpf = NULL;
	index = 0;
	ret = 0;
	va_start(ap, fmt);
	while (fmt[index])
	{
		if (fmt[index] == '%')
		{
			index++;
			if (!ft_parse_pf(&lpf, (char*)fmt, ap, &index))
				return (0);
		}
		index = ft_get_str_pf(&lpf, fmt, index);
	}
	va_end(ap);
	ft_print_all(lpf, &ret);
	return (ret);
}
