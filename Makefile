# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bruno <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/22 21:20:20 by bruno             #+#    #+#              #
#    Updated: 2019/01/24 16:26:11 by cbruno           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fractol

CC		= gcc
CFLAGS	= 
LIBFT	= ./includes/libft

objects	=	./src/fractal.o ./src/julia.o ./src/utils.o ./src/menu.o ./src/mouse.o ./src/color.o ./src/mandelbrot.o ./src/image.o ./src/graphic.o ./src/print.o ./src/paint.o ./src/key.o ./src/free.o ./src/main.o

ARCH = $(shell arch)

ifeq ($(ARCH), x86_64)
	MINILIBX	= ./includes/minilibx
	FRAMEWORK	= -lm -lft -lmlx -lX11 -lXext
else
	MINILIBX 	= ./includes/minilibx_macos
	FRAMEWORK	= -lmlx -lft -framework OpenGL -framework AppKit
endif

.SILENT:

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -DARCH=$(ARCH) -c -o $@ $<
	printf '\033[36m[ ✔ ] %s\n\033[36m' "$<"

$(NAME): lib $(objects) 
	$(CC) $(CFLAGS) -o $@ $(objects) -L $(MINILIBX) -L $(LIBFT) $(FRAMEWORK)
	printf '\033[32m[ ✔ ] %s\n\033[32m' "FDF"

lib:
	make -s -C $(LIBFT)
	make -s -C $(MINILIBX)

clean:
	make -s -C $(LIBFT) clean
	make -s -C $(MINILIBX) clean
	rm -f $(objects)
	printf '\033[31m[ ✔ ] %s\n\033[0m' "Clean Libprintf"

fclean:
	make -s -C $(LIBFT) fclean
	make -s -C $(MINILIBX) clean
	rm -f $(objects)
	rm -f $(NAME)
	printf '\033[31m[ ✔ ] %s\n\033[0m' "Fclean Libprintf"

run: re clean

re: fclean all
