# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: keenouxe <keenouxe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/19 08:23:39 by keenouxe          #+#    #+#              #
#    Updated: 2019/04/21 11:51:42 by jucapik          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	jucapik.filler
GRAPHNAME	=	shower.filler
#	Make options
MAKEFLAGS	+=	--no-print-directory

#	Output
UNAME	:=	$(shell uname)
ifeq ($(UNAME), Darwin)
	ECHO	=	@echo
endif

ifeq ($(UNAME), Linux)
	ECHO	=	@echo -e
endif

#	Compilator
CC		=	gcc
FLAGS	=	-Wall -Wextra -Werror

#	Folders
LIBDIR	=	lib$(LIB)
SRCDIR	=	.
OBJDIR	=	objs
INCDIR	=	.									\
			libft/includes						\
			sdl_main/SDL2-2.0.8/include/SDL2

#	Source files
SRC		=	main.c data.c piece2.c quit.c debug.c piece.c data2.c \
				heater.c free.c even_heatmap.c apply_heatmap.c free2.c \
				helper.c

SRC1		=	maingraph.c data.c piece2.c quit.c debug.c piece.c data2.c \
				heater.c free.c even_heatmap.c apply_heatmap.c img.c \
				put_img.c key_press.c data_graph.c piece_graph.c free2.c \
				helper.c


#	Graphic folders
SDL_MAIN_DOWNLOAD = https://www.libsdl.org/release/SDL2-2.0.8.tar.gz

LIBSDL			=   SDL2
LIBSDLIMG		=   SDL2_image

LFLAG		=		-L sdl_main/SDL2-2.0.8/lib  -lSDL2


OBJ		=	$(SRC:.c=.o)

LIB		=	ft

#	Prefixes
OBJP	=	$(addprefix $(OBJDIR)/, $(SRC:.c=.o))
OBJP1	=	$(addprefix $(OBJDIR)/, $(SRC1:.c=.o))
	INCP 	=	$(foreach dir, $(INCDIR), -I$(dir))
	LLIBP =		$(addprefix -l, $(LIB))
	LIBNAME =	$(addprefix lib, $(LIB))
	LIBP =		$(addprefix -L, $(LIBNAME)/)

#	Compilator
CC		=	gcc
FLAGS	=	-Wall -Wextra -Werror

#	Default Rule
DRULE	=	all

#	Main rules
default	:
	$(ECHO) "$(PUR)===> $(GRE)$(NAME) : $(PUR) START RULE : $(DRULE) <===$(DEF)"
	@make $(DRULE)
	$(ECHO) "$(PUR)===> $(GRE)$(NAME) : $(PUR) END RULE : $(DRULE) <===$(DEF)"

all		:	lib $(NAME)

re		:	fclean default

#	Graphic Library rules

lib: sdl_main

sdl_main:
	@if [ -d "./sdl_main/" ]; then \
		echo "SDL (main) ==> Nothing to be done"; \
		else \
		mkdir sdl_main && \
		echo "SDL (main) ==> Downloading SDL" && \
		cd ./sdl_main && \
		curl -s $(SDL_MAIN_DOWNLOAD) -O && \
		echo "SDL (main) ==> Compilation SDL main" && \
		tar xzf SDL2-2.0.8.tar.gz && \
		cd SDL2-2.0.8 && \
		./configure --prefix=$(shell pwd)/sdl_main/SDL2-2.0.8 > /dev/null && \
		$(MAKE) > /dev/null &&  \
		$(MAKE) install > /dev/null && \
		echo "SDL (main) ==> DONE"; \
		fi

#	Compilation rules
libft/libft.a	:
	$(ECHO) "$(YEL)===> $(GRE)lib$(LIB)$(YEL) Compilation <===$(DEF)"
	@make all -C lib$(LIB)

$(OBJDIR)/%.o	:  $(SRCDIR)/%.c filler.h
	@mkdir -p $(OBJDIR)
	$(CC) $(FLAGS) $(INCP) -c -o $@ $<

$(NAME)	:	libft/libft.a $(OBJP) $(OBJP1)
	$(ECHO) "$(YEL)===> $(GRE)$(NAME) : $(YEL) Binary Compilation <===$(DEF)"
	$(CC) $(FLAGS) -o $@ $(OBJP) $(INCP) $(LIBP) $(LLIBP) \
		$(LFLAG) -lSDL2
	$(CC) $(FLAGS) -o $(GRAPHNAME) $(OBJP1) $(INCP) $(LIBP) $(LLIBP) \
		$(LFLAG) -lSDL2

#	Cleaner rules
clean	:
	$(ECHO) "$(RED)===> $(GRE)$(NAME) : $(RED) Delete Object Files <===$(DEF)"
	@rm -rf $(OBJDIR)

fclean	:	clean
	$(ECHO) "$(RED)===> $(GRE)$(NAME) : $(RED) Delete Binary File <===$(DEF)"
	@rm -f $(NAME)
	@rm -f $(GRAPHNAME)
	$(ECHO) "$(RED)===> Delete $(GRE)lib$(LIB)$(RED) <===$(DEF)"
	@make fclean -C lib$(LIB)

#	Phony
.PHONY	=	default all re clean fclean $(OBJDIR) $(NAME)
#	Color
DEF		=	\033[0m
BLA		=	\033[30m
BLI		=	\033[5m
BLU		=	\033[34m
CYA		=	\033[36m
GRA		=	\033[1m
GRE		=	\033[32m
PUR		=	\033[35m
RED		=	\033[31m
SOU		=	\033[4m
WHI		=	\033[37m
YEL		=	\033[33m
