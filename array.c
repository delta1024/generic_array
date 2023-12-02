#include "array.h"
#include <stdlib.h>
#include <stdint.h>

typedef struct {
  uint8_t capacity;
  uint8_t length;
} array_header_t;

void *array_initialize() {
  array_header_t *header = malloc(sizeof(array_header_t));
  header->capacity = header->length = 0;
  return (void*)(header + 1);
}
 
void *array_adjust_for_push(void *array, size_t span) {
  array_header_t *header = ((array_header_t*)array) - 1;
  if (header->length + 1 > header->capacity) {
    int old_capacity = header->capacity;
    int new_capacity = old_capacity < 8 ? 8 : old_capacity * 2;
    array_header_t *new_header = realloc(header, (new_capacity * span) + sizeof(array_header_t));
    new_header->capacity = new_capacity;
    return (void*)(new_header + 1);
  }
  return array;
}

int array_push(void *array){
  array_header_t *header = ((array_header_t*)array) - 1;
  return header->length++;
}

int array_pop(void *array){
  array_header_t *header = ((array_header_t*)array) - 1;
  return --header->length;
}

int array_get_capacity(const void *array){
  const array_header_t *header = ((const array_header_t*)array) - 1;
  return header->capacity;
}

int array_get_length(const void *array){
  const array_header_t *header = ((const array_header_t*)array) - 1;
  return header->length;
}

void array_set_length(void *array, int length){
    array_header_t *header = ((array_header_t*)array) - 1;
    if (header->capacity > length) {
      header->length = length;      
    } else {
      // TODO: return an error here if capacity is less than requested length.
    }
    
}

void *array_set_capacity(void *array, int capacity, size_t span){
  array_header_t *header = ((array_header_t*)array) - 1;
  array_header_t *new_header = realloc(header, (capacity * span) + sizeof(array_header_t));
  new_header->capacity = capacity;
  return (void*)(new_header + 1);
}
void *array_reset(void *array) {
    array_header_t *header = ((array_header_t*)array) - 1;
    header = realloc(header, sizeof(array_header_t));
    return (void*)(header + 1);
}
void array_free(void *array){
  array_header_t *header = ((array_header_t*)array) - 1;
  free(header);
}
