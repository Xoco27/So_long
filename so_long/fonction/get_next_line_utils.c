/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfleuret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 09:57:02 by cfleuret          #+#    #+#             */
/*   Updated: 2024/12/06 11:10:28 by cfleuret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

t_list	*ft_lstnew(void *content)
{
	t_list	*c;

	c = malloc(sizeof(*c));
	if (c == NULL)
		return (NULL);
	c->content = content;
	c->next = NULL;
	return (c);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*p;

	p = (*lst);
	if (new == NULL || lst == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	while (p->next != NULL)
	{
		p = p->next;
	}
	p->next = new;
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*p;
	t_list	*l;

	if (lst == NULL)
		return ;
	if (*lst == NULL)
		return ;
	p = *lst;
	l = *lst;
	while (p != NULL)
	{
		l = p->next;
		if (del)
			del(p->content);
		free(p);
		p = l;
	}
	*lst = NULL;
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if ((char)c == '\0')
		return ((char *)s + ft_strlen(s));
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}
