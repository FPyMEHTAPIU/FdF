# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/03 14:20:18 by msavelie          #+#    #+#              #
#    Updated: 2024/07/30 20:21:43 by msavelie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCS = \
	main.c \
	check_map.c \
	free_map.c \
	parse_map.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Werror -Wextra

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
	@gcc -g $(CFLAGS) $(OBJS) libft.a libmlx42.a -Iinclude -ldl -lglfw -pthread -lm -o $(NAME)

clean: 
	@${RM} ${OBJS}
	@make clean -C ${LIBFT_DIR}

fclean: clean
	@${RM} ${NAME}
	@make fclean -C ${LIBFT_DIR}
	@${RM} libft.a
	@${RM} libmlx42.a

re: fclean all