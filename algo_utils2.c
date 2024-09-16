/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcozigon <gcozigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:31:55 by gcozigon          #+#    #+#             */
/*   Updated: 2023/05/04 15:42:14 by gcozigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	price_rotate(t_all *all, int pa, int pb)
{
	if (pa > 0)
		while (pa-- > 0)
			ft_rotate(all, 'a');
	else if (pa < 0)
		while (pa++ < 0)
			ft_reverse_rotate(all, 'a');
	if (pb > 0)
		while (pb-- > 0)
			ft_rotate(all, 'b');
	else if (pb < 0)
		while (pb++ < 0)
			ft_reverse_rotate(all, 'b');
}

void	push_small_price_leo(t_all *all)
{
	t_stack	*tmp_b;
	int		min_price;
	int		pa;
	int		pb;

	tmp_b = all->stack_b;
	min_price = tmp_b->price;
	pa = tmp_b->price_a;
	pb = tmp_b->price_b;
	while (tmp_b)
	{
		if (tmp_b->price < min_price)
		{
			min_price = tmp_b->price;
			pa = tmp_b->price_a;
			pb = tmp_b->price_b;
		}
		tmp_b = tmp_b->next;
	}
	price_rotate(all, pa, pb);
	ft_push(all, 'a');
}
