# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/12 22:24:42 by cado-car          #+#    #+#              #
#    Updated: 2021/08/13 10:18:03 by cado-car         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
LIB			= ar -rcs
LIB1		= ranlib
RM			= /bin/rm -f

LIBFT_DIR	= ./libft
LIBFT		= $(LIBFT_DIR)/libft.a

INC_DIR		= ./include

SRC_DIR		= ./srcs
SRCS		= $(SRC_DIR)/ft_conversion.c \
			$(SRC_DIR)/ft_convert_c.c \
			$(SRC_DIR)/ft_convert_d_i.c \
			$(SRC_DIR)/ft_convert_p.c \
			$(SRC_DIR)/ft_convert_pct.c \
			$(SRC_DIR)/ft_convert_s.c \
			$(SRC_DIR)/ft_convert_ux.c \
			$(SRC_DIR)/ft_initialize.c \
			$(SRC_DIR)/ft_parse.c \
			$(SRC_DIR)/ft_placeholder.c \
			$(SRC_DIR)/ft_printf.c

OBJS		= $(SRCS:.c=.o)

HEADER		= -I$(INC_DIR) -I$(LIBFT_DIR)
LFLAGS		= -L$(LIBFT_DIR) -lft

all:		$(NAME)

$(NAME):	$(OBJS) $(LIBFT)
			$(LIB)	$(NAME) $(OBJS)
			$(LIB1) $(NAME)

.c.o: 		
			$(CC) $(CFLAGS) $(HEADER) $(LFLAGS) -c $< -o $(<:.c=.o)

$(LIBFT):
			make -C $(LIBFT_DIR)

clean:
			make clean -C $(LIBFT_DIR)
			$(RM) $(OBJS)

fclean:		clean
			make fclean -C $(LIBFT_DIR)
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re