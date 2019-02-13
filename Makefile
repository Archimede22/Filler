#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jucapik <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/04 13:09:58 by jucapik           #+#    #+#              #
#    Updated: 2019/02/13 16:35:13 by jucapik          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		=	jucapik.filler

GRAPHNAME	=	shower.filler

CC			=	gcc

CFLAGS		+=	-g -Wall -Wextra -Werror

SRC0		=	main.c data.c piece2.c quit.c debug.c piece.c data2.c \
				heater.c free.c even_heatmap.c apply_heatmap.c free2.c \
				helper.c

SRC1		=	maingraph.c data.c piece2.c quit.c debug.c piece.c data2.c \
				heater.c free.c even_heatmap.c apply_heatmap.c img.c \
				put_img.c key_press.c data_graph.c piece_graph.c free2.c \
				helper.c

SRCPATH0	=	.

SOURCES0	=	$(addprefix $(SRCPATH0)/, $(SRC0))

HDR0		=	filler.h


HDRPATH0	=	.

HEADERS0	=	$(addprefix $(HDRPATH0)/, $(HDR0))

LIBNAME		=	ft

LIBSDL		=	SDL2

LIBUI		=	libui

LIBPATH		=	libft

LIBHEAD		=	libft

OBJ0		=	$(SRC0:.c=.o)

OBJ1		=	$(SRC1:.c=.o)

%.o:		$(SRCPATH0)/%.c
	$(CC) -o $@ -c $^ $(CFLAGS)

.PHONY:		clean fclean re

all:		$(NAME)

$(NAME):	$(OBJ0) $(OBJ1)
	cd $(LIBPATH) && $(MAKE)
	$(CC) -o $(NAME) $(OBJ0) -I $(LIBHEAD) -L $(LIBPATH) -l$(LIBNAME) \
		-L $(LIBUI) -l$(LIBSDL) $(sdl2-config --cflags --libs)
	$(CC) -o $(GRAPHNAME) $(OBJ1) -I $(LIBHEAD) -L $(LIBPATH) -l$(LIBNAME) \
		-L $(LIBUI) -l$(LIBSDL) $(sdl2-config --cflags --libs)

clean:
	@(cd $(LIBPATH) && $(MAKE) clean)
	rm -rf $(OBJ0)
	rm -rf $(OBJ1)

fclean:
	@(cd $(LIBPATH) && $(MAKE) fclean)
	rm -rf $(OBJ0)
	rm -rf $(OBJ1)
	rm -rf $(NAME)
	rm -rf $(GRAPHNAME)

re:			fclean all $(HDRPATH0)/$(HDR0)
