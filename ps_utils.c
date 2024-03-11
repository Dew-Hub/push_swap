/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buonturk <buonturk@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:43:29 by buonturk          #+#    #+#             */
/*   Updated: 2024/03/11 13:49:51 by buonturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	ps_getmiddle(int *pivot, int *stack_a, int len)
{
	int	c;
	int	*tmp;

	tmp = (int *)malloc(sizeof(int) * len);
	if (!tmp)
		return ;
	c = 0;
	while (c < len)
	{
		tmp[c] = stack_a[c];
		c++;
	}
	ps_bubblesort(tmp, len);
	*pivot = tmp[len / 2];
	free(tmp);
	return ;
}

int	ps_push(t_stack *stack, int len, char is_a_b)
{
	if (is_a_b == 'b')
		pb(stack, 1);
	else
		pa(stack, 1);
	len--;
	return (len);
}

int	ps_atoi(const char *str, char **argv, t_stack *stack, int is_argv)
{
	long	result;
	int		n;

	n = 1;
	result = 0;
	while ((*str >= 9 && *str <= 13) || (*str == 32))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			n = -1;
		str++;
		if (*str == '-' || *str == '+')
			return (0);
	}
	while (*str != 0 && *str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0') * n;
		if (result > 2147483647 || result < -2147483648)
			ps_free(argv, stack, is_argv, 1);
		str++;
	}
	return (result);
}
