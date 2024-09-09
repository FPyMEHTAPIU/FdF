# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/03 14:20:18 by msavelie          #+#    #+#              #
#    Updated: 2024/09/09 10:28:41 by msavelie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

NAME = fdf

SRC_DIR = ./srcs

SRCS = \
	${SRC_DIR}/main.c \
	${SRC_DIR}/check_map.c \
	${SRC_DIR}/free_ret.c \
	${SRC_DIR}/parse_map.c \
	${SRC_DIR}/convert_map.c \
	${SRC_DIR}/map_to_mlx.c \
	${SRC_DIR}/draw_line.c \
	${SRC_DIR}/to_2d.c \
	${SRC_DIR}/calculate_colors.c \
	${SRC_DIR}/set_colors.c \
	${SRC_DIR}/actions.c \
	${SRC_DIR}/rotate.c \
	${SRC_DIR}/point_handle.c \
	${SRC_DIR}/gui.c \
	${SRC_DIR}/hooks.c

OBJS = ${SRCS:.c=.o}

CFLAGS = -g -Wall -Werror -Wextra -Wpedantic

LIBFT_NAME = ./libft/libft.a
LIBFT_DIR = ./libft

MLX_DIR = ./MLX42/build

RM = rm -rf
AR = ar -rcs
LIB = ranlib

.PHONY = all clean fclean re

all: ${LIBFT_NAME} ${NAME}

${LIBFT_NAME}:
	@echo "$(CYAN)🛠  Compiling libft... 🛠$(DEF_COLOR)"
	@make -C ${LIBFT_DIR} --no-print-directory

${NAME}: ${OBJS}
	@echo "$(MAGENTA)🗂  Copying libft 🗂$(DEF_COLOR)"
	@cp ${LIBFT_DIR}/libft.a .
	@echo "$(MAGENTA)🗂  Copying mlx 🗂$(DEF_COLOR)"
	@cp ${MLX_DIR}/libmlx42.a .
	@echo "$(BLUE)🛠  Compiling FdF... 🛠$(DEF_COLOR)"
	@cc ${CFLAGS} ${OBJS} libft.a libmlx42.a -ldl -lglfw -pthread -lm -o ${NAME}
	@echo "$(GREEN)🥳 Success!🥳$(DEF_COLOR)"

%.o: %.c
	@cc $(CFLAGS) -Iinclude -c $< -o $@

clean:
	@echo "$(YELLOW)🚽 Deleting object files... 🚽$(DEF_COLOR)"
	@${RM} ${OBJS}
	@echo "$(YELLOW)🚽 Deleting object files in libft dir... 🚽$(DEF_COLOR)"
	@make clean -C ${LIBFT_DIR} --no-print-directory

fclean: clean
	@echo "$(RED)🪦  Deleting FdF... 🪦$(DEF_COLOR)"
	@${RM} ${NAME}
	@echo "$(RED)🪦  Deleting libft... 🪦$(DEF_COLOR)"
	@make fclean -C ${LIBFT_DIR} --no-print-directory
	@${RM} libft.a
	@echo "$(RED)🪦  Deleting mlx... 🪦$(DEF_COLOR)"
	@${RM} libmlx42.a
	@echo "$(RED)☣️  CLEAR ☣️$(DEF_COLOR)"

re: fclean all