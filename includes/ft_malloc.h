/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 12:18:38 by nobrien           #+#    #+#             */
/*   Updated: 2018/10/04 13:50:23 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_MALLOC_H
# define __FT_MALLOC_H

# include <sys/mman.h>
# include <unistd.h>
# include "../libft/includes/libft.h"

typedef struct		s_global
{
	void *tiny;
	void *small;
	void *large;
}					t_global;

typedef struct		s_block
{
	size_t	size;
	char	allocated;
	char	is_end;
}					t_block;

typedef struct		s_node
{
	void *next;
}					t_node;

# define OVERHEAD sizeof(t_block)
# define HDRP(bp) ((char *)(bp) - sizeof(t_block))
# define GET_SIZE(p) ((t_block *)(p))->size
# define GET_ALLOC(p) ((t_block *)(p))->allocated
# define IS_END(p) ((t_block *)(p))->is_end
# define NEXT_BLKP(bp) ((char *)(bp) + GET_SIZE(HDRP(bp)))
# define TINY 100
# define SMALL 4096
# define PAGE_SIZE getpagesize()

extern t_global		g_global;

void				*malloc(size_t size);
void				show_alloc_mem();
void				free(void *addr);
void				*realloc(void *ptr, size_t size);
int					get_type(size_t num);
void				*find_spot(void *ptr, size_t size, int type);
void				*init_memory(size_t size, int type);

#endif
