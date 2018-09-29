#ifndef __FT_MALLOC
#define __FT_MALLOC

#include <stdio.h>
#include <sys/mman.h>

// typedef struct	s_node
// {
// 	void *ptr;
// 	int size;
// 	t_node *next;
// }				t_node;

// typedef struct	s_lst
// {
// 	t_node *node;
// }				t_lst;

typedef struct {
	size_t size;
	char allocated;
} block_header;

// block overhead
#define OVERHEAD sizeof(block_header)


#endif
