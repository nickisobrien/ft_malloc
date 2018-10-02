#include <ft_malloc.h>

void sweep(void *ptr)
{
	while (ptr)
	{
		while (!IS_END(ptr))
			ptr += OVERHEAD + GET_SIZE(ptr);
		t_node *nextptr = (t_node*)(ptr + OVERHEAD + GET_SIZE(ptr));
		if (!nextptr->next)
			break;
		if (GET_ALLOC(nextptr->next) == 0 && IS_END(nextptr->next))
		{
			void *save = nextptr->next;
			nextptr = (t_node*)(ptr + OVERHEAD + GET_SIZE(ptr)); // assign currents nextptr to next's nextptr
			ptr = nextptr->next;
			if (!munmap(save, OVERHEAD + GET_SIZE(ptr)))
				printf("ERROR\n");
		}
		else
			ptr = nextptr->next;
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
		sweep(global.small);
		sweep(global.tiny);
		sweep(global.large);
	}
}
