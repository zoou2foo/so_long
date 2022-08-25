# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vjean <vjean@student.42quebec.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/08 09:33:47 by vjean             #+#    #+#              #
#    Updated: 2022/08/23 11:28:15 by vjean            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = error_check.c check_elements.c \
# nom des fichiers sources

LIBFT = libft/libft.a

OBJS = $(SRCS:.c=.o)

CC = gcc #le compilateur à utiliser

CFLAGS = -g -Wall -Wextra -Werror

.c.o:
	$(CC)$(CFLAGS) -Imlx -c $< -o $(<:.c=.o)

#AR = ar rcs

RM = rm -fr

#BONUS_OBJS = $(BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) 
	cd libft && make
	$(CC) $(OBJS) $(LIBFT) -o $(NAME)
#-Lmlx -lmlx -framework OpenGL -framework AppKit <-to add later
#$(NAME): $(OBJS) $(GNL_OBJS)
#    @make -C $(LIBFT_PATH)
#    $(CC) $(CFLAGS) $(GNL_OBJS) $(OBJS) $(MLX_FLAGS) $(LIBFT_PATH)/libft.a -o $(NAME)
#(NAME) va à la fin pour avoir l'exécutable so_long et non pas a.out
#MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

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