/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_ab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buonturk <buonturk@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 20:25:44 by buonturk          #+#    #+#             */
/*   Updated: 2024/03/06 14:40:47 by buonturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	ss(t_stack	*s, int is_print)
{
	sa(s, 0);
	sb(s, 0);
	if (is_print)
		write(1, "ss\n", 3);
}

void	rr(t_stack	*s, int is_print)
{
	ra(s, 0);
	rb(s, 0);
	if (is_print)
		write(1, "rr\n", 3);
}

void	rrr(t_stack	*s, int is_print)
{
	rra(s, 0);
	rrb(s, 0);
	if (is_print)
		write(1, "rrr\n", 4);
}
