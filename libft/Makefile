# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/17 09:23:09 by msavelie          #+#    #+#              #
#    Updated: 2024/08/01 13:41:18 by msavelie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = \
	ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_strlen.c \
	ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strncmp.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strnstr.c \
	ft_atoi.c \
	ft_calloc.c \
	ft_strdup.c \
    ft_substr.c \
    ft_strjoin.c \
    ft_strtrim.c \
    ft_split.c \
    ft_itoa.c \
    ft_strmapi.c \
    ft_striteri.c \
    ft_putchar_fd.c \
    ft_putstr_fd.c \
    ft_putendl_fd.c \
    ft_putnbr_fd.c \
	ft_lstnew_bonus.c \
	ft_lstadd_front_bonus.c \
	ft_lstsize_bonus.c \
	ft_lstlast_bonus.c \
	ft_lstadd_back_bonus.c \
	ft_lstdelone_bonus.c \
	ft_lstclear_bonus.c \
	ft_lstiter_bonus.c \
	ft_lstmap_bonus.c \
	get_next_line_bonus.c \
	get_next_line_utils_bonus.c \
	ft_fprintf.c \
	ft_fprint_hex.c \
	ft_free_strs.c

CFLAGS = -Wall -Wextra -Werror

PRINTF_DIR = ./printf
PRINTF_NAME = ./printf/libftprintf.a

RM = rm -rf
AR = ar -rcs
LIB = ranlib

OBJS = ${SRCS:.c=.o}

.PHONY = all clean fclean re 

all: ${PRINTF_NAME} ${NAME}

${PRINTF_NAME}:
	@make -C ${PRINTF_DIR}

${NAME}: ${OBJS}
	@cp ${PRINTF_DIR}/libftprintf.a .
	@mv libftprintf.a ${NAME}
	@${AR} ${NAME} ${OBJS}
	@${LIB} ${NAME}

clean:
	@${RM} ${OBJS} 
	@make clean -C ${PRINTF_DIR}

fclean: clean
	@${RM} ${NAME}
	@make fclean -C ${PRINTF_DIR}

re: fclean all

%.o : %.c
	@cc ${CFLAGS} -c $< -o $@
