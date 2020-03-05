# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clopez-m <clopez-m@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/24 14:43:03 by clopez-m          #+#    #+#              #
#    Updated: 2020/03/05 16:04:58 by clopez-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cube3d.a
SRC = ft_atoi.c ft_bzero.c  ft_calloc.c ft_isalnum.c    \
ft_isalpha.c    ft_isascii.c    ft_isdigit.c    ft_isprint.c    \
ft_itoa.c   ft_memccpy.c    ft_memchr.c ft_memcmp.c \
ft_memcpy.c ft_memmove.c    ft_memset.c ft_putchar_fd.c \
ft_putendl_fd.c ft_putnbr_fd.c  ft_putstr_fd.c  ft_split.c  \
ft_strchr.c ft_strdup.c ft_strjoin.c    ft_strlcat.c    \
ft_strlcpy.c    ft_strlen.c ft_strmapi.c    ft_strncmp.c    \
ft_strnstr.c    ft_strrchr.c    ft_strtrim.c    ft_substr.c \
ft_tolower.c    ft_toupper.c
SRCBONUS =  ft_lstadd_back_bonus.c  ft_lstadd_front_bonus.c ft_lstclear_bonus.c \
ft_lstdelone_bonus.c    ft_lstiter_bonus.c  ft_lstlast_bonus.c  \
ft_lstmap_bonus.c   ft_lstnew_bonus.c   ft_lstsize_bonus.c
SRCGNL = get_next_line.c gnl/get_next_line_utils.c
SRCCUBE = cube3d.c auxiliar.c checker.c convert_handler.c \
draw.c initiate.c key_handler.c raycast.c second_auxiliar.c
SRCMINI= mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c
SRCMINI+= mlx_png.c mlx_mouse.m
CC = gcc -Wall -Wextra -Werror
RM = rm -f
all: $(NAME)
$(NAME): 
	${CC} libft/libft.a gnl/${SRCGNL} minilibx/libmlx.a ${SRCCUBE} -framework OpenGL -framework AppKit -o CUBE3D
bonus:
	${CC} libft/libft.a gnl/${SRCGNL} minilibx/libmlx.a ${SRCCUBE} -framework OpenGL -framework AppKit -o CUBE3D
fclean:
	${RM} ${OBJ} ${OBJBONUS}
	${RM} ${NAME} ${OBJBONUS}
clean:
	${RM} ${OBJ} ${OBJBONUS}
re: fclean all
.PHONY: all clean fclean re bonus