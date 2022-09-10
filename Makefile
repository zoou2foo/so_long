# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vjean <vjean@student.42quebec.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/08 09:33:47 by vjean             #+#    #+#              #
<<<<<<< HEAD
#    Updated: 2022/09/09 21:47:08 by vjean            ###   ########.fr        #
=======
#    Updated: 2022/09/06 08:44:03 by vjean            ###   ########.fr        #
>>>>>>> 02f64d124c6e142eae9097fbe7d2b0b46c61956a
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = error_check_basic.c check_map.c check_game_basic.c so_long.c game_init.c\
	call_moves.c do_moves.c \
# nom des fichiers sources

LIBFT = libft/libft.a

OBJS = $(SRCS:.c=.o)

CC = gcc #le compilateur à utiliser

CFLAGS = -g -Wall -Wextra -Werror

<<<<<<< HEAD
MLX_FLAGS = -Lminilibx_opengl_20191021/ -lmlx -framework OpenGL -framework AppKit
#-L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit
#at home^
=======
MLX_FLAGS = -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit
#-Lmlx/minilibx_opengl_20191021/ -lmlx -framework OpenGL -framework AppKit

>>>>>>> 02f64d124c6e142eae9097fbe7d2b0b46c61956a


.c.o:
	@$(CC)$(CFLAGS) -Imlx -c $< -o $(<:.c=.o)

#AR = ar rcs

RM = rm -fr

#BONUS_OBJS = $(BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) 
	cd libft && make
	@$(CC) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)


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