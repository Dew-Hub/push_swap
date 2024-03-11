/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_seperations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buonturk <buonturk@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 00:22:30 by buonturk          #+#    #+#             */
/*   Updated: 2024/03/11 13:41:22 by buonturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_quicksort_start(t_stack *stack, int len)
{
	int	pivot_a;
	int	pivot_b;
	int	items;

	items = len;
	ps_getmiddle(&pivot_a, stack->a, len);
	while (len != items / 2 + items % 2)
	{
		if (stack->a[0] < pivot_a && (len--))
			pb(stack, 1);
		else
		{
			ps_getmiddle(&pivot_b, stack->b, stack->size_b);
			if ((stack->b[0] <= pivot_b) && (stack->size_b > 2))
				rr(stack, 1);
			else
				ra(stack, 1);
		}
	}
	ps_quicksort_a(stack, items / 2 + items % 2, 0);
	ps_quicksort_b(stack, items / 2, 0);
}

int	ps_quicksort_a(t_stack *stack, int len, int counter)
{
	int	pivot_a;
	int	items;

	if (ps_issorted(stack->a, len, 'a') == 1)
		return (1);
	if (len == 2)
		return (ps_sort_a(stack));
	else if (len == 3 && stack->size_a == 3)
		return (ps_sortthree(stack));
	else if (len == 3)
		return (ps_sort_a2(stack, len));
	ps_getmiddle(&pivot_a, stack->a, len);
	items = len;
	while (len != items / 2 + items % 2)
	{
		if (stack->a[0] < pivot_a && (len--))
			pb(stack, 1);
		else if (++counter)
			ra(stack, 1);
	}
	while (items / 2 + items % 2 != stack->size_a && counter--)
		rra(stack, 1);
	return (ps_quicksort_a(stack, items / 2 + items % 2, 0),
		ps_quicksort_b(stack, items / 2, 0));
}

int	ps_quicksort_b(t_stack *stack, int len, int counter)
{
	int	pivot_b;
	int	items;

	if (!counter && ps_issorted(stack->b, len, 'b') == 1)
		while (len--)
			pa(stack, 1);
	if (len <= 3)
		return (ps_sort_b(stack, len));
	ps_getmiddle(&pivot_b, stack->b, len);
	items = len;
	while (len != items / 2)
	{
		if (stack->b[0] >= pivot_b && (len--))
			pa(stack, 1);
		else if (++counter)
			rb(stack, 1);
	}
	while (items / 2 != stack->size_b && counter--)
		rrb(stack, 1);
	return (ps_quicksort_a(stack, items / 2 + items % 2, 0),
		ps_quicksort_b(stack, items / 2, 0));
	return (1);
}
