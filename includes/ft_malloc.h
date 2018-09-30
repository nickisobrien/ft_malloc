#ifndef __FT_MALLOC
#define __FT_MALLOC

#include <stdio.h>
#include <sys/mman.h>
#include <unistd.h>

// typedef struct	s_node
// {
// 	void *mem;
// 	t_node *next;
// }				t_node;

typedef struct		s_global
{
	void *tiny;
	void *small;
	void *large;
}					t_global;

typedef struct		s_block_header
{
	size_t size;
	char allocated;
}					block_header;


#define CHUNK_SIZE (1 << 14)
#define CHUNK_ALIGN(size) (((size)+(CHUNK_SIZE-1)) & ~(CHUNK_SIZE-1))
// block overhead
#define OVERHEAD sizeof(block_header)
// get header from payload pointer (bp = block payload)
#define HDRP(bp) ((char *)(bp) - sizeof(block_header))
// p = block header
#define GET_SIZE(p) ((block_header *)(p))->size
// is allocated?
#define GET_ALLOC(p) ((block_header *)(p))->allocated
// get next block header (bp = block paylaod)
#define NEXT_BLKP(bp) ((char *)(bp) + GET_SIZE(HDRP(bp)))

#define TINY 100
#define SMALL 4096
// large is anything > SMALL


#define PAGE_SIZE getpagesize()
#endif
