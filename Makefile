# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: buehara <buehara@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/01 18:38:10 by buehara           #+#    #+#              #
#    Updated: 2025/11/06 16:46:10 by buehara          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#		Program VARS
# =========================================================================== ||

NAME = push_swap
 
FLAGS = -Wall -Wextra -Werror -g3 -I.

CC = cc


#	Sources
# =========================================================================== ||

SRCS = \
	push_swap.c				\
	push_swap_base.c		\
	push_stack.c			\
	push_rotate.c			\
	push_parsing.c			\
	push_parsing_utils.c	\
	push_push.c				\
	push_sort.c				\
	push_sort_utils.c		\
	push_merge.c			\
	push_qsort.c			\
	push_heap_sort.c		\
	push_shell_sort.c		\
	push_count_sort.c		\
	push_radix_sort.c		\
	push_rev_rotate.c		\
	push_move.c				\
	main.c
	

OBJS = $(SRCS:.c=.o)

LIBFT = libft/libft.a


#	Recipes
# ========================================================================== ||

all : $(NAME)
	@echo "\n\tCompiling Complete!\n"


$(NAME) : $(LIBFT) $(OBJS) 
	@$(CC) $(OBJS) -Llibft -lft -o $@


%.o : %.c
	@$(CC) $(FLAGS) -c $< -o $@
	@echo "\tCompiling -> "$@


$(LIBFT) :
	@$(MAKE) -sC libft/ all
	@echo "\n\tCompiling -> "$@

#	Clean
# ========================================================================== ||

clean:
	@rm -fr $(OBJS)
	@$(MAKE) -sC libft/ $@
	@echo "\n\tDeleting OBJs"

fclean : clean
	@rm -f $(NAME)
	@$(MAKE) -sC libft/ $@
	@echo "\tDeleting Files"


re : fclean all


#	.PHONY
# ========================================================================== ||
.PHONY : all clean fclean re
