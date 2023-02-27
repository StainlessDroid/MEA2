# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/24 18:51:54 by mpascual          #+#    #+#              #
#    Updated: 2023/02/27 18:57:20 by mpascual         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Output Colors
CLR_RMV		:= \033[0m
RED		    := \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m

# Global Config
NAME		= fdf
LNAME		= fdf_linux
LIBFT_DIR	= ./libft
LIBFT		= libft.a
LIBFT_HEAD	= $(LIBFT_DIR)/header.h
HEADER		= fdf.h
SRC_FILES	= fdf.c utils.c read_map.c color.c store_map.c
BONUS_SRC	=

ifdef WITH_BONUS
SRCS = $(SRC_FILES) $(BONUS_SRC)
else
SRCS = $(SRC_FILES)
endif

OBJS			= $(SRCS:.c=.o)
CC				= gcc
CFLAGS			= -Wall -Wextra -Werror

# Flags for minilibx compilation in linux and mac
LFLAGS			= -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
MFLAGS			= -lmlx -framework OpenGL -framework AppKit

all: compile_lib $(NAME)

linux: compile_lib $(LNAME)

$(LNAME): $(OBJS) $(HEADER)
	@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LFLAGS) -L. $(LIBFT_DIR)/$(LIBFT)
	@echo "$(GREEN)$(NAME) created ✓${CLR_RMV}"

$(NAME): $(OBJS) $(HEADER)
	@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
	$(CC) $(CFLAGS) $(OBJS) $(MFLAGS) -o $(NAME) -L. $(LIBFT_DIR)/$(LIBFT)
	@echo "$(GREEN)$(NAME) created ✓${CLR_RMV}"

$(OBJS): $(SRCS)
		$(CC) $(CFLAGS) -c $(SRCS)

compile_lib:
		cd $(LIBFT_DIR) && $(MAKE)

clean:
		rm -rf $(OBJS)
		cd $(LIBFT_DIR) && make clean

fclean: clean
		rm -rf $(LIBFT_DIR)/$(LIBFT)
		rm -rf $(NAME)

bonus:
	$(MAKE) WITH_BONUS=1

norme:
		@norminette $(SRCS) fdf.h

re: fclean all

.PHONY: all re clean fclean
