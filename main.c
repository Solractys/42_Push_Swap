/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <buehara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 15:51:35 by buehara           #+#    #+#             */
/*   Updated: 2025/11/20 19:36:26 by buehara          ###   ########.fr       */
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
			ft_printf(" ");
	}
	ft_printf("]\n");
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
	if (ft_sorted(stack_a, ft_bigger))
		ft_error(stack_a->stack, stack_a, FALSE);
	ft_push_swap(stack_a);
	ft_push_free(stack_a->stack, stack_a);
	return (FALSE);
}
