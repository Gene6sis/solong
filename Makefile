# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adben-mc <adben-mc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/15 00:41:23 by adben-mc          #+#    #+#              #
#    Updated: 2022/01/20 05:48:41 by adben-mc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	srcs/ft_main.c					\
				srcs/ft_sprites.c				\
				srcs/ft_screen.c				\
				srcs/ft_readmap.c				\
				srcs/ft_hooks.c					\
				srcs/ft_get_pixel.c				\
				srcs/ft_check.c					\
				srcs/ft_error.c					\
				gnl/get_next_line.c				\
				gnl/get_next_line_utils.c

SRCS_BONUS	=	srcs/ft_main_bonus.c			\
				srcs/ft_sprites_bonus.c			\
				srcs/ft_screen_bonus.c			\
				srcs/ft_readmap_bonus.c			\
				srcs/ft_hooks_bonus.c			\
				srcs/ft_get_pixel_bonus.c		\
				srcs/ft_check_bonus.c			\
				srcs/ft_error_bonus.c			\
				gnl/get_next_line.c				\
				gnl/get_next_line_utils.c

OBJS		= $(SRCS:.c=.o)
OBJS_BONUS	= $(SRCS_BONUS:.c=.o)

NAME		=	so_long

CC			=	gcc
CFLAGS		= 	-Wall -Werror -Wextra -g3 #-fsanitize=address
MLXFLAGS	= 	-framework OpenGL -framework AppKit

HEADER		=	includes/so_long.h

LIBFT_DIR	=	libft
LIBFT_LIB 	=	$(LIBFT_DIR)/libft.a
LIBFT_FLAG  =   -L libft -lft

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
	$(CC)  $(CFLAGS) $(OBJS) $(MLXFLAGS) $(LIBFT_FLAG) -o $(NAME)
else
	$(CC) $(CFLAGS) $(MLXFLAGS) $(OBJS) $(LIBFT_LIB) $(MLX_LIB) -o $(NAME)
endif

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)

clean:
	$(RM) $(OBJS)
	$(RM) $(OBJS_BONUS)
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(MLX_DIR)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIBFT_LIB)
	$(RM) $(MLX_LIB)

re: fclean all

bonus: $(OBJS_BONUS) $(LIBFT_LIB) $(MLX_LIB)
ifeq ($(shell uname), Linux)
	$(CC)  $(CFLAGS) $(OBJS_BONUS) $(MLXFLAGS) $(LIBFT_FLAG) -o $(NAME)
else
	$(CC) $(CFLAGS) $(MLXFLAGS) $(OBJS_BONUS) $(LIBFT_LIB) $(MLX_LIB) -o $(NAME)
endif

.PHONY: all clean fclean re bonus