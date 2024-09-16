/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_nb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcozigon <gcozigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 12:33:23 by gcozigon          #+#    #+#             */
/*   Updated: 2023/05/04 18:44:28 by gcozigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_nb(t_all *all)
{
	all->size_a = lstsize(all->stack_a);
	if (check_double(all->stack_a) == 0)
		return (0);
	if (all->size_a == 2)
		ft_swap(all, 'a');
	if (all->size_a == 3)
		algo_3(all);
	if (all->size_a == 4 || all->size_a == 5)
		algo_5(all);
	if (all->size_a > 5)
		algo_n(all);
	return (1);
}

int	check_double(t_stack *stack_a)
{
	t_stack	*x;

	while (stack_a)
	{
		x = stack_a->next;
		while (x)
		{
			if (stack_a->nb == x->nb)
				return (ft_printf("Error\nthey are double\n"), 0);
			x = x->next;
		}
		stack_a = stack_a->next;
	}
	return (1);
}
