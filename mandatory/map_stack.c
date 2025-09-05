/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeblee <jaeblee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 16:53:29 by seungbel          #+#    #+#             */
/*   Updated: 2024/09/17 16:26:08 by jaeblee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "parse.h"

void	init_stack(t_stack *stack)
{
	stack->top = NULL;
}

int	isempty(t_stack *stack)
{
	return (stack->top == NULL);
}

void	push(t_stack *stack, int row, int col)
{
	t_node	*newnode;

	newnode = (t_node *)malloc(sizeof(t_node));
	newnode->mat.row = row;
	newnode->mat.col = col;
	newnode->next = stack->top;
	stack->top = newnode;
}

t_mat	pop(t_stack *stack)
{
	t_node	*tmp;
	t_mat	pop_mat;

	if (isempty(stack))
		exit(1);
	tmp = stack->top;
	pop_mat = tmp->mat;
	stack->top = stack->top->next;
	free(tmp);
	tmp = NULL;
	return (pop_mat);
}
