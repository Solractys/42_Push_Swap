/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <buehara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 15:51:35 by buehara           #+#    #+#             */
/*   Updated: 2025/11/13 20:55:29 by buehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_array(t_carray *stack, char *c)
{
	int	i;
	int start;

	i = 0;
	start = stack->start;
	ft_printf("\nStart\n");
	ft_printf("== Operation : %s ==\n", c);
	while (i < stack->len)
	{
		ft_printf("N : %d\n", stack->stack[start]);
		i++;
		start = (i + stack->start) % stack->max;
	}
	ft_printf("End\n\n");
}

void	ft_print_list(t_carray *stack, int len)
{
	int	i;
	int start;

	i = 0;
	ft_printf("List = [");
	start = stack->start;
	while (len > i)
	{
		ft_printf("%d", stack->stack[start]);
		i++;
		start = (stack->start + i) % stack->max;
		if (i < len)
			ft_printf(",");
	}
	ft_printf("]\n");
}
/*
void ft_test(t_carray *stack, int argc)
{
	t_moves	*m_list;
	t_carray *st_b;
	int	*num;

	if (argc > 1)
	{
		m_list = malloc(sizeof(t_moves));
		num = ft_calloc(sizeof(int), argc);
		st_b = ft_new_stack(num, 0, argc);
		m_list->len = 0;
		m_list->max = 30;
		m_list->moves = ft_calloc(sizeof(char *), 30);
		ft_print_array(stack, "Before");
		
		ft_printf("\nlinha 1\n");
		ft_moves(m_list, push_b(stack, st_b));
		ft_print_list(stack, stack->len);
		ft_print_list(st_b, st_b->len);

		ft_printf("\nlinha 2\n");
		ft_moves(m_list, rotate_a(stack, st_b));
		ft_print_list(stack, stack->len);
		ft_print_list(st_b, st_b->len);

		ft_printf("\nlinha 3\n");
		ft_moves(m_list, rotate_a(stack, st_b));
		ft_print_list(stack, stack->len);
		ft_print_list(st_b, st_b->len);

		ft_printf("\nlinha 4\n");
		ft_moves(m_list, rotate_a(stack, st_b));
		ft_print_list(stack, stack->len);
		ft_print_list(st_b, st_b->len);

		ft_printf("\nlinha 5\n");
		ft_moves(m_list, rotate_a(stack, st_b));
		ft_print_list(stack, stack->len);
		ft_print_list(st_b, st_b->len);

		ft_printf("\nlinha 6\n");
		ft_moves(m_list, rev_rotate_a(stack, st_b));
		ft_print_list(stack, stack->len);
		ft_print_list(st_b, st_b->len);

		ft_printf("\nlinha 7\n");
		ft_moves(m_list, ft_push(stack, st_b, 'b'));
		ft_print_list(stack, stack->len);
		ft_print_list(st_b, st_b->len);

		ft_printf("\nlinha 8\n");
		ft_moves(m_list, ft_push(stack, st_b, 'a'));
		ft_print_list(stack, stack->len);
		ft_print_list(st_b, st_b->len);

		ft_printf("\nlinha 9\n");
		ft_moves(m_list, ft_rotate(st_b, 'b'));
		ft_print_list(st_b, st_b->len);

		ft_printf("\nlinha 10\n");
		ft_moves(m_list, ft_rotate(stack, 'a'));
		ft_print_list(stack, stack->len);
		ft_print_list(st_b, st_b->len);

		ft_printf("\nlinha 11\n");
		ft_moves(m_list, ft_rev_rotate(st_b, 'b'));
		ft_print_list(stack, stack->len);
		ft_print_list(st_b, st_b->len);

		ft_printf("\nlinha 12\n");
		ft_moves(m_list, ft_rev_rotate(stack, 'a'));
		ft_print_list(stack, stack->len);
		ft_print_list(st_b, st_b->len);

		ft_printf("\nlinha 13\n");
		ft_moves(m_list, ft_rev_rotate(st_b, 'b'));
		ft_print_list(stack, stack->len);
		ft_print_list(st_b, st_b->len);

		ft_printf("\nlinha 14\n");
		ft_moves(m_list, ft_rotate(st_b, 'b'));
		ft_print_list(stack, stack->len);
		ft_print_list(st_b, st_b->len);

		ft_printf("\nlinha 15\n");
		ft_moves(m_list, ft_rotate(stack, 'a'));
		ft_print_list(stack, stack->len);
		ft_print_list(st_b, st_b->len);

		ft_printf("\nlinha 16\n");
		ft_moves(m_list, ft_rotate(st_b, 'b'));
		ft_print_list(stack, stack->len);
		ft_print_list(st_b, st_b->len);

		ft_printf("\nlinha 17\n");
		ft_moves(m_list, ft_push(stack, stack, 'a'));
		ft_print_list(stack, stack->len);
		ft_print_list(st_b, st_b->len);

		for (int i = 0; i < m_list->len; i++)
			ft_printf("Move : %s\n", m_list->moves[i]);
		ft_print_array(stack, "After");
		free(m_list->moves);
		free(m_list);
		ft_push_free(st_b->stack, st_b);
	}	
}*/

void	ft_print_move(t_moves *list)
{
	int	i;

	i = 0;
	ft_printf("\nList of Movements : \n");
	while (i < list->len)
	{
		ft_printf("%s\n", list->moves[i]);
		i++;
	}
}

int	ft_find_idx(int *list, int len, int nbr)
{
	int idx;
	int	temp;

	idx = 0;
	temp = list[idx];
	while (idx < len && temp != nbr)
	{
		idx++;
		temp = list[idx];
	}
	return (idx);
}

int	*ft_copy_better(int *list, int len)
{
	int	*cpy;
	int idx;
	int	max;
	int	count;
	int	min;

	cpy = ft_calloc(sizeof(int *), len);
	count = len;
	min = ft_find_xtreme(list, len, ft_smaller);
	if (min == MIN_INT)
	{
		idx = ft_find_idx(list, len, min);
		cpy[idx] = 0;
		count--;
	}
	while (0 < count)
	{
		max = ft_find_xtreme(list, len, ft_bigger);
		idx = ft_find_idx(list, len, max);
		cpy[idx] = count--;
		list[idx] = MIN_INT;
	}
	free(list);
	return (cpy);
}

int	ft_check_args(int argc, char **argv)
{
	int	index;

	index = 1;
	while (index < argc)
	{
		if (argv[index][0] == '\0')
			return (TRUE);
		index++;
	}
	return (FALSE);
}

int	main(int argc, char **argv)
{
	int			*arg_a;
	int			check;
	int			len;
	t_carray	*stack_a;

	if (ft_check_args(argc, argv))
		ft_error(NULL, (t_carray *) NULL, TRUE);
	arg_a = NULL;
	len = 0;
	arg_a = ft_parsing(argc, argv, &len);
	if (len < 2)
		ft_error(arg_a, NULL, FALSE);
	check = ft_dup_check(arg_a, len);
	arg_a = ft_copy_better(arg_a, len);
	stack_a = ft_new_stack(arg_a, len, len);
	if (ft_sorted(stack_a))
		ft_error(stack_a->stack, stack_a, FALSE);
//	ft_test(stack_a, len);
	ft_print_list(stack_a, stack_a->len);
	ft_push_swap(stack_a);
	ft_push_free(stack_a->stack, stack_a);
	return (FALSE);
}
