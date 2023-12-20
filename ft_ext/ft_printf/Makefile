NAME = ft_printf.a

SRCC = ft_printf.c ft_putchar.c ft_putnbr.c \
ft_putstr.c ft_putnbr_base.c ft_put_adress.c

SRCO = $(SRCC:.c=.o)

CFLAGS = -Wall -Werror -Wextra

LIB_DIR = ../
OBJ_DIR = ./OBJ/.

all : $(SRCC) $(NAME)

%.o : %.c ft_printf.h Makefile $(OBJ_DIR)
	gcc $(FLAGS) -c $< -o $(OBJ_DIR)/${<:.c=.o}

$(NAME) : $(SRCO)
	ar crs $(LIB_DIR)$(NAME) $(addprefix $(OBJ_DIR)/,$(notdir $(SRCO)))

re : fclean $(NAME)

fclean : clean
	rm -rf $(NAME)

clean :
	rm -rf $(addprefix $(OBJ_DIR)/,$(notdir $(SRCO)))

.PHONY: all re fclean clean