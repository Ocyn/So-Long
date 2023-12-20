NAME = so_long

SRCC_DIR = ft_src/

SRCC = So_long_Main.c \
       ft_parse_map.c \
       ft_pre_parse_map.c \
       ft_tools.c \
       ft_is_map_finishable.c \
       ft_save_map.c \
       ft_build_map.c \
       ft_play.c \
       ft_interact.c \
	   ft_player_way.c \
	   ft_rtx_on.c \
	   ft_rtx_on_utils.c

SRCC_PATH = $(addprefix $(SRCC_DIR),$(SRCC))

CC = gcc
FLAGS = -Wall -Wextra -Werror -g3

INCLUDE = ./headers/so_long.h

OBJ_DIR = OBJ/
OBJ_PATH = $(SRCC_DIR)$(OBJ_DIR)

MLX_DIR = mlx_linux/libmlx.a
INCLUDE_MLX = ./mlx_linux/mlx.h ./mlx_linux/mlx_int.h
MLXFLAGS = -L ./mlx_linux -lmlx -lXext -lX11 -lm -lbsd

LIB_DIR = ./ft_ext/
LIB = 	libft.a \
		ft_printf.a \
		gnl.a
LIB_INCLUDE =	ft_ext/ft_printf/ft_printf.h \
				ft_ext/get_next_line/get_next_line.h \
				ft_ext/Libft/libft.h
LIB_PATH = $(addprefix $(LIB_DIR),$(LIB))

OBJ = $(addprefix $(OBJ_PATH), $(SRCC:.c=.o))

all : Makefile $(NAME) 

$(NAME): $(INCLUDE) $(OBJ) | $(LIB_PATH)
	$(CC) $(OBJ) $(INCLUDE) $(MLX_DIR) $(LIB_PATH) $(MLXFLAGS) $(FLAGS) -o $(NAME)

$(MLX_DIR): $(INCLUDE_MLX)
	make -C mlx_linux/

$(LIB_PATH): $(MLX_DIR)
	make -C $(LIB_DIR)Libft/
	make -C $(LIB_DIR)get_next_line/
	make -C $(LIB_DIR)ft_printf/

$(OBJ_PATH)%.o : $(SRCC_DIR)%.c | $(OBJ_PATH)
	$(CC) $(FLAGS) -c $< -o $@

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

re : fclean $(NAME)

fclean : clean
	rm -rf $(NAME)
	rm -rf ft_ext/*.a
	make fclean -C $(LIB_DIR)Libft/
	make fclean -C $(LIB_DIR)get_next_line/
	make fclean -C $(LIB_DIR)ft_printf/

clean :
	rm -rf $(OBJ)
	make clean -C $(LIB_DIR)Libft/
	make clean -C $(LIB_DIR)get_next_line/
	make clean -C $(LIB_DIR)ft_printf/
	make clean -C mlx_linux/

.PHONY: all MLX re fclean clean