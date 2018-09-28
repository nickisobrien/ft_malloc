#include <ft_malloc.h>

void free(void *ptr)
{(void)ptr;

}

void *malloc(size_t size)
{
	void *addr = mmap(0, size, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
	if (addr == MAP_FAILED)
	{
		printf("FAILED\n");
	}
	return (addr);
}

void *realloc(void *ptr, size_t size)
{(void)ptr;(void)size;
	return (NULL);
}

int		main(void)
{
	char *str = (char *)malloc(sizeof(char) * 5);
	for (int i = 0; i < 4; i++)
	{
		str[i] = 'a' + i;
	}
	str[4] = '\0';
	printf("Test %s\n", str);
}
