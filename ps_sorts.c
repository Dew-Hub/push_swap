/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sorts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buonturk <buonturk@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 00:28:29 by buonturk          #+#    #+#             */
/*   Updated: 2024/03/11 13:49:43 by buonturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_sortthree(t_stack *s)
{
	if (s->a[0] > s->a[1] && s->a[0] < s->a[2] && s->a[1] < s->a[2])
		sa(s, 1);
	if (s->a[0] > s->a[1] && s->a[0] > s->a[2] && s->a[1] > s->a[2])
	{
		sa(s, 1);
		rra(s, 1);
	}
	if (s->a[0] > s->a[1] && s->a[0] > s->a[2] && s->a[1] < s->a[2])
		ra(s, 1);
	if (s->a[0] < s->a[1] && s->a[0] < s->a[2] && s->a[1] > s->a[2])
	{
		sa(s, 1);
		ra(s, 1);
	}
	if (s->a[0] < s->a[1] && s->a[0] > s->a[2] && s->a[1] > s->a[2])
		rra(s, 1);
	return (1);
}

void	ps_bubblesort(int *stack, int len)
{
	int	i;
	int	c;
	int	tmp;

	i = 0;
	while (i < len)
	{
		c = i + 1;
		while (c < len)
		{
			if (stack[i] > stack[c])
			{
				tmp = stack[i];
				stack[i] = stack[c];
				stack[c] = tmp;
			}
			c++;
		}
		i++;
	}
}

int	ps_sort_a(t_stack *stack)
{
	if (stack->a[0] > stack->a[1])
	{
		if (stack->b[0] < stack->b[1])
			ss(stack, 1);
		else
			sa(stack, 1);
	}
	return (1);
}

int	ps_sort_a2(t_stack *stack, int len)
{
	while (len != 3 || !(stack->a[0] < stack->a[1]
			&& stack->a[1] < stack->a[2]))
	{
		if (len == 3 && stack->a[0] > stack->a[1] && stack->a[2])
		{
			if ((stack->a[0] > stack->a[1]) && (stack->b[0] < stack->b[1]))
				ss(stack, 1);
			else
				sa(stack, 1);
		}
		else if (len == 3 && !(stack->a[2] > stack->a[0]
				&& stack->a[2] > stack->a[1]))
			len = ps_push(stack, len, 'b');
		else if (stack->a[0] > stack->a[1])
			sa(stack, 1);
		else if (len++)
			pa(stack, 1);
	}
	return (1);
}

int	ps_sort_b(t_stack *stack, int len)
{
	if (len == 2)
	{
		if (stack->b[0] < stack->b[1])
			sb(stack, 1);
		pa(stack, 1);
		pa(stack, 1);
	}
	else if (len == 3)
	{
		while (len || !(stack->a[0] < stack->a[1] && stack->a[1] < stack->a[2]))
		{
			if (len == 1 && stack->a[0] > stack->a[1])
				sa(stack, 1);
			else if (len == 1 || (len >= 2 && stack->b[0] > stack->b[1])
				|| (len == 3 && stack->b[0] > stack->b[2]))
				len = ps_push(stack, len, 'a');
			else
				sb(stack, 1);
		}
	}
	return (1);
}
