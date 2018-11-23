/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 09:35:40 by wta               #+#    #+#             */
/*   Updated: 2018/11/23 06:40:39 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include <stdarg.h>
# include <stdio.h>
# define SHARP		1
# define ZERO		1 << 1
# define MINUS		1 << 2
# define SPACE		1 << 3
# define PLUS		1 << 4
# define CHAR		1 << 5
# define SHORT		1 << 6
# define LONG		1 << 7
# define LLONG		1 << 8
# define OCTAL		1 << 9
# define HEX_L		1 << 10
# define HEX_U		1 << 11
# define HEX_PTR	1 << 12
# define LDOUBLE	1 << 13

typedef struct	s_lpf
{
	struct s_lpf	*next;
	int				flag;
	int				width;
	int				acc;
	int				ret;
	char			*str;
}				t_lpf;

int		ft_printf(const char *fmt, ...);

void	ft_print_all(t_lpf *lpf, int *ret);
t_lpf	*ft_pf_new(void);
t_lpf	**ft_lpf_append(t_lpf **lpf, t_lpf *node);
int		ft_parse_mod(t_lpf *node, char *fmt);
char	ft_parse_flag(t_lpf *node, char *fmt, int *index);
int		ft_is_arg(char c);
char	*ft_strspace(int len);
char	*ft_strzero(int len);
char	*ft_convert_s(char *str, t_lpf *node);
char	*ft_convert_c(int c, t_lpf *node);
char	*ft_convert_p(unsigned long ptr, t_lpf *node);
char	*ft_convert_per(int c, t_lpf *node);
char	*ft_convert_d(long long n, t_lpf *node);

int		ft_abs(long long n);

#endif
