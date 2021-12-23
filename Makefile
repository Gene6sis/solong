# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adben-mc <adben-mc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/15 00:41:23 by adben-mc          #+#    #+#              #
#    Updated: 2021/12/23 01:28:37 by adben-mc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	srcs/main.c						\
				srcs/ft_sprites.c				\
				srcs/ft_screen.c				\
				srcs/ft_readmap.c				\
				srcs/ft_hooks.c					\
				srcs/ft_get_pixel.c				\
				srcs/ft_check.c					\
				gnl/get_next_line.c				\
				gnl/get_next_line_utils.c

OBJS		= $(SRCS:.c=.o)

NAME		=	so_long

CC			=	gcc
CFLAGS		= 	-Wall -Werror -Wextra -fsanitize=address
MLXFLAGS	= 	-framework OpenGL -framework AppKit

HEADER		=	includes/so_long.h

LIBFT_DIR	=	libft
LIBFT_LIB 	=	$(LIBFT_DIR)/libft.a

MLX_DIR		=	mlx
MLX_LIB		=	$(MLX_DIR)/libmlx.a

ifeq ($(shell uname), Linux)
MLX_DIR		= 	mlx_linux
MLX_LIB		= 	$(MLX_DIR)/libmlx_Linux.a
MLXFLAGS	=  -Lmlx_linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -Imlx_linux
CFLAGS 		+= 	-D LINUX 
endif

all: $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -o $@ -c $<
	
$(NAME): $(OBJS) $(LIBFT_LIB) $(MLX_LIB)
ifeq ($(shell uname), Linux)
	$(CC)  $(CFLAGS) $(OBJS) $(MLXFLAGS) -o $(NAME)
else
	$(CC) $(CFLAGS) $(MLXFLAGS) $(OBJS) $(LIBFT_LIB) $(MLX_LIB) -o $(NAME)
endif

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)

clean:
	$(RM) $(OBJS)
	$(RM) $(BONUS_OBJS)
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(MLX_DIR)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIBFT_LIB)
	$(RM) $(MLX_LIB)

re: fclean all

.PHONY: all clean fclean re bonus