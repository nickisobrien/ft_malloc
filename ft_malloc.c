/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 20:18:16 by nobrien           #+#    #+#             */
/*   Updated: 2018/10/03 20:13:00 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_malloc.h"

// might be error memory is being left unremoved because realloc can't
// free what was pointed to before if it's passing something else with realloc
// and if im reallocating from something else, should i free that ?
int		main(void)
{
	// void *ptr = malloc(0);
	// void *ptr = NULL;
	// ptr = realloc(ptr, 100);
	// ptr = realloc(ptr, 0);
	// free(ptr);
	// (void)ptr;

// check for when realloc is smaller than malloc
	// char *pptr = (char *)malloc(5000);
	// char *pptr2 = (char *)malloc(5500);
	// char *pptr3 = (char *)malloc(6000);
	// // ptr = (char *)realloc((void *)ptr, sizeof(char) * 7000); // this messes printing memory up but 70000 doesn't
	// for (int i = 0; i < 5000; i++)
		// pptr[i] = 'b';
	// // this should move to smaller memory
	// // pptr = realloc(pptr,7000);
	// (void)pptr3;
	// (void)pptr;
	// (void)pptr2;
	// free(pptr3);

	// printf("%d\n", IS_END(NEXT_BLKP(pptr2)));
	// free(pptr2);
	// pptr2 = (char *)realloc((void*)pptr2, sizeof(char) * 3000);
	// ptr = (char *)realloc((void*)ptr, sizeof(char) * 2000);
	// printf("%zu %d\n", GET_SIZE(NEXT_BLKP(OVERHEAD+NEXT_BLKP(ptr))), IS_END(NEXT_BLKP(ptr)));
	// printf("%c %c\n", ptr[3400], ptr[6500]);

	// void *ptr = malloc(sizeof(char) * 3000);
	// printf("%lu, %d, %c, %lu\n", GET_SIZE(HDRP(ptr)), GET_ALLOC(HDRP(ptr)), ((char*)ptr)[0], GET_SIZE(NEXT_BLKP(ptr)));
	// void *ptr2 = malloc(sizeof(char) * 1000);
	// printf("%lu, %d, %c, %lu\n", GET_SIZE(HDRP(ptr2)), GET_ALLOC(HDRP(ptr2)), ((char*)ptr2)[0], GET_SIZE(NEXT_BLKP(ptr2)));
	// void *ptr3 = malloc(sizeof(char) * 1000);
	// printf("%lu, %d, %c, %lu\n", GET_SIZE(HDRP(ptr3)), GET_ALLOC(HDRP(ptr3)), ((char*)ptr3)[0], GET_SIZE(NEXT_BLKP(ptr3)));
	// void *ptr4 = malloc(sizeof(char) * 1000);
	// printf("%lu, %d, %c, %lu, %d\n", GET_SIZE(HDRP(ptr4)), GET_ALLOC(HDRP(ptr4)), ((char*)ptr4)[0], GET_SIZE(NEXT_BLKP(ptr4)), IS_END(NEXT_BLKP(ptr4)));
	// free(ptr4);
	// free(ptr3);
	// ptr3 = malloc(sizeof(char) * 500); // need to figure out how to ensure that this next_blkp isn't end because it's getting slipped into front of 2nd alloc
	// printf("%lu, %d, %c, %lu, %d\n", GET_SIZE(HDRP(ptr3)), GET_ALLOC(HDRP(ptr3)), ((char*)ptr3)[0], GET_SIZE(NEXT_BLKP(ptr3)), IS_END(NEXT_BLKP(ptr3)));
	// void *ptr5 = malloc(sizeof(char) * 1000); // need to figure out how to ensure that this next_blkp isn't end because it's getting slipped into front of 2nd alloc
	// printf("%lu, %d, %c, %lu, %d\n", GET_SIZE(HDRP(ptr5)), GET_ALLOC(HDRP(ptr5)), ((char*)ptr5)[0], GET_SIZE(NEXT_BLKP(ptr5)), IS_END(NEXT_BLKP(ptr5)));

	// void *ptr = malloc(40);
	// void *ptr4 = malloc(3000);
	// void *ptr2 = malloc(550);
	// void *ptr3 = malloc(3000);
	// void *ptr5 = malloc(110);
	// free(ptr);
	// free(ptr3);
	// // free(ptr5);
	// (void)ptr;(void)ptr2;(void)ptr3; (void)ptr4; (void)ptr5;

	// void *r = malloc(500);
	// void *ptr3 = malloc(2100);
	// void *ptr4 = malloc(2500);


	// ptr = realloc(ptr, 4000);
	// printf("TEST\n");
	// printf("TEST\n");
	// printf("%c\n", ((char*)tr)[1]);
	// show_alloc_mem();
	// printf("\n");
	// free(r);
	// free(tr);
	// free(ptr2);
	// free(ptr4);
	// free(ptr3);
	// free(ptr);
	// free(ptr5);

	// void *ptr1 = malloc(10000);
	// void *apr1 = malloc(10);
	// void *apt1 = malloc(444);
	// void *atr1 = malloc(1000);
	// void *aar1 = malloc(100000);
	// void *aat1 = malloc(555);
	// void *ptr2 = malloc(10000);
	// void *apr2 = malloc(10);
	// void *apt2 = malloc(444);
	// void *atr2 = malloc(1000);
	// void *aar2 = malloc(100000);
	// void *aat2 = malloc(555);
	// void *ptr3 = malloc(10000);
	// void *apr3 = malloc(10);
	// void *apt3 = malloc(444);
	// void *atr3 = malloc(1000);
	// void *aar3 = malloc(100000);
	// void *aat3 = malloc(555);
	// void *ptr4 = malloc(10000);
	// void *apr4 = malloc(10);
	// void *apt4 = malloc(444);
	// void *atr4 = malloc(1000);
	// void *aar4 = malloc(100000);
	// void *aat4 = malloc(555);
	// void *ptr5 = malloc(10000);
	// void *apr5 = malloc(10);
	// void *apt5 = malloc(444);
	// void *atr5 = malloc(1000);
	// void *aar5 = malloc(100000);
	// void *aat5 = malloc(555);
	// void *ptr6 = malloc(10000);
	// void *apr6 = malloc(10);
	// void *apt6 = malloc(444);
	// void *atr6 = malloc(1000);
	// void *aar6 = malloc(100000);
	// void *aat6 = malloc(555);
	// void *ptr7 = malloc(10000);
	// void *apr7 = malloc(10);
	// void *apt7 = malloc(444);
	// void *atr7 = malloc(1000);
	// void *aar7 = malloc(100000);
	// void *aat7 = malloc(555);
	// show_alloc_mem();
	// free(ptr1);
	// free(apr1);
	// free(apt1);
	// free(atr1);
	// free(aar1);
	// free(aat1);
	// free(ptr2);
	// free(apr2);
	// free(apt2);
	// free(atr2);
	// free(aat2);
	// free(aar2);
	// free(ptr3);
	// free(apr3);
	// free(apt3);
	// free(atr3);
	// free(aar3);
	// free(aat3);
	// free(ptr4);
	// free(apr4);
	// free(apt4);
	// free(atr4);
	// free(aar4);
	// free(aat4);
	// free(ptr5);
	// free(apr5);
	// free(apt5);
	// free(atr5);
	// free(aar5);
	// free(aat5);
	// free(ptr6);
	// free(apr6);
	// free(apt6);
	// free(atr6);
	// free(aat6);
	// free(aar6);
	// free(ptr7);
	// free(apr7);
	// free(apt7);
	// free(atr7);
	// free(aar7);
	// free(aat7);















































	// void *ptr = NULL;
	// ptr = realloc(ptr, 100);
	// free(ptr);

	// void *ptr = malloc(40000);
	// void *ptr2 = malloc(25000);
	// void *ptr3 = malloc(30000);
	// free(ptr);
	// (void)ptr;(void)ptr2;(void)ptr3;

	// void *ptr;
	// for (int i = 0; i < 6; i++)
	// {
	// 	ptr = malloc(sizeof(char) * 20);
	// 	// printf("%zu %d\mn", GET_SIZE(NEXT_BLKP(ptr)), IS_END(NEXT_BLKP(ptr)));
	// 	(void)ptr;
	// 	free(ptr);
	// }
	// for (int i = 0; i < 4; i++)
	// {
	// 	ptr = malloc(sizeof(char) * 200);
	// 	// printf("%zu %d\mn", GET_SIZE(NEXT_BLKP(ptr)), IS_END(NEXT_BLKP(ptr)));
	// 	(void)ptr;
	// 	free(ptr);
	// }
	// for (int i = 0; i < 2; i++)
	// {
	// 	ptr = malloc(sizeof(char) * 8000);
	// 	// printf("%zu %d\mn", GET_SIZE(NEXT_BLKP(ptr)), IS_END(NEXT_BLKP(ptr)));
	// 	(void)ptr;
	// 	free(ptr);
	// }
	// sleep(10);
	show_alloc_mem();
}
