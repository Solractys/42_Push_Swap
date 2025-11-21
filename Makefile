# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: buehara <buehara@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/01 18:38:10 by buehara           #+#    #+#              #
#    Updated: 2025/11/17 15:35:47 by buehara          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#		Program VARS
# =========================================================================== ||

NAME = push_swap
FLAGS = -Wall -Wextra -Werror -Iincludes -Iincludes/gnl -Iincludes/printf -Iincludes/libft -g3 -I.
CC = cc


#	Sources
# =========================================================================== ||

SRCS = $(shell find -name "*.c")

OBJS = $(SRCS:.c=.o)

#	Recipes
# ========================================================================== ||

all : $(NAME)
	@echo "\n\tCompiling Complete!\n"


$(NAME) : $(OBJS) 
	@$(CC) $(OBJS) -lft -o $@


%.o : %.c
	@$(CC) $(FLAGS) -c $< -o $@
	@echo "\tCompiling -> "$@


$(LIBFT) :
	@$(MAKE) -sC includes/libft/ all
	@$(MAKE) -sC includes/printf/ all
	@echo "\n\tCompiling -> "$@

#	Clean
# ========================================================================== ||

clean:
	@rm -fr $(OBJS)
	@$(MAKE) -sC includes/libft/ $@
	@$(MAKE) -sC includes/printf/ $@
	@echo "\n\tDeleting OBJs"

fclean : clean
	@rm -f $(NAME)
	@$(MAKE) -sC includes/libft/ $@
	@$(MAKE) -sC includes/printf/ $@
	@echo "\tDeleting Files"


re : fclean all


#	.PHONY
# ========================================================================== ||
.PHONY : all clean fclean re
