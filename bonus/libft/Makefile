# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/31 11:45:32 by cado-car          #+#    #+#              #
#    Updated: 2021/07/31 11:45:32 by cado-car         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a 

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
LIB			= ar -rcs
LIB1		= ranlib
RM			= /bin/rm -f

INCS		= libft.h
SRCS		= ft_strlen.c ft_memcpy.c ft_strlcpy.c ft_strchr.c ft_strdup.c \
			ft_strjoin.c ft_itoa.c ft_putchar.c ft_uitoa_base.c ft_isdigit.c \
			ft_appendchr.c ft_isascii.c ft_isprint.c ft_strlcat.c ft_memset.c

OBJS		= $(SRCS:.c=.o)

all: 		$(NAME)

$(NAME):	$(OBJS) $(INCS)
			$(LIB)	$(NAME) $(OBJS)
			$(LIB1) $(NAME)

.c.o: 		
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean:		
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
