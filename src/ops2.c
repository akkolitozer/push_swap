/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulescur <hulescur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 19:38:32 by hulescur          #+#    #+#             */
/*   Updated: 2026/02/10 19:41:27 by hulescur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ss(t_stack **a, t_stack **b)
{
	sab(a, 1);
	sab(b, 0);
}

void	rr(t_stack **a, t_stack **b)
{
	rab(a, 1);
	rab(b, 0);
}

void	rrr(t_stack **a, t_stack **b)
{
	rrab(a, 1);
	rrab(b, 0);
}
