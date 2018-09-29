#ifndef __FT_MALLOC
#define __FT_MALLOC

#include <stdio.h>
#include <sys/mman.h>

typedef struct	s_node
{
	void *memory;
	int size;
}				t_node;

typedef struct	s_lst
{
	t_node *head;
}				t_lst;

#endif
