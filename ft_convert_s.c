/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 01:16:45 by wta               #+#    #+#             */
/*   Updated: 2018/11/23 03:29:03 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_convert_s(char *str, t_lpf *node)
{
	char	*output;
	int		len;

	if (str == NULL)
		return (ft_strdup("(null)"));
	output = NULL;
	if (!(output = ft_strdup(str)))
		return (NULL);
	len = ft_strlen(output);
	if (node->acc > 0 && node->acc < len
		&& !(output = ft_strndupfree(output, node->acc)))
			return (NULL);
	len = (output) ? ft_strlen(output) : len;
	if (node->width > len && node->flag & MINUS)
	{
		if (!(output = ft_strjoinfree(output, ft_strspace(node->width - len))))
			return (NULL);
	}
	else if (node->width > len
	&& !(output = ft_strjoinfree(ft_strspace(node->width - len), output)))
		return (NULL);
	else if (!output && !(output = ft_strdup(str)))
		return (NULL);
	return (output);
}
