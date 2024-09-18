# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/03 14:20:18 by msavelie          #+#    #+#              #
#    Updated: 2024/09/18 11:08:36 by msavelie         ###   ########.fr        #
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
BONUS_DIR = ./bonus

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
	${SRC_DIR}/hooks.c \
	${SRC_DIR}/point_handle.c \
	${SRC_DIR}/scale.c

BONUS_SRCS = \
	${BONUS_DIR}/main_bonus.c \
	${BONUS_DIR}/check_map_bonus.c \
	${BONUS_DIR}/free_ret_bonus.c \
	${BONUS_DIR}/parse_map_bonus.c \
	${BONUS_DIR}/convert_map_bonus.c \
	${BONUS_DIR}/map_to_mlx_bonus.c \
	${BONUS_DIR}/draw_line_bonus.c \
	${BONUS_DIR}/to_2d_bonus.c \
	${BONUS_DIR}/calculate_colors_bonus.c \
	${BONUS_DIR}/set_colors_bonus.c \
	${BONUS_DIR}/actions_bonus.c \
	${BONUS_DIR}/rotate_bonus.c \
	${BONUS_DIR}/point_handle_bonus.c \
	${BONUS_DIR}/gui_bonus.c \
	${BONUS_DIR}/hooks_bonus.c \
	${BONUS_DIR}/scale_bonus.c

OBJS = ${SRCS:.c=.o}
BONUS_OBJS = ${BONUS_SRCS:.c=.o}

CFLAGS = -g -Wall -Werror -Wextra -Wpedantic

LIBFT_DIR = ./libft
LIBFT_NAME = ${LIBFT_DIR}/libft.a
MLX_DIR = ./MLX42
MLX_NAME = ${MLX_DIR}/build/libmlx42.a

HEADERS	= -I ./include -I $(LIBMLX)/include
LIBS = ${LIBFT_NAME} ${MLX_NAME} -ldl -lglfw -pthread -lm

RM = rm -rf
AR = ar -rcs
LIB = ranlib

.PHONY = all clean fclean re bonus libmlx

all: libmlx ${LIBFT_NAME} ${NAME}

${LIBFT_NAME}:
	@echo "$(CYAN)🛠  Compiling libft... 🛠$(DEF_COLOR)"
	@make -C ${LIBFT_DIR} --no-print-directory

libmlx: .mlx

.mlx:
	@touch .mlx
	@git clone https://github.com/codam-coding-college/MLX42.git ${MLX_DIR}
	@cmake ${MLX_DIR} -B ${MLX_DIR}/build && cmake --build ${MLX_DIR}/build -j4

${NAME}: ${OBJS}
	@echo "$(BLUE)🛠  Compiling FdF... 🛠$(DEF_COLOR)"
	@cc ${CFLAGS} ${OBJS} ${LIBS} ${HEADERS} -o ${NAME}
	@echo "$(GREEN)🥳 Success!🥳$(DEF_COLOR)"

%.o: %.c
	@cc $(CFLAGS) -c $< -o $@ ${HEADERS}

clean:
	@echo "$(YELLOW)🚽 Deleting object files... 🚽$(DEF_COLOR)"
	@${RM} ${OBJS}
	@${RM} ${BONUS_OBJS}
	@echo "$(YELLOW)🚽 Deleting object files in libft dir... 🚽$(DEF_COLOR)"
	@make clean -C ${LIBFT_DIR} --no-print-directory

fclean: clean
	@echo "$(RED)🪦  Deleting FdF... 🪦$(DEF_COLOR)"
	@${RM} ${NAME}
	@echo "$(RED)🪦  Deleting libft... 🪦$(DEF_COLOR)"
	@make fclean -C ${LIBFT_DIR} --no-print-directory
	@echo "$(RED)🪦  Deleting mlx... 🪦$(DEF_COLOR)"
	@echo "$(RED)☣️  CLEAR ☣️$(DEF_COLOR)"
	@${RM} .bonus
	@${RM} -rf MLX42
	@${RM} .mlx

re: fclean all

bonus: all .bonus

.bonus: ${BONUS_OBJS} ${LIBFT_NAME}
	@touch .bonus
	@${RM} ${NAME}
	@echo "$(BLUE)🛠  Compiling FdF with bonus... 🛠$(DEF_COLOR)"
	@cc ${CFLAGS} ${BONUS_OBJS} ${LIBS} ${HEADERS} -o ${NAME}
	@echo "$(GREEN)🥳 Success!🥳$(DEF_COLOR)"