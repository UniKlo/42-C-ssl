#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khou <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/22 18:08:35 by khou              #+#    #+#              #
#    Updated: 2019/03/12 18:16:07 by khou             ###   ########.fr        #
#                                                                              #
#******************************************************************************#

C = clang

NAME = ft_ssl

FLAGS = -g -Wall -Wextra -Werror # -fsanitize=address #-g

DIR_H = incl/

DIR_S = srcs/

HEADER = ft_ssl.h

SOURCES = main.c

SRCS = $(addprefix $(DIR_S)/, $(SOURCES))

INCL = -I $(DIR_H)

LIB = -L libft/ -lft


all: $(NAME)

$(NAME): $(SRCS)
	@make -C libft/
	@$(C) $(FLAGS) $(LIB) $(SRCS) $(INCL) -o $(NAME)
	@echo "\033[32mBinary \033[1;32m$(NAME)\033[1;0m\033[32m created.\033[0m"

norme:
	norminette ./libft/
	@echo
	norminette ./$(HEADER)/
	@echo
	norminette ./$(DIR_S)/

clean:
	@make clean -C libft
	@echo "ft_ssl cleaned up objects"

fclean: clean
	@rm -f $(NAME)
	@rm -f *~
	@rm -f \#*\#
	@rm -f incl/*~
	@rm -f incl/\#*\#
	@rm -f srcs/*~
	@rm -f srcs/\#*\#
	@rm -f srcs/.#*
	@rm -f a.out
	@rm -rf *dSYM
	@make fclean -C libft
	@echo "ft_ssl reset"

re: fclean all

.PHONY: fclean re norme all clean
