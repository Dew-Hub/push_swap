/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buonturk <buonturk@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:43:01 by buonturk          #+#    #+#             */
/*   Updated: 2024/03/11 14:00:33 by buonturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stack
{
	int		*a;
	int		*b;
	int		size_a;
	int		size_b;
	char	**av;
}	t_stack;

void		ps_push_swap(t_stack *stack, int len);

char		**ft_split(char const *s, char c);
int			ps_argvlen(char **argv);

int			ps_isnum(char *num, char **argv, t_stack *stack, int is_argv);
void		ps_isrepeat(int size, char **argv, t_stack *stack, int is_argv);
int			ps_issorted(int *stack_ab, int len, char is_a_b);

void		ps_free(char **av, t_stack *stack, int is_av, int is_error);
void		ps_free_argv(char **argv);

int			ps_sortthree(t_stack *s);
void		ps_bubblesort(int *stack, int size);
int			ps_sort_a(t_stack *stack);
int			ps_sort_a2(t_stack *stack, int len);
int			ps_sort_b(t_stack *stack, int len);

void		ps_getmiddle(int *pivot, int *stack_a, int len);
int			ps_push(t_stack *stack, int len, char is_a_b);
int			ps_atoi(const char *str, char **argv, t_stack *stack, int is_argv);

void		ps_quicksort_start(t_stack *stack, int len);
int			ps_quicksort_a(t_stack *stack, int len, int counter);
int			ps_quicksort_b(t_stack *stack, int len, int counter);

void		pa(t_stack *s, int is_print);
void		pb(t_stack *s, int is_print);
void		sa(t_stack *s, int is_print);
void		sb(t_stack *s, int is_print);
void		ss(t_stack	*s, int is_print);
void		ra(t_stack *s, int is_print);
void		rb(t_stack *s, int is_print);
void		rr(t_stack	*s, int is_print);
void		rra(t_stack *s, int is_print);
void		rrb(t_stack *s, int is_print);
#endif