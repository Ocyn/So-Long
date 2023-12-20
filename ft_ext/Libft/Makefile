NAME = libft.a

SRCC =  ft_strlen.c \
		ft_to_bzero.c \
		ft_itoa.c \
		ft_strdup.c

SRCO = $(SRCC:.c=.o)

CFLAGS = -Wall -Werror -Wextra

LIB_DIR = ../
OBJ_DIR = ./OBJ/.

all : $(SRCC) $(NAME)

%.o : %.c libft.h
	gcc $(FLAGS) -c $< -o $(OBJ_DIR)/${<:.c=.o}

$(NAME) : $(SRCO)
		ar crs $(LIB_DIR)$(NAME) $(addprefix $(OBJ_DIR)/,$(notdir $(SRCO)))

re : fclean $(NAME)

fclean : clean
	rm -f $(NAME)

clean :
	rm -f $(addprefix $(OBJ_DIR)/,$(notdir $(SRCO)))

.PHONY: all re fclean clean