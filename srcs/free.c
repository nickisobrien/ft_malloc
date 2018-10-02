#include <ft_malloc.h>

// |16 200 16 30 16 12 void*

void sweep(void *ptr)
{
	while (ptr)
	{
		while (!IS_END(ptr))
			ptr += OVERHEAD + GET_SIZE(ptr);
		t_node *node = (t_node*)(ptr + OVERHEAD + GET_SIZE(ptr));
		if (!node->next)
			break;
		if (GET_ALLOC(node->next) == 0 && IS_END(node->next) == 1)
		{
			void *save = node->next;
			void *next = ((t_node*)(save + GET_SIZE(save) + OVERHEAD))->next;
			((t_node*)(ptr + OVERHEAD + GET_SIZE(ptr)))->next = next;
			if (munmap(save, OVERHEAD + GET_SIZE(save) + sizeof(t_node)) == -1)
				printf("ERROR\n");
		}
		else
			ptr = node->next;
	}
	
}

void free(void *addr)
{
	// need to figure out how to erase a block but also set whatever is pointing at it to either NULL or the blocks next if it exists
	if (!addr)
		return ;
	GET_ALLOC(HDRP(addr)) = 0;
	if (GET_ALLOC(NEXT_BLKP(addr)) == 0)
	{
		// size of next chunk
		IS_END(HDRP(addr)) = IS_END(NEXT_BLKP(addr));
		GET_SIZE(HDRP(addr)) += GET_SIZE(NEXT_BLKP(addr)) + OVERHEAD;
	}
	if (IS_END(HDRP(addr)))
	{
		// sweep(global.small);
		// sweep(global.tiny);
		sweep(global.large);
	}
}
