# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vjean <vjean@student.42quebec.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/08 09:33:47 by vjean             #+#    #+#              #
#    Updated: 2022/09/09 21:47:08 by vjean            ###   ########.fr        #
#    Updated: 2022/09/06 08:44:03 by vjean            ###   ########.fr        #                                                                            #
# **************************************************************************** #

NAME = so_long

SRCS = error_check_basic.c check_map.c check_game_basic.c so_long.c game_init.c\
	call_moves.c do_moves.c \
# nom des fichiers sources

LIBFT = libft/libft.a

OBJS = $(SRCS:.c=.o)

CC = gcc #le compilateur à utiliser

CFLAGS = -g -Wall -Wextra -Werror


MLX_FLAGS = -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit
#-Lminilibx_opengl_20191021/ -lmlx -framework OpenGL -framework AppKit
#at home^

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

tests:	all
	@echo ""
	@echo "---==== VERSION MANDATOIRE ====---"
	@echo ""
	@echo "Vous ne devriez voir que des erreurs. Si une carte/jeu se load, c'est un fail"
	@echo ""
	@echo "Test FD en problème"
	./$(NAME) maps/mip.ber
	@echo ""
	@echo "Nombre d'arguments en problème"
	./$(NAME) maps/map.ber maps/map1.ber
	@echo ""
	@echo "Nom de fichier en problème"
	./$(NAME) maps/map.bert
	@echo ""
	@echo "Nom de fichier en problème (pas d'extension)"
	./$(NAME) maps/map
	@echo ""
	@echo "Carte inexistante (NULL)"
	./$(NAME) maps/null.ber
	@echo ""
	@echo "Carte trop petite"
	./$(NAME) maps/too_small.ber
	@echo ""
	@echo "Carte avec mauvais caractère (test 1)"
	./$(NAME) maps/bad.ber
	@echo ""
	@echo "Carte avec mauvais caractère (test 2)"
	./$(NAME) maps/bad1.ber
	@echo ""
	@echo "Carte pas rectangle"
	./$(NAME) maps/bad2.ber
	@echo ""
	@echo "Carte problème de mur (test 1)"
	./$(NAME) maps/bad3.ber
	@echo ""
	@echo "Carte problème de mur (test 2)"
	./$(NAME) maps/bad4.ber
	@echo ""
	@echo "Carte problème de mur (test 3)"
	./$(NAME) maps/bad5.ber
	@echo ""
	@echo "Carte caractère manquant (test 1 - P)"
	./$(NAME) maps/bad6.ber
	@echo ""
	@echo "Carte caractère manquant (test 2 - E)"
	./$(NAME) maps/bad7.ber
	@echo ""
	@echo "Carte caractère manquant (test 3 - C)"
	./$(NAME) maps/bad8.ber
	@echo ""
	@echo "Carte doublon (P)"
	./$(NAME) maps/bad9.ber
	@echo ""
#bonus: $(OBJS) $(BONUS_OBJS)
#$(CC) $(NAME) $(OBJS) $(BONUS_OBJS)

.PHONY: all clean fclean re #bonus