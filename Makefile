# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bfiochi- <bfiochi-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/02 17:15:19 by bfiochi-          #+#    #+#              #
#    Updated: 2025/04/03 13:40:55 by bfiochi-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
LIBFT = ./libft/libft.a
LIBFT_DIR = ./libft
CC = cc
CFLAGS = -Wall -Wextra -Werror -ggdb
SRCS = main.c handle_input.c utils.c inicializing_stacks.c swap.c push.c\
		rotate.c reverse_rotate.c two_and_three.c sort.c find_targets.c\
		utils_calc.c costs_calc.c execute_step.c execute_final_steps.c\
		utils_steps.c
OBJS = $(SRCS:.c=.o)
RM = rm -rf
CHECKER = checker
SRCS_BONUS = ./bonus/checker_bonus.c ./bonus/get_next_line/get_next_line.c\
				./bonus/get_next_line/get_next_line_utils.c
OBJS_BONUS = $(SRCS_BONUS:.c=.o)
OBJS_NO_MAIN = $(filter-out main.o, $(OBJS))

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

bonus: $(CHECKER)

$(CHECKER): $(OBJS_NO_MAIN) $(OBJS_BONUS)
	$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) -o $(CHECKER) $(OBJS_NO_MAIN) $(OBJS_BONUS) $(LIBFT)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(NAME) $(CHECKER)

re: fclean all

.PHONY: all clean fclean re
