# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgollong <lgollong@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/16 14:26:59 by lgollong          #+#    #+#              #
#    Updated: 2022/09/30 17:52:14 by lgollong         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = main.c \
		error.c \
		init.c \
		utils.c \
		execute.c \

OBJ = $(SRC:%.c=%.o)

GREEN 	= \033[32;1m
RED		= \033[31;1m
END 	= \033[0m

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN) [✓] philo compiled$(END)"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@echo "$(RED) [x] objs deleted$(END)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED) [x] philo deleted$(END)"

re:	fclean all