# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/03 14:20:18 by msavelie          #+#    #+#              #
#    Updated: 2024/06/03 17:13:59 by msavelie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCS = \
	fdf.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Werror -Wextra

LIBFT_NAME = ./libft/libft.a
LIBFT_DIR = ./libft

MLX_NAME = ./mlx/libmlx.a
MLX_DIR = ./mlx

RM = rm -rf
AR = ar -rcs
LIB = ranlib

.PHONY = all clean fclean re

all: ${LIBFT_NAME} ${MLX_NAME} ${NAME}

${LIBFT_NAME}:
	make -C ${LIBFT_DIR}

${MLX_NAME}:
	make -C ${MLX_DIR}

${NAME}: ${OBJS}
	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	cp ${LIBFT_DIR}/libft.a .
	mv libft.a ${NAME}
	cp ${MLX_DIR}/libmlx.a .
	mv libmlx.a ${NAME}
	${AR} ${NAME} ${OBJS}
	${LIB} ${NAME}

clean: 
	${RM} ${OBJS}
	make clean -C ${LIBFT_DIR}
	make clean -C ${MLX_DIR}

fclean: clean
	${RM} ${NAME}
	make fclean -C ${LIBFT_DIR}

re: fclean all

%.o : %.c
	cc ${CFLAGS} -Imlx -c $< -o $@
