# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wta <wta@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/28 20:09:26 by wta               #+#    #+#              #
#    Updated: 2018/11/25 16:08:02 by wta              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a
SRCS	=	ft_atoi.c		ft_bzero.c		ft_intlen_base.c				\
			ft_isalnum.c	ft_isalpha.c	ft_isascii.c	ft_isdigit.c	\
			ft_isprint.c	ft_itoa.c		ft_lstadd.c		ft_lstappend.c	\
			ft_lstdel.c		ft_lstdelone.c	ft_lstiter.c	ft_lstmap.c		\
			ft_lstnew.c		ft_memalloc.c	ft_memccpy.c	ft_memchr.c		\
			ft_memcmp.c		ft_memcpy.c		ft_memdel.c		ft_memmove.c	\
			ft_memset.c		ft_putchar.c	ft_putchar_fd.c	ft_putendl.c	\
			ft_putendl_fd.c	ft_putnbr.c		ft_putnbr_fd.c	ft_putstr.c		\
			ft_putstr_fd.c	ft_strcat.c		ft_strchr.c		ft_strclr.c		\
			ft_strcmp.c		ft_strcpy.c		ft_strdel.c		ft_strdup.c		\
			ft_strdupdel.c	ft_strequ.c		ft_striter.c	ft_striteri.c	\
			ft_strjoin.c	ft_strjoindel.c	ft_strlcat.c	ft_strlen.c		\
			ft_strmap.c		ft_strmapi.c	ft_strncat.c	ft_strncmp.c	\
			ft_strncpy.c	ft_strnequ.c	ft_strnew.c		ft_strnstr.c	\
			ft_strrchr.c	ft_strsplit.c	ft_strstr.c		ft_strsub.c		\
			ft_strtrim.c	ft_tolower.c	ft_toupper.c	ft_wdcpy.c		\
			ft_word_count.c	ft_word_len.c	get_next_line.c	ft_strndup.c	\
			ft_strjoinfree.c	ft_strndupfree.c

OBJ		=	$(SRCS:.c=.o)
CC		=	gcc 
CFLAGS	=	-Wall -Wextra -Werror

all		:	$(NAME)

$(NAME)	:	$(OBJ)
	ar -rcs $(NAME) $(OBJ)

%.o		:	%.c ./libft.h
	$(CC) $(CFLAGS) -o $@ -c $<

clean	:
	rm -f $(OBJ)

fclean	:	clean
	rm -f	$(NAME)

re		:	fclean all
