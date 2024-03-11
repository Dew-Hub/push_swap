/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_is_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buonturk <buonturk@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:29:28 by buonturk          #+#    #+#             */
/*   Updated: 2024/03/06 17:42:06 by buonturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	ps_isnum(char *num, char **argv, t_stack *stack, int is_argv)
{
	int	c;

	c = 0;
	if (num[c] == '-')
		c++;
	if (num[c] == '\0')
		ps_free(argv, stack, is_argv, 1);
	while (num[c])
	{
		if (!(ft_isdigit(num[c])))
			ps_free(argv, stack, is_argv, 1);
		c++;
	}
	return (1);
}

void	ps_isrepeat(int size, char **argv, t_stack *stack, int is_argv)
{
	int	c;
	int	i;

	c = 0;
	i = 1;
	while (c < size)
	{
		while (i < size)
		{
			if (stack->a[c] == stack->a[i])
				ps_free(argv, stack, is_argv, 1);
			i++;
		}
		c++;
		i = c + 1;
	}
}

int	ps_argvlen(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}

int	ps_issorted(int *stack_ab, int len, char is_a_b)
{
	int	i;

	i = 0;
	while ((is_a_b == 'a') && (++i < len))
	{
		if (stack_ab[i - 1] > stack_ab[i])
			return (0);
	}
	while ((is_a_b == 'b') && (++i < len))
	{
		if (stack_ab[i - 1] < stack_ab[i])
			return (0);
	}
	return (1);
}
