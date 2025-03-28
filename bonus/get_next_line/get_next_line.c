/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiochi- <bfiochi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 19:07:39 by bfiochi-          #+#    #+#             */
/*   Updated: 2025/03/28 21:53:32 by bfiochi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// create a list with the content of the file until find new line
void	create_list(t_list_gnl **list, int fd)
{
	char	*buffer;
	int		chars_read;

	buffer = malloc(BUFFER_SIZE + 1);
	if (buffer == NULL)
		return ;
	while (!found_newline(*list))
	{
		chars_read = read(fd, buffer, BUFFER_SIZE);
		if (chars_read <= 0)
		{
			free(buffer);
			return ;
		}
		buffer[chars_read] = '\0';
		add_newnode(list, buffer);
		buffer = malloc(BUFFER_SIZE + 1);
		if (buffer == NULL)
			return ;
	}
	free(buffer);
}

// Find the size until the \n, alloc memory and then copy the content
char	*put_line(t_list_gnl *list)
{
	char	*next_str;
	int		len;

	if (list == NULL)
		return (NULL);
	len = len_line(list);
	next_str = malloc(len + 1);
	if (next_str == NULL)
		return (NULL);
	copy_str(list, next_str);
	return (next_str);
}

// Create a clean node (everything after the \n) and recreate the list
void	polish_list(t_list_gnl **list)
{
	t_list_gnl	*last;
	t_list_gnl	*clean_node;
	int			i;
	int			k;

	clean_node = malloc(sizeof(t_list_gnl));
	if (clean_node == NULL)
		return ;
	clean_node->str_buffer = malloc(BUFFER_SIZE + 1);
	if (clean_node->str_buffer == NULL)
	{
		free(clean_node);
		return ;
	}
	clean_node->next = NULL;
	last = find_lastnode(*list);
	i = 0;
	k = 0;
	while ((last->str_buffer[i] != '\0') && (last->str_buffer[i] != '\n'))
		++i;
	while ((last->str_buffer[i] != '\0') && (last->str_buffer[++i] != '\0'))
		clean_node->str_buffer[k++] = last->str_buffer[i];
	clean_node->str_buffer[k] = '\0';
	dealloc(list, clean_node);
}

// Add a new node at the end of the list
void	add_newnode(t_list_gnl **list, char *buffer)
{
	t_list_gnl	*new_node;
	t_list_gnl	*last_node;

	last_node = find_lastnode(*list);
	new_node = malloc(sizeof(t_list_gnl));
	if (new_node == NULL)
		return ;
	if (last_node == NULL)
		*list = new_node;
	else
		last_node->next = new_node;
	new_node->str_buffer = buffer;
	new_node->next = NULL;
}

char	*get_next_line(int fd)
{
	static t_list_gnl	*list = NULL;
	char				*next_line;

	if ((fd < 0) || (BUFFER_SIZE <= 0) || (read(fd, &next_line, 0) < 0))
		return (NULL);
	create_list(&list, fd);
	if (list == NULL)
		return (NULL);
	next_line = put_line(list);
	polish_list(&list);
	return (next_line);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*new_line;

// 	fd = open("file.txt", O_RDONLY);
// 	new_line = get_next_line(fd);
// 	if (fd < 0)
// 	{
// 		printf("%s", new_line);
// 		return (1);
// 	}
// 	while (new_line)
// 	{
// 		printf("%s", new_line);
// 		free(new_line);
// 		new_line = get_next_line(fd);
// 	}
// 	close(fd);
// 	return (0);
// }
