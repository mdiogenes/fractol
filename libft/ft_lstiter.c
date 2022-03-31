/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoler-e <msoler-e@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 09:45:05 by msoler-e          #+#    #+#             */
/*   Updated: 2022/01/24 15:02:38 by msoler-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*new;
	t_list	*temp;

	if (lst)
	{
		new = lst;
		while (new->next)
		{
			temp = new;
			new = new->next;
			f(temp->content);
		}
		f(new->content);
	}
}
