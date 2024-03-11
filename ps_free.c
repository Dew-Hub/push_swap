/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buonturk <buonturk@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:40:19 by buonturk          #+#    #+#             */
/*   Updated: 2024/03/11 14:05:52 by buonturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdlib.h>

void	ps_free(char **argv, t_stack *stack, int is_argv, int is_error)
{
	if (is_argv)
		ps_free_argv(argv);
	if (stack->a)
		free (stack->a);
	if (stack->b)
		free (stack->b);
	if (stack)
		free (stack);
	if (is_error)
		write(2, "Error\n", 6);
	exit (1);
}

void	ps_free_argv(char **argv)
{
	int	c;

	c = 0;
	while (argv[c])
		free(argv[c++]);
	free(argv);
}
