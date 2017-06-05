# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hpachy <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/08 13:33:40 by hpachy            #+#    #+#              #
#    Updated: 2017/01/30 12:48:31 by hpachy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d
LIB = libft/

HEAD = libft/
HEAD2 = Include/
FLAGS = -Wall -Werror -Wextra -g -O3
SRC = Src/main.c Src/parsing.c Src/light_on.c Src/line.c Src/raycasting.c Src/init_ray_casting_var.c Src/key_hook.c Src/wall_destruction.c Src/floor.c Src/wall_print.c Src/texture_retro.c Src/texturelol.c Src/retro_texture.c Src/load_hd.c Src/hd_texture.c Src/texture_hd_2.c Src/key_loop.c Src/print_wall_color.c Src/knife.c Src/gestion_error.c Src/error_shell.c
OBJ =  main.o parsing.o light_on.o line.o raycasting.o init_ray_casting_var.o key_hook.o wall_destruction.o floor.o wall_print.o texture_retro.o texturelol.o retro_texture.o load_hd.o hd_texture.o texture_hd_2.o key_loop.o print_wall_color.o knife.o gestion_error.o error_shell.o

LIBX = -O3 -lmlx -lft -framework OpenGL -framework appKit

all: libft $(NAME)

.PHONY: libft clean fclean re

libft:
	@make -C libft

$(NAME):
	@echo "\033[33;32mCompilation executable : $(NAME)"
	@gcc $(FLAGS) -c $(SRC) -I $(HEAD) -I $(HEAD2)
	@echo "\033[33;32mCompilation .o"
	@gcc -o $(NAME) -L $(LIB) $(OBJ) $(LIBX)
	@echo "\033[33;32m===> OK <==="

clean:
	@echo "\033[31mremove Wolf3D/*.o"
	@rm -f $(OBJ)
	@echo "\033[33;32m===> OK <==="

fclean:	clean
	@echo "\033[31mremove executable : $(NAME)"
	@rm -f $(NAME)
	@echo "\033[33;32m===> OK <==="

re:	fclean all
