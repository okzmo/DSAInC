#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE 6
int numbers[SIZE];

typedef struct {
  int *array;
  int capacity;
  int size;
} Queue;

Queue *create_queue(int capacity);
bool deque(Queue *queue, int *item);
bool enque(Queue *queue, int item);
bool is_empty(Queue *queue);
bool is_full(Queue *queue);
bool peek(Queue *queue, int *item);
void destroy_queue(Queue *queue);

int main() {
  Queue *queue = create_queue(5);
  if (queue == NULL) {
    printf("Error creating a queue!");
    return 1;
  }

  enque(queue, 1);
  enque(queue, 2);
  enque(queue, 3);
  int peek_val;
  peek(queue, &peek_val);
  printf("Peeked val %d, with a queue of size %d", peek_val, queue->size);
  int deque_val;
  deque(queue, &deque_val);
  printf("Deque val %d", deque_val);
  peek(queue, &peek_val);
  printf("Peeked val %d, with a queue of size %d", peek_val, queue->size);

  destroy_queue(queue);

  return 0;
}

Queue *create_queue(int capacity) {
  if (capacity <= 0)
    return NULL;

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

bool is_full(Queue *queue) { return queue->capacity == queue->size; }
bool is_empty(Queue *queue) { return queue->size == 0; }

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
  for (int i = 0; i < queue->size - 1; i++) {
    queue->array[i] = queue->array[i + 1];
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
