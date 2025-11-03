/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <buehara@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 15:51:35 by buehara           #+#    #+#             */
/*   Updated: 2025/11/02 21:13:37 by buehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_array(t_carray *stack, char *c)
{
	int	ctrl;

	ctrl = 0;
	ft_printf("\nStart\n");
	ft_printf("== Operation : %s ==\n", c);
	while (ctrl < stack->len)
	{
		ft_printf("Number : %d\n", stack->stack[(ctrl + stack->start) % \
			stack->max]);
		ctrl++;
	}
	ft_printf("End\n\n");
}

void	ft_print_list(int *list, int len)
{
	int	i;

	i = 0;
	ft_printf("[");
	while (len > i)
	{
		ft_printf("%d", list[i]);
		i++;
		if (i < len)
			ft_printf(",");
	}
	ft_printf("]\n");
}

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
		m_list->moves = ft_calloc(sizeof(char *), 30);
		ft_print_array(stack, "Before");
		ft_moves(m_list, ft_push(stack, st_b, 'a'));
		ft_moves(m_list, ft_rotate(stack, 'a'));
		ft_moves(m_list, ft_push(stack, st_b, 'a'));
		ft_moves(m_list, ft_swap(stack, 'a'));
		ft_moves(m_list, ft_swap(stack, 'a'));
		ft_moves(m_list, ft_swap(st_b, 'b'));
		ft_moves(m_list, ft_push(stack, st_b, 'b'));
		ft_moves(m_list, ft_push(stack, st_b, 'a'));
		ft_moves(m_list, ft_rotate(st_b, 'b'));
		ft_moves(m_list, ft_rotate(stack, 'a'));
		ft_moves(m_list, ft_rev_rotate(st_b, 'b'));
		ft_moves(m_list, ft_rev_rotate(stack, 'a'));
		ft_moves(m_list, ft_rev_rotate(st_b, 'b'));
		ft_moves(m_list, ft_rotate(st_b, 'b'));
		ft_moves(m_list, ft_rotate(stack, 'a'));
		ft_moves(m_list, ft_rotate(st_b, 'b'));
		ft_moves(m_list, ft_push(stack, stack, 'a'));
		for (int i = 0; i < m_list->len; i++)
			ft_printf("Move : %s\n", m_list->moves[i]);
		ft_print_array(stack, "After");
		free(m_list->moves);
		free(m_list);
		ft_push_free(st_b->stack, st_b);
	}	
}

void	ft_print_move(t_moves *list)
{
	int	i;

	i = 0;
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

int	main(int argc, char **argv)
{
	int			*arg_a;
	int			check;
	int			len;
	t_carray	*stack_a;

	arg_a = NULL;
	len = 0;
	arg_a = ft_parsing(argc, argv, &len);
	if (len < 2)
		ft_error(arg_a, NULL, FALSE);
	check = ft_dup_check(arg_a, len);
	arg_a = ft_copy_better(arg_a, len);
	ft_print_list(arg_a, len);
	stack_a = ft_new_stack(arg_a, len, len);
	if (ft_sorted(stack_a))
		ft_error(stack_a->stack, stack_a, FALSE);
//	ft_test(stack_a, len);
//	ft_push_swap(stack_a);
	ft_print_array(stack_a, "Stack A");
	ft_push_free(stack_a->stack, stack_a);
	return (FALSE);
}
