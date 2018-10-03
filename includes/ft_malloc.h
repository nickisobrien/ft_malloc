#ifndef __FT_MALLOC
#define __FT_MALLOC

#include <stdio.h>
#include <sys/mman.h>
#include <unistd.h>
# include "../libft/includes/libft.h"

typedef struct		s_global
{
	void *tiny;
	void *small;
	void *large;
}					t_global;
t_global global;

typedef struct		s_block_header
{
	size_t size;
	char allocated;
	char isEnd;
}					block_header;

typedef struct		s_node
{
	void *next;
}					t_node;


#define CHUNK_SIZE (1 << 14)
// block overhead
#define OVERHEAD sizeof(block_header)
// get header from payload pointer (bp = block payload)
#define HDRP(bp) ((char *)(bp) - sizeof(block_header))
// p = block header
#define GET_SIZE(p) ((block_header *)(p))->size
// is allocated?
#define GET_ALLOC(p) ((block_header *)(p))->allocated

#define IS_END(p) ((block_header *)(p))->isEnd
// get next block header (bp = block paylaod)
#define NEXT_BLKP(bp) ((char *)(bp) + GET_SIZE(HDRP(bp)))

#define TINY 100
#define SMALL 4096
// large is anything > SMALL

#define PAGE_SIZE getpagesize()

void	*malloc(size_t size);
void	*init_memory(size_t size, int type);
void	show_alloc_mem();
void	free(void *addr);
void 	*realloc(void *ptr, size_t size);
int		get_type(size_t num);
void	*find_spot(void *ptr, size_t size, int type);

#endif
