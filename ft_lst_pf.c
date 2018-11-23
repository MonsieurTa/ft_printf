/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_pf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 01:12:30 by wta               #+#    #+#             */
/*   Updated: 2018/11/23 01:14:06 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_all(t_lpf *lpf, int *ret)
{
	t_lpf	*elem;

	if (lpf)
	{
		elem = lpf;
		while (elem)
		{
			ft_putstr(elem->str);
			*ret += elem->ret;
			elem = elem->next;
		}
	}
}

t_lpf	*ft_pf_new()
{
	t_lpf	*new;
	if (!(new = (t_lpf*)malloc(sizeof(t_lpf))))
		return (NULL);
	new->next = NULL;
	new->flag = 0;
	new->width = 0;
	new->acc = 0;
	new->ret = 0;
	new->str = NULL;
	return (new);
}

t_lpf	**ft_lpf_append(t_lpf **lpf, t_lpf *node)
{
	t_lpf	*elem;

	elem = NULL;
	if (*lpf)
	{
		elem = *lpf;
		while (elem->next)
			elem = elem->next;
		elem->next = node;
	}
	else
		*lpf = node;
	return (lpf);
}
