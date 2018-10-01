#include <ft_malloc.h>

void	show_alloc_mem()
{
	void *ptr;
	if (global.tiny)
	{
		printf("TINY: %p\n", global.tiny);
		ptr = global.tiny;
		while (1)
		{
			if (GET_ALLOC(ptr) == 1)
				printf("%p - %p : %lu bytes\n", ptr + OVERHEAD, ptr + OVERHEAD + GET_SIZE(ptr), GET_SIZE(ptr));
			if (IS_END(ptr))
			{
				if ((*(t_node*)(ptr + OVERHEAD + GET_SIZE(ptr))).next)
					ptr = (*(t_node*)(ptr + OVERHEAD + GET_SIZE(ptr))).next;
				else
					break;
			}
			else
				ptr += OVERHEAD + GET_SIZE(ptr);
		}
	}

	if (global.small)
	{
		printf("SMALL: %p\n", global.small);
		ptr = global.small;
		while (1)
		{
			if (GET_ALLOC(ptr) == 1)
				printf("%p - %p : %lu bytes\n", ptr + OVERHEAD, ptr + OVERHEAD + GET_SIZE(ptr), GET_SIZE(ptr));
			if (IS_END(ptr))
			{
				if ((*(t_node*)(ptr + OVERHEAD + GET_SIZE(ptr))).next)
					ptr = (*(t_node*)(ptr + OVERHEAD + GET_SIZE(ptr))).next;
				else
					break;
			}
			else
				ptr += OVERHEAD + GET_SIZE(ptr);
		}
	}

	if (global.large)
	{
		printf("LARGE: %p\n", global.large);
		ptr = global.large;
		while (1)
		{
			if (GET_ALLOC(ptr) == 1)
				printf("%p - %p : %lu bytes\n", ptr + OVERHEAD, ptr + OVERHEAD + GET_SIZE(ptr), GET_SIZE(ptr));
			if (IS_END(ptr))
			{
				if ((*(t_node*)(ptr + OVERHEAD + GET_SIZE(ptr))).next)
					ptr = (*(t_node*)(ptr + OVERHEAD + GET_SIZE(ptr))).next;
				else
					break;
			}
			else
				ptr += OVERHEAD + GET_SIZE(ptr);
		}
	}
}
