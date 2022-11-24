# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nick <nick@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/12 10:21:39 by nickras           #+#    #+#              #
#    Updated: 2022/11/24 23:14:02 by nick             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

LIBFTPRINTF_PATH	= ./libftprintf
LIBFTPRINTF_A	= $(LIBFTPRINTF_PATH)/libftprintf.a

MLX_FLAGS = -lmlx -lXext -lX11 -lm
MAKE = make
CC = gcc
RM = rm -rf
CFLAG = #-Wall -Werror -Wextra -g3
SRC_DIR = 	./src/
OBJ_DIR =   ./obj/


SRC_FILES = main.c create_picture.c start_values.c moving.c check_map.c check_tiles.c \
events.c check_route.c ../gnl/get_next_line_utils.c ../gnl/get_next_line.c \
../gnl/get_next_line.h ../libftprintf/libftprintf.a 

OBJ_FILES = ${SRC_FILES:.c=.o}
SRC			= $(addprefix $(SRC_DIR),$(SRC_FILES))
OBJ			= $(addprefix $(OBJ_DIR),$(OBJ_FILES))

${NAME}: ${OBJ} $(LIBFTPRINTF_A)
			${CC} -o ${NAME} ${CFLAG} ${OBJ}  $(MLX_FLAGS) 
#${LIBFTPRINTF_A}
all: ${NAME}

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
#			$(MAKE) all -C $(LIBFTPRINTF_PATH)
			mkdir -p $(OBJ_DIR)
			${CC} ${CFLAG} -o $@ -c $^

clean:
			$(RM) ${OBJ_DIR}

fclean: clean
			$(RM) ${NAME}
##			make fclean -C $(LIBFTPRINTF_PATH)

re: fclean all

.PHONY: all clean fclean re