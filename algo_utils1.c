/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcozigon <gcozigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:31:31 by gcozigon          #+#    #+#             */
/*   Updated: 2023/05/04 15:41:51 by gcozigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_price_ab(t_all *all, t_stack *tmp_b, int position, int pos_a)
{
	if (pos_a <= (lstsize(all->stack_a) / 2))
		tmp_b->price_a = pos_a;
	else
		tmp_b->price_a = (pos_a - lstsize(all->stack_a));
	if (position <= (lstsize(all->stack_b) / 2))
		tmp_b->price_b = position;
	else
		tmp_b->price_b = (position - lstsize(all->stack_b));
	if (position > all->size_b / 2)
	{
		tmp_b->price_b = (position - all->size_b - 1);
		tmp_b->price_b++;
	}
}

void	get_price(t_all *all)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	int		position;
	int		parent;
	int		pos_a;

	position = 0;
	tmp_b = all->stack_b;
	all->size_b = lstsize(all->stack_b);
	while (tmp_b)
	{
		tmp_a = all->stack_a;
		pos_a = 0;
		parent = ft_get_parent(tmp_b->nb, &all->stack_a);
		while (tmp_a && tmp_a->nb != parent)
		{
			pos_a++;
			tmp_a = tmp_a->next;
		}
		get_price_ab(all, tmp_b, position, pos_a);
		position++;
		ft_pr(&tmp_b);
		tmp_b = tmp_b->next;
	}
}

void	cost_calculator(t_all *all)
{
	t_stack	*tmp;

	tmp = all->stack_b;
	while (tmp && tmp->next)
	{
		tmp->good_nb = ft_good_nb(all, tmp->nb);
		tmp = tmp->next;
	}
}

int	ft_good_nb(t_all *all, int nb)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	int		i;
	int		j;

	tmp_a = all->stack_a;
	tmp_b = all->stack_b;
	tmp_b->good_nb = tmp_a->nb;
	while (tmp_a && tmp_a->next)
	{
		if (!tmp_a->next->nb)
			break ;
		i = tmp_a->nb;
		j = tmp_a->next->nb;
		if (!j)
			return (tmp_b->good_nb);
		if (j - nb < i - nb)
			tmp_b->good_nb = j;
		tmp_a = tmp_a->next;
	}
	return (tmp_b->good_nb);
}

void	find_good_nb(t_all *all, int nb)
{
	all->size_a = lstsize(all->stack_a);
	if (nb < all->size_a / 2)
	{
		while (nb > 0)
		{
			ft_rotate(all, 'a');
			nb--;
		}
	}
	else if (nb > all->size_a / 2)
	{
		while (nb < all->size_a)
		{
			ft_rotate(all, 'a');
			nb++;
		}
	}
}
