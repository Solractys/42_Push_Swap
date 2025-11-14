/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <buehara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 19:06:47 by buehara           #+#    #+#             */
/*   Updated: 2025/11/13 16:00:51 by buehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/includes/libft.h"
# include "libft/includes/get_next_line.h"
# include "libft/includes/ft_printf.h"
# include <unistd.h>
# include <stdlib.h>

enum e_char
{
	SPACE = 32
};

enum e_stackPosition
{
	POS_UP,
	POS_KEEP,
	POS_DOWN,
	LEN_ADD = 1,
	LEN_MINUS = -1
};

enum e_maskr
{
    PZERO = 64,
    RZERO = 32,
    RSEC = 16,
    SZERO = 8,
    DOUBLE = 4,
    AMASK = 2,
    BMASK = 1
};
	
enum e_maska
{
	PB,
    SA,
    RA,
    RRA,
    SB,
    RB,
    RRB,
    PA,
	TOTALMOVES
};

enum e_maskf
{
	SBCK = 9,
	SACK = 10,
	SSCK = 12,
	RBCK = 33,
	RACK = 34,
	RRCK = 36,
	RRBCK = 49,
	RRACK = 50,
	RRRCK = 52,
	PBCK = 65,
	PACK = 66
};

typedef struct s_moves
{
	int		len;
	int		max;
	char	**moves;
}				t_moves;

typedef struct s_carray
{
	int	len;
	int	start;
	int	end;
	int	max;
	int	*stack;
}				t_carray;

typedef char	*(*t_mfunc)(t_carray *stack_a, t_carray *stack_b); 

// 		Test Functions
void		ft_test(t_carray *stack, int argc);
void		ft_print_array(t_carray *stack, char *c);
void		ft_print_list(t_carray *stack, int len);

//		MAIN
// ============================================================= ||

void		ft_push_swap(t_carray *stack);

// 		Functions Utils
// ============================================================= ||

int			ft_isspace(int c);
int			ft_sorted(t_carray *stack);
int			*ft_copy_better(int *list, int len);
void		ft_error(void *arg, t_carray *stack, int check);
void		ft_push_free(int *arg, t_carray *stack);
void		ft_str_free(char **list);

//		Math Functions
// ============================================================= ||

int			ft_log(int len, int base);

// 		Functions Stacks
// ============================================================= ||

int			ft_before(t_carray *stack);
int			ft_next(t_carray *stack, int index);
void		ft_att_tcarray(t_carray *stack, int start, int end, int len);
t_carray	*ft_new_stack(void *content, int len, int max);

char		*ft_swap(t_carray *stack, char c);
char		*swap_a(t_carray *sta, t_carray *stb);
char		*swap_b(t_carray *sta, t_carray *stb);
void		ft_push(t_carray *stack_a, t_carray *stack_b);
char		*push_a(t_carray *sta, t_carray *stb);
char		*push_b(t_carray *sta, t_carray *stb);
char		*ft_rotate(t_carray *stack, char c);
char		*rotate_a(t_carray *sta, t_carray *stb);
char		*rotate_b(t_carray *sta, t_carray *stb);
char		*ft_rev_rotate(t_carray *stack, char c);
char		*rev_rotate_a(t_carray *sta, t_carray *stb);
char		*rev_rotate_b(t_carray *sta, t_carray *stb);
void		ft_rotate_base(t_carray *stk, char direction);
void		ft_swap_base(t_carray *stk_a, int idx_a, \
						t_carray *stk_b, int idx_b);
int		ft_push_alg(t_moves *list, t_carray *sta, t_carray *stb);

// 		Functions Parsing
// ============================================================= ||

int			ft_check_args(int argc, char **argv);
int			ft_count_int(char **list);
int			ft_digit_check(char **argv);
int			*ft_parsing(int argc, char **argv, int *len);
int			ft_dup_check(int *arg, int n);
char		*ft_rev_split(int n, char **args, char c);

//		Moves List
// ============================================================= ||

int			move_check(char *mov);
int			move_limit(t_moves *list, t_carray *sta);
int			move_dub(int mov, t_moves *list, t_carray *sta, t_carray *stb);
void		ft_print_move(t_moves *list);
void		ft_moves(t_moves *m_list, char *mov);
void		move_return(t_moves *list, t_carray *sta, t_carray *stb);
t_moves		*ft_move_add(int llen);
t_mfunc		func_list(int list);

//		Sort Functions
//============================================================== ||
//---- Utils ------
void		ft_swap_sort(int *a, int *b);
int			ft_bigger(int a, int b);
int			ft_smaller(int a, int b);

//---- Merge Sort ------
void		ft_mer_sort(int *list, int start, int end);
void		ft_mer_utils(int *list, int start, int mid, int end);

//---- Quick Sort ------
int			ft_rearrange(int *list, int pivot, int end);
void		ft_quick_sort(int *list, int pivot, int end);

//---- Heap Sort -------
void		ft_down_the_tree(int *list, int index, int len);
void		ft_heapfy(int *list, int len);
void		ft_heap_sort(int *list, int len);

//---- Shell Sort ------
void		ft_shell_sort(int *list, int len);

//---- Counting Sort ----
int			ft_find_xtreme(int *list, int len, int (*f)(int, int));
void		ft_counting_sort(int *list, int len);

//---- Radix Sort ------
int			**ft_array_radix(int len);
int			ft_find_digits(int *list, int len);
void		ft_radix_sort(int *list, int len);
void		ft_int_free(int **list, int len);

#endif
