#ifndef	  __array_header_h__
#define	  __array_header_h__

#include <stddef.h>
/** 
   Initializes array metadata and returns a handle to the array
   header.  It is unsafe to try access the memory pointed to by the
   returned ptr until you have called array_adjust_for_push(void *,size_t)
   at least once.
 */
void *array_initialize();
/**
    Check and expand capacity to ensure it is safe to index the array
    with array_push(void *array).
    returns the new buffer.
 */
void *array_adjust_for_push(void *array, size_t span);
/** returns the current index and increments the length value in the arrays header. */
int array_push(void *array);
/** decrements the arrays length value in the header the returns the updated value. */
int array_pop(void *array);
/** returns array capacity */
int array_get_capacity(const void *array);
/** returns arrays length */
int array_get_length(const void *array);
/** Provided the new length is less than the arrays capacity, update the arrays length. */
void array_set_length(void *array, int length);
/** returns the updated ptr with the given capacity */
void *array_set_capacity(void *array, int capacity, size_t span);
/** frees the arrays buffer and returns a fresh handle */
void *array_reset(void *array);
void array_free(void *array);

#endif // __array_header_h__
