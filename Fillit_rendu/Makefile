# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: jodoming <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/02/20 12:47:49 by jodoming     #+#   ##    ##    #+#        #
#    Updated: 2018/02/20 15:03:38 by jodoming    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME        =   fillit

LIB_DIR     =   ./lib

HEADER      =   fillit.h

FILENAMES   =   main.c map.c read.c solve.c tetri.c tetri_tools.c

SOURCES     =   $(addprefix ./, $(FILENAMES))

OBJECTS     =   $(addprefix build/, $(FILENAMES:.c=.o))

L_FT        =   ./libft

LIB_LNK     =   -L $(L_FT) -l ft

LIB_INC     =   -I $(L_FT)/libft.h

.PHONY: all clean fclean re

all: $(NAME)

clean:
		rm -rf build/
		@$(MAKE) -C $(L_FT) clean

fclean: clean
		rm -f $(NAME)
		@$(MAKE) -C $(L_FT) fclean

re:
	    @$(MAKE) fclean
		@$(MAKE) all

build:
		mkdir build/

$(NAME): $(OBJECTS)
	    @$(MAKE) -C $(L_FT)
		gcc -I $(HEADER) $(OBJECTS) $(LIB_LNK) -o $@

build/%.o: ./%.c | build
	    gcc $(LIB_INC) -I $(HEADER) -c $< -o $@
