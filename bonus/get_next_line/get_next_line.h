/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiochi- <bfiochi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 11:57:05 by bfiochi-          #+#    #+#             */
/*   Updated: 2025/03/28 21:54:54 by bfiochi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10

# endif

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

// Structure of my linked list
typedef struct s_list_gnl
{
	char				*str_buffer;
	struct s_list_gnl	*next;
}	t_list_gnl;

int			found_newline(t_list_gnl *list);
int			len_line(t_list_gnl *list);

char		*get_next_line(int fd);
char		*put_line(t_list_gnl *list);

void		create_list(t_list_gnl **list, int fd);
void		add_newnode(t_list_gnl **list, char *buffer);
void		copy_str(t_list_gnl *list, char *str);
void		polish_list(t_list_gnl **list);
void		dealloc(t_list_gnl **list, t_list_gnl *clean_node);

t_list_gnl	*find_lastnode(t_list_gnl *list);

#endif
