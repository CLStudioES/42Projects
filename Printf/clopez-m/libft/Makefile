# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clopez-m <clopez-m@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/10 18:14:13 by clopez-m          #+#    #+#              #
#    Updated: 2020/02/10 18:14:14 by clopez-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a

CC=gcc

CFLAGS+=-Werror -Wextra -Wall

SRC=ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c			\
	ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c		\
	ft_strcpy.c	ft_strlcpy.c ft_strlcat.c ft_strchr.c		\
	ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_isalpha.c		\
	ft_isupper.c ft_islower.c ft_isdigit.c ft_isalnum.c		\
	ft_isascii.c ft_isprint.c ft_isspace.c ft_toupper.c		\
	ft_tolower.c ft_atoi.c ft_calloc.c ft_strdup.c			\
	ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c		\
	ft_wordcnt.c ft_itoa.c ft_uitoa.c ft_strmapi.c			\
	ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c			\
	ft_putnbr_fd.c

SRC_BONUS=	ft_lstnew_bonus.c ft_lstadd_front_bonus.c		\
			ft_lstadd_back_bonus.c ft_lstsize_bonus.c 		\
			ft_lstlast_bonus.c ft_lstdelone_bonus.c 		\
			ft_lstclear_bonus.c ft_lstiter_bonus.c			\
			ft_lstmap_bonus.c

OBJ=$(SRC:.c=.o)

BONUS_OBJ=$(SRC_BONUS:.c=.o)

$(NAME):	$(OBJ)
	-@$(CC) $(CFLAGS) -c $(SRC)
	-@ar rc $(NAME) $(OBJ)
	-@ranlib $(NAME)

all: $(NAME)

clean:
	-@rm -rf $(OBJ)

fclean:	clean bclean
	-@rm -rf $(NAME)

bonus:	$(BONUS_OBJ) $(OBJ)
	-@$(CC) $(CFLAGS) -c $(SRC_BONUS) $(SRC)
	-@ar rc $(NAME) $(BONUS_OBJ) $(OBJ)
	-@ranlib $(NAME)

bclean:
	-@rm -rf $(BONUS_OBJ)

re:	fclean all
