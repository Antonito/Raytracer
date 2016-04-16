##
## Makefile for Raytracer2 in /raytracer2
##
## Made by Antoine Baché
## Login   <bache_a@epitech.net>
##
## Started on  Thu Apr 14 12:22:26 2016 Antoine Baché
## Last update Sat Apr 16 18:12:01 2016 Ludovic Petrenko
##

DEBUG=			yes

SRC_PREFIX=		src/

SRC_FILES=		init_data.c			\
			launch.c			\
			main.c

TOOLS_PREFIX=		src/tools/

TOOLS_FILES=		memory.c

SRC=			$(addprefix $(SRC_PREFIX),$(SRC_FILES))

SRC_TOOLS=		$(addprefix $(TOOLS_PREFIX),$(TOOLS_FILES))

SRC+=			$(SRC_TOOLS)

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
	CFLAGS+=	-ansi -pedantic -g -D DEBUG
else
	CFLAGS+=	-Werror
endif

CC=			gcc

RM=			rm -f

OBJ=			$(SRC:.c=.o)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) -o $(NAME) $(LIB)
	@echo -ne '\e[1m\e[32m[ OK ] \e[0m'
	@echo "Compiled Raytracer2"

%.o:	%.c
	@$(CC) -o $@ -c $< $(CFLAGS)
	@echo -ne '\e[1m\e[32m[ OK ] \e[0m'
	@echo "Compiling" $<

all:	$(NAME) infos

infos:
ifeq ($(DEBUG), yes)
	@echo -e '\n [0;1;31;91mm[0;1;33;93mmm[0;1;32;92mm[0m   [0;1;34;94mmm[0;1;35;95mmm[0;1;31;91mmm[0m [0;1;33;93mm[0;1;32;92mmm[0;1;36;96mmm[0m  [0;1;35;95mm[0m    [0;1;33;93mm[0m   [0;1;36;96mm[0;1;34;94mmm[0m         [0;1;36;96mm[0m    [0;1;31;91mm[0m  [0;1;33;93mm[0;1;32;92mmm[0;1;36;96mm[0m  [0;1;34;94mm[0;1;35;95mmm[0;1;31;91mm[0m   [0;1;32;92mmm[0;1;36;96mmm[0;1;34;94mmm[0m\n [0;1;33;93m#[0m   [0;1;36;96m"[0;1;34;94mm[0m [0;1;35;95m#[0m      [0;1;32;92m#[0m    [0;1;35;95m#[0m [0;1;31;91m#[0m    [0;1;32;92m#[0m [0;1;36;96mm[0;1;34;94m"[0m   [0;1;31;91m"[0m        [0;1;34;94m#[0;1;35;95m#[0m  [0;1;31;91m#[0;1;33;93m#[0m [0;1;32;92mm"[0m  [0;1;34;94m"m[0m [0;1;35;95m#[0m   [0;1;33;93m"[0;1;32;92mm[0m [0;1;36;96m#[0m\n [0;1;32;92m#[0m    [0;1;35;95m#[0m [0;1;31;91m#m[0;1;33;93mmm[0;1;32;92mmm[0m [0;1;36;96m#[0;1;34;94mmm[0;1;35;95mmm[0;1;31;91m"[0m [0;1;33;93m#[0m    [0;1;36;96m#[0m [0;1;34;94m#[0m   [0;1;31;91mm[0;1;33;93mm[0m        [0;1;35;95m#[0m [0;1;31;91m#[0;1;33;93m#[0m [0;1;32;92m#[0m [0;1;36;96m#[0m    [0;1;35;95m#[0m [0;1;31;91m#[0m    [0;1;36;96m#[0m [0;1;34;94m#m[0;1;35;95mmm[0;1;31;91mmm[0m\n [0;1;36;96m#[0m    [0;1;31;91m#[0m [0;1;33;93m#[0m      [0;1;34;94m#[0m    [0;1;33;93m#[0m [0;1;32;92m#[0m    [0;1;34;94m#[0m [0;1;35;95m#[0m    [0;1;32;92m#[0m        [0;1;31;91m#[0m [0;1;33;93m"[0;1;32;92m"[0m [0;1;36;96m#[0m [0;1;34;94m#[0m    [0;1;31;91m#[0m [0;1;33;93m#[0m    [0;1;34;94m#[0m [0;1;35;95m#[0m\n [0;1;34;94m#[0;1;35;95mmm[0;1;31;91mm"[0m  [0;1;32;92m#m[0;1;36;96mmm[0;1;34;94mmm[0m [0;1;35;95m#[0;1;31;91mmm[0;1;33;93mmm[0;1;32;92m"[0m [0;1;36;96m"m[0;1;34;94mmm[0;1;35;95mm"[0m  [0;1;33;93m"m[0;1;32;92mmm[0;1;36;96m"[0m        [0;1;33;93m#[0m    [0;1;34;94m#[0m  [0;1;35;95m#[0;1;31;91mmm[0;1;33;93m#[0m  [0;1;32;92m#[0;1;36;96mmm[0;1;34;94mm"[0m  [0;1;31;91m#m[0;1;33;93mmm[0;1;32;92mmm[0m\n'
endif
	@echo -ne '\e[1m\e[36mCompilation line: \e[0m'
	@echo $(CC) -o file.o -c file.c $(CFLAGS)
	@echo -ne '\e[1m\e[36mLinking: \e[0m'
	@echo $(CC) files.o ... -o $(NAME) $(LIB)


clean:
	@$(RM) $(OBJ)
	@echo -ne '\e[1m\e[31m[ RM ] \e[0m'
	@echo "Removing OBJ files ..."

fclean:	clean
	@$(RM) $(NAME)
	@echo -ne '\e[1m\e[31m[ RM ] \e[0m'
	@echo "Removing binaries ..."

re:	fclean all

.PHONY:	all clean fclean re
