# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/03 14:20:18 by msavelie          #+#    #+#              #
#    Updated: 2024/08/06 16:31:18 by msavelie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC_DIR = ./srsc

SRCS = \
	${SRC_DIR}/main.c \
	${SRC_DIR}/check_map.c \
	${SRC_DIR}/free_map.c \
	${SRC_DIR}/parse_map.c \
	${SRC_DIR}/convert_map.c \
	${SRC_DIR}/free_arr.c \
	${SRC_DIR}/map_to_mlx.c \
	${SRC_DIR}/draw_line.c

OBJS = ${SRCS:.c=.o}

CFLAGS = -g -Wall -Werror -Wextra

LIBFT_NAME = ./libft/libft.a
LIBFT_DIR = ./libft

MLX_DIR = ./MLX42/build

RM = rm -rf
AR = ar -rcs
LIB = ranlib

.PHONY = all clean fclean re

all: ${LIBFT_NAME} ${NAME}

${LIBFT_NAME}:
	@make -C ${LIBFT_DIR}

${NAME}: ${OBJS}
	@cp ${LIBFT_DIR}/libft.a .
	@cp ${MLX_DIR}/libmlx42.a .
	@gcc ${CFLAGS} ${OBJS} libft.a libmlx42.a -ldl -lglfw -pthread -lm -o ${NAME}

%.o: %.c
	gcc $(CFLAGS) -Iinclude -c $< -o $@

clean: 
	@${RM} ${OBJS}
	@make clean -C ${LIBFT_DIR}

fclean: clean
	@${RM} ${NAME}
	@make fclean -C ${LIBFT_DIR}
	@${RM} libft.a
	@${RM} libmlx42.a

re: fclean all