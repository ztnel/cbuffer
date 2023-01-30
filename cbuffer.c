/**
 * @file cbuffer.c
 * @author ztnel (christian911@sympatico.ca)
 * @brief A lightweight circular buffer API
 * @version 0.1
 * @date 2022-10
 *
 * @copyright Copyright © 2022 Christian Sargusingh
 *
 */

#include "cbuffer.h"

#include <assert.h>
#include <stdio.h>
#include <string.h>  // memcpy

// NOTE: internal function no null ptr assertions
static inline uint8_t is_full(cbuffer_t *cb) {
  return ((cb->head + 1) % cb->size) == cb->tail;
}

// NOTE: internal function no null ptr assertions
static inline uint8_t is_empty(cbuffer_t *cb) {
  return cb->tail == cb->head;
}

void cbuffer_init(cbuffer_t *cbuffer, void *buffer, size_t elem_size, size_t size) {
  assert(cbuffer && buffer);
  cbuffer->head = 0;
  cbuffer->tail = 0;
  cbuffer->buffer = buffer;
  cbuffer->size = size;
  cbuffer->elem_size = elem_size;
  printf("Size: %li\n", cbuffer->size);
  printf("Elem Size: %li\n", cbuffer->elem_size);
}

cbuffer_status_t cbuffer_write(cbuffer_t *cbuffer, const void *data) {
  assert(cbuffer);
  if (is_full(cbuffer)) {
    return CBUFFER_OVERFLOW;
  }
  printf("%u\n\r", *(uint16_t *)data);
  size_t index = (cbuffer->head * cbuffer->elem_size) % (cbuffer->size * cbuffer->elem_size);
  printf("Head: %li\n\r", cbuffer->head);
  memcpy(cbuffer->buffer + index, data, cbuffer->elem_size);
  cbuffer->head = (cbuffer->head + 1) % cbuffer->size;
  return CBUFFER_SUCCESS;
}

void *cbuffer_get(cbuffer_t *cbuffer) {
  assert(cbuffer);
  if (is_empty(cbuffer)) {
    return NULL;
  }
  printf("Tail: %li\n\r", cbuffer->tail);
  size_t index = (cbuffer->tail * cbuffer->elem_size) % (cbuffer->size * cbuffer->elem_size);
  void *ret = cbuffer->buffer + index;
  printf("%hu", *(uint16_t *)ret);
  cbuffer->tail = (cbuffer->tail + 1) % cbuffer->size;
  return ret;
}
