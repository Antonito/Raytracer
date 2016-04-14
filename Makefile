##
## Makefile for Raytracer2 in /raytracer2
##
## Made by Antoine Baché
## Login   <bache_a@epitech.net>
##
## Started on  Thu Apr 14 12:22:26 2016 Antoine Baché
## Last update Thu Apr 14 18:52:03 2016 Antoine Baché
##

DEBUG=			yes

SRC_PREFIX=		src/

SRC_FILES=		main.c

TOOLS_PREFIX=		src/tools/

TOOLS_FILES=

SRC=			$(addprefix $(SRC_PREFIX),$(SRC_FILES))

SRC_TOOLS=		$(addprefix $(TOOLS_PREFIX),$(TOOLS_FILES))

#SRC+=			$(SRC_TOOLS)

NAME=			raytracer2

HEAD=			-Iinclude			\
			-I/home/${USER}/.froot/include

LIB=			-L/usr/local/lib		\
			-L/home/${USER}/.froot/lib	\
			-llapin 			\
			-lsfml-audio 			\
			-lsfml-graphics 		\
			-lsfml-window 			\
			-lsfml-system 			\
			-lstdc++ 			\
			-ldl 				\
			-lOpenCL			\
			-lm

CFLAGS=			$(HEAD) -W -Wall -Wextra
ifeq ($(DEBUG), yes)
	CFLAGS+=		-ansi -pedantic -g -D DEBUG
else
	CFLAGS+=		-Werror
endif

CC=			gcc

RM=			rm -f

OBJ=			$(SRC:.c=.o)

$(NAME): $(OBJ)
	@echo -n "Flags: "
	@echo $(CFLAGS)
	@echo -n "[ "
	@echo -n "OK"
	@echo -n " ] "
	@echo "Compiled Raytracer2"
	@$(CC) $(OBJ) -o $(NAME) $(LIB)

%.o:	%.c
	@echo -n "[ "
	@echo -n "OK"
	@echo -n " ] "
	@echo "Compiling" $<
	@$(CC) -o $@ -c $< $(CFLAGS)

all:	$(NAME)

clean:
	@echo -n "[ "
	@echo -n "OK"
	@echo -n " ] "
	@echo "Removing OBJ files ..."
	@$(RM) $(OBJ)

fclean:	clean
	@echo -n "[ "
	@echo -n "OK"
	@echo -n " ] "
	@echo "Deleting binaries ..."
	@$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
