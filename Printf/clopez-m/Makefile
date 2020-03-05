# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clopez-m <clopez-m@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/10 18:20:04 by clopez-m          #+#    #+#              #
#    Updated: 2020/02/10 18:20:07 by clopez-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

CFLAGS = -Werror -Wextra -Wall

PRINTF_SRC = ft_printf.c	ft_start_process.c	ft_reset_struct.c	ft_check_modifiers.c	\
				ft_print_string.c	ft_print_character.c	ft_print_integer.c		\
				ft_print_unsigned_integer.c	ft_print_hex.c		ft_print_ptr.c			\
				ft_printf_utils.c ft_print_percentage.c								\

LIB_PATH = libft/

LIB_SRC = ft_strlen.c		ft_strchr.c		ft_isdigit.c					\
		  ft_itoa.c			ft_strdup.c								\
		  ft_strcpy.c		ft_uitoa.c		ft_ndigits_base.c	ft_itoa_base.c	\

PRINTF_SRC += $(addprefix $(LIB_PATH), $(LIB_SRC))
OBJ = $(PRINTF_SRC:.c=.o)

$(NAME):	$(OBJ)
	$(CC) $(CFLAGS) -c $(PRINTF_SRC)
	ar rc $(NAME) $(notdir $(OBJ))
	ranlib $(NAME)

all: $(NAME)

clean: $(OBJ)
	rm -rf $(notdir $(OBJ))
	$(MAKE) -C libft clean

fclean: clean
	rm -rf $(NAME)
	$(MAKE) -C $(LIB_PATH) fclean

re: fclean all
