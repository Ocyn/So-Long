NAME = gnl.a

SRCC =  get_next_line.c \
		get_next_line_utils.c \

LIBFT = ../Libft/libft.a

SRCO = $(SRCC:.c=.o)

CFLAGS = -Wall -Werror -Wextra

LIB_DIR = ../
OBJ_DIR = ./OBJ/.

all : $(SRCC) $(NAME)

%.o : %.c get_next_line.h Makefile $(OBJ_DIR)
	gcc $(FLAGS) -c $< -o $(OBJ_DIR)/${<:.c=.o}

$(NAME) : $(SRCO)
	ar crs $(LIB_DIR)$(NAME) $(addprefix $(OBJ_DIR)/,$(notdir $(SRCO)))

re : fclean $(NAME)

fclean : clean
	rm -f $(NAME)

clean :
	rm -f $(addprefix $(OBJ_DIR)/,$(notdir $(SRCO)))

.PHONY: all re fclean clean