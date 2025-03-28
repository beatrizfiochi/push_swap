/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiochi- <bfiochi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 12:16:18 by bfiochi-          #+#    #+#             */
/*   Updated: 2025/03/28 13:49:23 by bfiochi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Search, node by node, for the new line
int	found_newline(t_list_gnl *list)
{
	char	*s;

	if (list == NULL)
		return (0);
	while (list != NULL)
	{
		s = list->str_buffer;
		while (*s != '\0')
		{
			if (*s == '\n')
				return (1);
			s++;
		}
		list = list->next;
	}
	return (0);
}

t_list_gnl	*find_lastnode(t_list_gnl *list)
{
	if (list == NULL)
		return (NULL);
	while (list->next != NULL)
		list = list->next;
	return (list);
}

void	copy_str(t_list_gnl *list, char *str)
{
	char	*s;

	while (list != NULL)
	{
		s = list->str_buffer;
		while ((*s != '\0') && (*s != '\n'))
		{
			*str = *s;
			str++;
			s++;
		}
		if (*s == '\n')
		{
			*str = '\n';
			str++;
			*str = '\0';
			return ;
		}
		list = list->next;
	}
	*str = '\0';
}

int	len_line(t_list_gnl *list)
{
	int	i;
	int	len;

	if (list == NULL)
		return (0);
	len = 0;
	while (list != NULL)
	{
		i = 0;
		while ((list->str_buffer[i] != '\0') && (list->str_buffer[i] != '\n'))
		{
			i++;
			len++;
		}
		if (list->str_buffer[i] == '\n')
			return (len + 1);
		list = list->next;
	}
	return (len);
}

// Free the whole list and keep only the clean node
void	dealloc(t_list_gnl **list, t_list_gnl *clean_node)
{
	t_list_gnl	*tmp;

	if (*list == NULL)
		return ;
	while (*list != NULL)
	{
		tmp = (*list)->next;
		free((*list)->str_buffer);
		free(*list);
		*list = tmp;
	}
	*list = NULL;
	if (clean_node->str_buffer[0] != '\0')
		*list = clean_node;
	else
	{
		free(clean_node->str_buffer);
		free(clean_node);
	}
}
