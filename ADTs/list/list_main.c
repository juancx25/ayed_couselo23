#include <stdio.h>
#include <stdlib.h>
#include "list.h"

bool average(t_elem value, int index, void *ctx);

int list_printInt(t_elem value, int index, void *ctx){
  printf("%d ", value);
  return true;
}

int main() {
  list *L = list_new(1024);

  list_insert(L, list_length(L), 1);
  list_insert(L, list_length(L), 2);
  list_insert(L, list_length(L), 3);
  list_insert(L, list_length(L), -2);
  list_insert(L, list_length(L), 4);
  list_insert(L, list_length(L), 5);
  list_insert(L, list_length(L), -5);
  list_insert(L, list_length(L), 6);
  list_insert(L, list_length(L), -2);
  list_insert(L, list_length(L), 7);
  list_insert(L, list_length(L), -1);
  list_insert(L, list_length(L), 8);

  list_traverse(L, list_printInt, NULL);

  int sum = 0;

  list_traverse(L, average, &sum);

  printf("\nElements average: %d\n", sum / list_length(L));
}

bool average(t_elem value, int index, void *ctx) {
  int *sum = ctx;
  *sum += value;
  return true;
}
