# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adben-mc <adben-mc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/15 00:41:23 by adben-mc          #+#    #+#              #
#    Updated: 2021/12/15 03:01:46 by adben-mc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	srcs/main.c

OBJS		= $(SRCS:.c=.o)

NAME		=	so_long

CC			=	gcc
CFLAGS		= 	-Wall -Werror -Wextra
MLXFLAGS	= 	-framework OpenGL -framework AppKit

HEADER		=	includes/so_long.h

LIBFT_DIR	=	libft
LIBFT_LIB 	=	$(LIBFT_DIR)/libft.a

MLX_DIR		=	mlx
MLX_LIB		=	$(MLX_DIR)/libmlx.a

ifdef LINUX
MLX_DIR		= mlx-linux
MLX_LIB		= $(MLX_DIR)/libmlx_Linux.a
MLXFLAGS	= -lXext -lX11 -lm
CFLAGS 		+= -D LINUX 
endif

all: $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -o $@ -c $<
	
$(NAME): $(OBJS) $(LIBFT_LIB) $(MLX_LIB) $(HEADER)
	$(CC) $(CFLAGS) $(MLXFLAGS) $(OBJS) $(LIBFT_LIB) $(MLX_LIB) -o $(NAME)

$(LIBFT_LIB):
	$(MAKE) bonus -C $(LIBFT_DIR)

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