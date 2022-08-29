# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vjean <vjean@student.42quebec.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/08 09:33:47 by vjean             #+#    #+#              #
#    Updated: 2022/08/29 10:46:41 by vjean            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = error_check.c check_map1.c deal_mlx.c so_long.c game_init.c \
# nom des fichiers sources

LIBFT = libft/libft.a

OBJS = $(SRCS:.c=.o)

CC = gcc #le compilateur à utiliser

CFLAGS = -g -Wall -Wextra -Werror

MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

.c.o:
	$(CC)$(CFLAGS) -Imlx -c $< -o $(<:.c=.o)

#AR = ar rcs

RM = rm -fr

#BONUS_OBJS = $(BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) 
	cd libft && make
	$(CC) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

clean:
	$(RM) $(OBJS)
	make clean -C libft

fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIBFT)

re: fclean all

#bonus: $(OBJS) $(BONUS_OBJS)
#$(CC) $(NAME) $(OBJS) $(BONUS_OBJS)

.PHONY: all clean fclean re #bonus