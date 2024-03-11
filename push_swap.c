/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buonturk <buonturk@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:37:27 by buonturk          #+#    #+#             */
/*   Updated: 2024/03/11 13:40:11 by buonturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <stdlib.h>

void	ps_push_swap(t_stack *stack, int len)
{
	if (ps_issorted(stack->a, stack->size_a, 'a') == 0)
	{
		if (len == 2)
			sa(stack, 1);
		else if (len == 3)
			ps_sortthree(stack);
		else
			ps_quicksort_start(stack, len);
	}
}

void	ps_allocate(char **argv, int is_argv)
{
	t_stack	*stack;
	int		len;
	int		c;

	c = -1;
	stack = malloc(sizeof(t_stack));
	if (!stack)
		ps_free(argv, stack, is_argv, 1);
	len = ps_argvlen(argv);
	stack->a = malloc(sizeof(int) * len);
	if (!stack->a)
		ps_free(argv, stack, is_argv, 1);
	stack->size_a = len;
	stack->b = malloc(sizeof(int) * len);
	if (!stack->b)
		ps_free(argv, stack, is_argv, 1);
	stack->size_b = 0;
	while (++c < len && ps_isnum(argv[c], argv, stack, is_argv))
		stack->a[c] = ps_atoi(argv[c], argv, stack, is_argv);
	ps_isrepeat(len, argv, stack, is_argv);
	ps_push_swap(stack, len);
	ps_free(argv, stack, is_argv, 0);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		if (!argv)
			exit (1);
		ps_allocate(argv, 1);
		ps_free_argv(argv);
	}
	else
	{
		ps_allocate(++argv, 0);
	}
	return (0);
}
