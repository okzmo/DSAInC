#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int *array;
  int capacity;
  int size;
} Queue;

Queue *create_queue(int capacity);
bool enque(Queue *queue, int item);
bool deque(Queue *queue, int *item);
bool is_full(Queue *queue);
bool is_empty(Queue *queue);
bool peek(Queue *queue, int *item);
void destroy_queue(Queue *queue);

int main() {
  Queue *queue = create_queue(5);
  if(!queue) {
    printf("ERROR: creating queue.\n");
    return 1;
  }


  int peeked_val = 0;
  int dequed_val = 0;

  enque(queue, 5);
  enque(queue, 2);
  enque(queue, 4);
  printf("size: %d\n", queue->size);
  printf("capacity: %d\n", queue->capacity);

  peek(queue, &peeked_val);
  printf("peeked: %d\n", peeked_val);

  deque(queue, &dequed_val);
  printf("dequed: %d\n", dequed_val);
  deque(queue, &dequed_val);
  printf("dequed: %d\n", dequed_val);

  peek(queue, &peeked_val);
  printf("peeked: %d\n", peeked_val);



  destroy_queue(queue);
  return 0;
}

Queue *create_queue(int capacity) {
  if (capacity <= 0) {
    return NULL;
  }


  Queue *queue = malloc(sizeof(Queue));
  if (queue == NULL) {
    return NULL;
  }

  queue->array = malloc(sizeof(int) * capacity);
  if (queue->array == NULL) {
    free(queue);
    return NULL;
  }

  queue->capacity = capacity;
  queue->size = 0;

  return queue;
}

void destroy_queue(Queue *queue) {
  free(queue->array);
  free(queue);
}

bool is_full(Queue *queue) {
  return queue->capacity == queue->size;
}

bool is_empty(Queue *queue) {
  return queue->size == 0;
}

bool enque(Queue *queue, int item) {
  if (is_full(queue)) {
    return false;
  }

  queue->array[queue->size] = item;
  queue->size++;

  return true;
}

bool deque(Queue *queue, int *item) {
  if (is_empty(queue)) {
    return false;
  }

  queue->size--;
  *item = queue->array[0];
  for (int i = 0; i < queue->size; i++) {
    queue->array[i] = queue->array[i+1];
  }

  return true;
}

bool peek(Queue *queue, int *item) {
  if (is_empty(queue)) {
    return false;
  }

  *item = queue->array[0];

  return true;
}
