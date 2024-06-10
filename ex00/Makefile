# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgosselk <lgosselk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/14 15:46:06 by lgosselk          #+#    #+#              #
#    Updated: 2024/03/22 09:41:30 by lgosselk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	megaphone

DEFAULT	=	\033[0m
RED		=	\033[1;31m
GREEN	=	\033[1;32m
YELLOW	=	\033[1;33m

CC		=	c++
RM		=	rm -rf
SRC		=	megaphone.cpp
CFLAGS	=	-Wall -Werror -Wextra -std=c++98

OBJ	=	$(SRC:.cpp=.o)

all:	$(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)$(NAME) created!$(DEFAULT)"

clean:
	@$(RM) $(OBJ)
	@echo "$(YELLOW)object removed!$(DEFAULT)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)$(NAME) removed!$(DEFAULT)"

re: fclean all

.PHONY: all clean fclean re