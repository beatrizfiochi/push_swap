# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bfiochi- <bfiochi-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/02 17:15:19 by bfiochi-          #+#    #+#              #
#    Updated: 2025/02/02 17:59:27 by bfiochi-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
LIBFT = ./libft/libft.a
LIBFT_DIR = ./libft
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = main.c handle_input.c
OBJS = $(SRCS:.c=.o)
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
./SILENT:

