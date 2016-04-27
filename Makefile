##
## Makefile for Raytracer2 in /raytracer2
##
## Made by Antoine Baché
## Login   <bache_a@epitech.net>
##
## Started on  Thu Apr 14 12:22:26 2016 Antoine Baché
## Last update Wed Apr 27 23:22:50 2016 Antoine Baché
##

DEBUG=			yes

SRC_PREFIX=		src/

SRC_FILES=		init_data.c			\
			build_octree.c			\
			get_node.c			\
			launch.c			\
			main.c				\
			vector.c			\
			vector_op.c

NOISE_PREFIX=		src/noise/

NOISE_FILES=		perlin.c			\
			perlin_calc_color.c		\
			perlin_calc_init.c		\
			perlin_calc_pixel.c		\
			perlin_calc_smooth.c		\
			perlin_calc_smooth_values.c	\
			perlin_gradient.c		\
			perlin_tables.c			\
			perlin_tables_4d.c		\
			perlin_tables_4d_next.c		\
			permutation_table.c		\
			simplex.c			\
			simplex_calc_det.c		\
			simplex_calc_grad.c		\
			simplex_calc_init.c		\
			simplex_calc_offset.c		\
			simplex_calc_offset_next.c	\
			simplex_calc_pixel.c		\
			simplex_calc_table.c		\
			simplex_mask.c

NETWORK_PREFIX=		src/cluster/

NETWORK_FILES=		connection.c			\
			packet.c			\
			server.c

CLIENT_PREFIX=		src/client/

CLIENT_FILES=		main.c				\
			loop.c

LOADER_PREFIX=		src/loader/

LOADER_FILES=		count.c				\
			get_material.c			\
			load_config.c			\
			load_light_type.c		\
			load_mat.c			\
			load_obj.c			\
			load_obj_type.c			\
			load_scene.c			\
			obj_type.c

SOLVER_PREFIX=		src/solver/

SOLVER_FILES=		second_degree.c			\
			third_degree.c			\
			fourth_degree.c			\
			fourth_degree_extended.c	\
			check_solution.c

TOOLS_PREFIX=		src/tools/

TOOLS_FILES=		memory.c			\
			fast_sqrt.c			\
			my_strlen.c			\
			my_getnbr.c			\
			my_getdouble.c			\
			my_strcmp.c			\
			my_strncmp.c			\
			my_gethexa.c			\
			my_strndup.c			\
			my_puterr.c

SRC=			$(addprefix $(SRC_PREFIX),$(SRC_FILES))

SRC_NOISE=		$(addprefix $(NOISE_PREFIX),$(NOISE_FILES))

SRC_NETWORK=		$(addprefix $(NETWORK_PREFIX),$(NETWORK_FILES))

SRC_CLIENT=		$(addprefix $(CLIENT_PREFIX),$(CLIENT_FILES))

SRC_LOADER=		$(addprefix $(LOADER_PREFIX),$(LOADER_FILES))

SRC_SOLVER=		$(addprefix $(SOLVER_PREFIX),$(SOLVER_FILES))

SRC_TOOLS=		$(addprefix $(TOOLS_PREFIX),$(TOOLS_FILES))

SRC+=			$(SRC_NOISE)

SRC+=			$(SRC_NETWORK)

SRC+=			$(SRC_TOOLS)

SRC+=			$(SRC_LOADER)

SRC+=			$(SRC_SOLVER)

SRC_CLIENT+=		$(SRC_TOOLS)

NAME=			raytracer2

NAME_CLIENT=		client_raytracer2

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
			-lpthread			\
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

OBJ_CLIENT=		$(SRC_CLIENT:.c=.o)

$(NAME_CLIENT): $(OBJ_CLIENT)
	@$(CC) $(OBJ_CLIENT) -o $(NAME_CLIENT) $(LIB)
	@echo -ne '\e[1m\e[32m[ OK ] \e[0m'
	@echo "Compiled client"

$(NAME): $(OBJ)
	@$(CC) $(OBJ) -o $(NAME) $(LIB)
	@echo -ne '\e[1m\e[32m[ OK ] \e[0m'
	@echo "Compiled Raytracer2"

%.o:	%.c
	@$(CC) -o $@ -c $< $(CFLAGS)
	@echo -ne '\e[1m\e[32m[ OK ] \e[0m'
	@echo "Compiling" $<

all:	$(NAME) $(NAME_CLIENT) infos

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
	@$(RM) $(OBJ_CLIENT)
	@echo -ne '\e[1m\e[31m[ RM ] \e[0m'
	@echo "Removing OBJ files ..."

fclean:	clean
	@$(RM) $(NAME)
	@$(RM) $(NAME_CLIENT)
	@echo -ne '\e[1m\e[31m[ RM ] \e[0m'
	@echo "Removing binaries ..."

re:	fclean all

.PHONY:	all clean fclean re
