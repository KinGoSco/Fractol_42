# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nkhachab <nkhachab@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/07 21:17:25 by nkhachab          #+#    #+#              #
#    Updated: 2023/06/08 17:02:42 by nkhachab         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = julia.c main.c mandelbrot.c tools.c hook.c

OBJFILES = $(SRC:.c=.o)
CFLAGS = -Wall -Werror -Wextra
LDFLAGS = -lmlx -framework OpenGL -framework AppKit
NAME = fractol

all: $(NAME)

$(NAME): $(OBJFILES)
	cc $(CFLAGS) $(OBJFILES) $(LDFLAGS) -o $(NAME)

clean:
	rm -f $(OBJFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all
