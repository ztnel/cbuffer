
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "cbuffer.h"

int main(void) {
  cbuffer_t test_cbuf;
  uint16_t buffer[10];
  cbuffer_init(&test_cbuf, buffer, sizeof(uint16_t), 10);
  for (uint16_t i = 0; i < 9; i++) {
    if (cbuffer_write(&test_cbuf, &i) != CBUFFER_SUCCESS) {
      printf("Failure.\n\r");
      return 1;
    }
  }
  uint16_t *value;
  for (int i = 0; i < 11; i++) {
    value = (uint16_t *)cbuffer_get(&test_cbuf);
    if (value == NULL) {
      printf("No data.\n\r");
    } else {
      printf("%hu\r\n", *value);
    }
  }
}