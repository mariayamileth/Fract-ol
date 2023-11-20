# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maricont <maricont@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/10 18:41:11 by maricont          #+#    #+#              #
#    Updated: 2023/11/13 09:51:44 by maricont         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CFLAGS = -Wall -Wextra -Werror
LFLAGS = -L./mlx -lmlx -framework OpenGL -framework AppKit

SRCS = fractol.c util.c mlx.c cal_fractol.c

OBJS = $(SRCS:.c=.o)

INCLUDE = -I ./
RM = rm -f

%.o: %.c fractol.h
	${CC} ${CFLAGS} -I./mlx $(INCLUDE) -c $< -o $@

all : $(NAME)

$(NAME): $(OBJS)
	@cd mlx && make
	${CC} ${CFLAGS} $(OBJS) ${LFLAGS} -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

