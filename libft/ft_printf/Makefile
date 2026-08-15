NAME = ft_printf.a

FUNCTIONS = ft_printf.c ft_putchar.c ft_putnbr.c ft_putnbr_u.c\
	ft_puthex.c ft_puthex_up.c ft_putstr.c ft_putpntr.c
OBJECTS = $(FUNCTIONS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJECTS)
	$(AR) $(NAME) $(OBJECTS)

all: $(NAME)

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY:  all clean fclean re

