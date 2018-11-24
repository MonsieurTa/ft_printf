# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wta <marvin@42.fr>                         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/22 09:43:49 by wta               #+#    #+#              #
#    Updated: 2018/11/24 14:51:40 by wta              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

SRC		=	ft_printf.c			ft_convert_c.c		ft_convert_p.c			\
			ft_convert_s.c		ft_lst_pf.c			ft_parse_pf.c			\
			ft_utils.c			ft_convert_per.c	ft_convert_d.c			\
			ft_convert_u.c		ft_convert_o.c		ft_convert_hex.c		\
			libft/ft_atoi.c		libft/ft_isdigit.c	ft_convert_f.c			\
			libft/ft_putstr.c	libft/ft_strdup.c	libft/ft_strjoinfree.c	\
			libft/ft_strlen.c	libft/ft_strndup.c	libft/ft_intlen_base.c	\
			libft/ft_strndupfree.c	libft/ft_strncpy.c						\
			libft/ft_strnew.c	libft/ft_strcat.c	libft/ft_strcpy.c		\
			libft/ft_memcpy.c	libft/ft_strdel.c

INC		=	./ft_printf.h

OBJ		=	$(SRC:.c=.o)

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

all		:	$(NAME)

$(NAME)	:	$(OBJ)
	$(MAKE) -C libft
	ar -rcs $(NAME) $(OBJ)

%.o		:	%.c	./ft_printf.h	./Makefile
	$(CC) $(CFLAGS) -o $@ -c $<

clean	:
	$(MAKE) -C libft clean
	rm -f	$(OBJ)

fclean	: clean
	$(MAKE) -C libft fclean
	rm -f	$(NAME)

re		:	fclean all
