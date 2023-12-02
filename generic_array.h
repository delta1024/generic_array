#ifndef	  __array_header_h__
#define	  __array_header_h__

#include <stddef.h>

void *array_initialize();
void *array_adjust_for_push(void *array, size_t span);
int array_push(void *array);
int array_pop(void *array);
int array_get_capacity(const void *array);
int array_get_length(const void *array);
void array_set_length(void *array, int length);
void *array_set_capacity(void *array, int capacity, size_t span);
void *array_reset(void *array);
void array_free(void *array);

#endif // __array_header_h__
