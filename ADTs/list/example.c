#include "list.h"
#include "queue.h"
#include <stdio.h>

/*
  Una cola de enteros almacena las operaciones pendientes sobre una lista
  de números naturales, las cuales se codifican de la siguiente manera:
    - Si el número es positivo, debe ser insertado al final de la lista
    - Si el número es negativo, su opuesto debe ser eliminado de la lista
  Desarrollar una función que reciba como parámetros la cola y la lista y
  realice las operaciones pendientes
*/

list *create_list();
queue *create_queue();
bool print_list(t_elem value, int index, void *ctx);
void do_operations(list *L, queue *q);

int main()
{
  list *L = create_list();
  queue *q = create_queue();
  do_operations(L, q);

  return 0;
}


list *create_list() {
  return list_new(1024);
}

queue *create_queue()
{
  queue *q = queue_new(1024);

  enqueue(q, 1);  // 1
  enqueue(q, 2);  // 1, 2
  enqueue(q, 3);  // 1, 2, 3
  enqueue(q, -2); // 1, 3
  enqueue(q, 4);  // 1, 3, 4
  enqueue(q, 5);  // 1, 3, 4, 5
  enqueue(q, -5); // 1, 3, 4
  enqueue(q, 6);  // 1, 3, 4, 6
  enqueue(q, -2); // 1, 3, 4, 6
  enqueue(q, 7);  // 1, 3, 4, 6, 7
  enqueue(q, -1); // 3, 4, 6, 7
  enqueue(q, 8);  // 3, 4, 6, 7, 8
}

bool print_list(t_elem elem, int index, void *ctx) {
  printf("%d ", elem);
  return true;
}

void do_operations(list *L, queue *q)
{
  while (!queue_isempty(q))
  {
    t_elem value = dequeue(q);

    if (value > 0)
      list_insert(L, list_length(L), value);
    else
    {
      int index = list_search(L, -value);
      if (index >= 0)
        list_delete(L, index);
    }

    printf("%2d -> (%d) ", value, list_length(L));
    list_traverse(L, print_list, NULL);
    getchar();
  }
}
