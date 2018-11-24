/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 09:38:55 by wta               #+#    #+#             */
/*   Updated: 2018/11/24 19:40:14 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_convert_type(t_lpf *node, va_list ap)
{
	char	*str;

	str = NULL;
	if (node->type == '%')
		if (!(str = ft_convert_per(node->type, node)))
			return (NULL);
	if (node->type == 's')
		if (!(str = ft_convert_s(va_arg(ap, char*), node)))
			return (NULL);
	if (node->type == 'c')
		if (!(str = ft_convert_c(va_arg(ap, int), node)))
			return (NULL);
	if (node->type == 'p')
		if (!(str = ft_convert_p(va_arg(ap, unsigned long), node)))
			return (NULL);

	if (node->type == 'd' || node->type == 'i')
	{
		if (node->flag & LLONG)
			if ((!(str = ft_convert_d(va_arg(ap, long long), node))))
				return (NULL);

		if (node->flag & LONG)
			if (!(str = ft_convert_d(va_arg(ap, long), node)))
				return (NULL);

		if (!(node->flag & LLONG) && !(node->flag & LONG)
				&& !(str = ft_convert_d(va_arg(ap, int), node)))
			return (NULL);
	}
	if (node->type == 'u')
	{
		if (node->flag & LLONG)
			if ((!(str = ft_convert_u(va_arg(ap, unsigned long long), node))))
				return (NULL);

		if (node->flag & LONG)
			if (!(str = ft_convert_u(va_arg(ap, unsigned long), node)))
				return (NULL);

		if (!(node->flag & LLONG) && !(node->flag & LONG)
				&& !(str = ft_convert_u(va_arg(ap, unsigned int), node)))
			return (NULL);

	}
	if (node->type == 'o')
	{
		if (node->flag & LLONG)
			if ((!(str = ft_convert_o(va_arg(ap, unsigned long long), node))))
				return (NULL);

		if (node->flag & LONG)
			if (!(str = ft_convert_o(va_arg(ap, unsigned long), node)))
				return (NULL);

		if (!(node->flag & LLONG) && !(node->flag & LONG)
				&& !(str = ft_convert_o(va_arg(ap, unsigned int), node)))
			return (NULL);

	}
	if (node->type == 'x' || node->type == 'X')
	{
		if (node->flag & LLONG)
			if ((!(str = ft_convert_hex(va_arg(ap, unsigned long long), node))))
				return (NULL);

		if (node->flag & LONG)
			if (!(str = ft_convert_hex(va_arg(ap, unsigned long), node)))
				return (NULL);

		if (!(node->flag & LLONG) && !(node->flag & LONG)
				&& !(str = ft_convert_hex(va_arg(ap, unsigned int), node)))
			return (NULL);

	}
	if (node->type == 'f')
	{
		if (node->flag & LLONG)
		{
			if ((!(str = ft_convert_f(va_arg(ap, long double), node))))
				return (NULL);

		}
		else
			if (!(str = ft_convert_f(va_arg(ap, double), node)))
				return (NULL);

	}
	return (str);
}

int		ft_parse_pf(t_lpf **lpf, char *fmt, va_list ap, int *index)
{
	t_lpf	*node;

	node = NULL;
	if (!(node = ft_pf_new()))
		return (0);
	if (!(node->type = ft_parse_flag(node, fmt, index)))
	{
		if (node->str)
			free(node->str);
		free(node);
		return (0);
	}
	if (!(node->str = ft_convert_type(node, ap)))
	{
		if (node->str)
			free(node->str);
		free(node);
		return (0);
	}
	(*index)++;
	node->ret += ft_strlen(node->str);
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
	t_lpf		*lst;
	va_list		ap;
	int			index;
	int			ret;

	lst = NULL;
	index = 0;
	ret = 0;
	va_start(ap, fmt);
	while (fmt[index])
	{
		if (fmt[index] == '%')
		{
			index++;
			if (!ft_parse_pf(&lst, (char*)fmt, ap, &index))
			{
				ft_rm_lst(lst);
				return (0);
			}
		}
		index = ft_get_str_pf(&lst, fmt, index);
	}
	va_end(ap);
	ft_print_all(lst, &ret);
	ft_rm_lst(lst);
	return (ret);
}
