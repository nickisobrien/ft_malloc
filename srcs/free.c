#include <ft_malloc.h>

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
}