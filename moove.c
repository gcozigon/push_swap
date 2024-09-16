/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcozigon <gcozigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 18:02:34 by gcozigon          #+#    #+#             */
/*   Updated: 2023/05/04 17:39:24 by gcozigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_all *all, char c)
{
	int	tmp;

	if (c == 'a' && all->stack_a->next && all->stack_a)
	{
		tmp = all->stack_a->nb;
		all->stack_a->nb = all->stack_a->next->nb;
		all->stack_a->next->nb = tmp;
		ft_printf("sa\n");
	}
	if (c == 'b' && all->stack_b->next && all->stack_b)
	{
		tmp = all->stack_b->nb;
		all->stack_b->nb = all->stack_b->next->nb;
		all->stack_b->next->nb = tmp;
		ft_printf("sb\n");
	}
}

void	ft_push(t_all *all, char c)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (c == 'a' && all->stack_b)
	{
		tmp = all->stack_b;
		all->stack_b = all->stack_b->next;
		tmp2 = all->stack_a;
		all->stack_a = tmp;
		all->stack_a->next = tmp2;
		ft_printf("pa\n");
	}
	if (c == 'b' && all->stack_a)
	{
		tmp = all->stack_a;
		all->stack_a = all->stack_a->next;
		tmp2 = all->stack_b;
		all->stack_b = tmp;
		all->stack_b->next = tmp2;
		ft_printf("pb\n");
	}
}

void	ft_rotate(t_all *all, char c)
{
	t_stack	*tmp;

	if (c == 'a' && all->stack_a)
	{
		tmp = laststack(all->stack_a);
		tmp->next = (all->stack_a);
		all->stack_a = all->stack_a->next;
		tmp->next->next = NULL;
		ft_printf("ra\n");
	}
	if (c == 'b' && all->stack_b)
	{
		tmp = laststack(all->stack_b);
		tmp->next = (all->stack_b);
		all->stack_b = all->stack_b->next;
		tmp->next->next = NULL;
		ft_printf("rb\n");
	}
}

void	ft_reverse_rotate(t_all *all, char c)
{
	t_stack	*first;
	t_stack	*tmp;
	t_stack	*last;

	if (c == 'a' && all->stack_a)
	{
		tmp = all->stack_a;
		first = tmp;
		while (tmp->next->next)
			tmp = tmp->next;
		last = tmp->next;
		tmp->next = 0;
		add_front(&all->stack_a, last);
	}
	if (c == 'b' && all->stack_b)
	{
		tmp = all->stack_b;
		first = tmp;
		while (tmp->next->next)
			tmp = tmp->next;
		last = tmp->next;
		tmp->next = 0;
		add_front(&all->stack_b, last);
	}
	ft_printf("rr%c\n", c);
}
