# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iskaraag <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/06 17:32:10 by iskaraag          #+#    #+#              #
#    Updated: 2024/09/06 17:32:11 by iskaraag         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INC=%%%%

INCLIB=$(INC)/minilibx-linux/lib 
SRC     = main	sources/mapchecker	sources/errors \
		sources/mapchecker_utils	sources/errors2	sources/open_free \
		sources/maplen sources/keyhandler sources/draw

SRCS    = $(addsuffix .c, $(SRC))
OBJS    = $(SRCS:.c=.o)
NAME    = so_long

CC      = gcc
RM      = rm -f
CFLAGS  =  -Wall -Wextra -Werror -g -fdiagnostics-color=always
LFLAGS = -L..  -L$(INCLIB) -lXext -lX11 -lm
LIBFT   = libft/libft.a

GFLAGS = -lXext -lX11 -lm 
GPATH = ./minilibx-linux/
MLX_PATH = $(GPATH)/libmlx.a

all:    $(NAME)


libft: extract
	@make -C libft/
	
extract:
	tar -xzvf minilibx-linux.tgz

mlx: extract
	@make -C $(GPATH)

	
$(NAME): libft mlx $(OBJS) $(LIBFT) $(MLX_PATH)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_PATH) $(GFLAGS) -o $(NAME) 
	
%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -Ilibft -c $< -o $@

clean:
	$(RM) $(OBJS)
	@make clean -C libft/
	@make clean -C $(GPATH)

fclean: clean
	$(RM) $(NAME)
	@make fclean -C libft/

re: fclean all

debug: $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -fsanitize=address $(OBJS) -Llibft -lft -o $(NAME)

.PHONY: libft all clean fclean re debug
