/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 01:15:37 by wta               #+#    #+#             */
/*   Updated: 2018/11/23 06:02:02 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_is_arg(char c)
{
	char	buf[] = "%cspdiouxXf";
	int		i;

	i = -1;
	while (buf[++i])
		if (buf[i] == c)
			return (1);
	return (0);
}

char	*ft_strspace(int len)
{
	char	*new;
	int		i;

	new = NULL;
	if (!(new = ft_strnew(len)))
		return (NULL);
	i = -1;
	while (++i < len)
		new[i] = ' ';
	return (new);
}

char	*ft_strzero(int len)
{
	char	*new;
	int		i;

	new = NULL;
	if (!(new = ft_strnew(len)))
		return (NULL);
	i = -1;
	while (++i < len)
		new[i] = '0';
	return (new);
}

int		ft_abs(long long n)
{
	return (n < 0 ? -n : n);
}
