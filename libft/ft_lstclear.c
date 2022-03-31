/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoler-e <msoler-e@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 09:44:37 by msoler-e          #+#    #+#             */
/*   Updated: 2022/01/24 12:24:28 by msoler-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*new;
	t_list	*temp;

	if (lst && *lst)
	{
		new = *lst;
		while (new->next)
		{	
			temp = new;
			new = new->next;
			del(temp->content);
			free(temp);
		}
		del(new->content);
		free(new);
		*lst = 0;
	}
}
