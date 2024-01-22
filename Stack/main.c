#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE 6
int numbers[SIZE];

typedef struct {
  int *array;
  int capacity;
  int size;
} Stack;

Stack *create_stack(int capacity);
bool pop(Stack *stack, int *item);
bool push(Stack *stack, int item);
bool is_empty(Stack *stack);
bool is_full(Stack *stack);
bool peek(Stack *stack, int *item);
void destroy_stack(Stack *stack);

int main() {
  Stack *stack = create_stack(5);
  if (stack == NULL) {
    printf("Error creating a stack!");
    return 1;
  }

  destroy_stack(stack);

  return 0;
}

Stack *create_stack(int capacity) {
  if (capacity <= 0)
    return NULL;

  Stack *stack = malloc(sizeof(Stack));
  if (stack == NULL) {
    return NULL;
  }

  stack->array = malloc(sizeof(int) * capacity);
  if (stack->array == NULL) {
    free(stack);
    return NULL;
  }

  stack->capacity = capacity;
  stack->size = 0;

  return stack;
}

void destroy_stack(Stack *stack) {
  free(stack->array);
  free(stack);
}

bool is_full(Stack *stack) { return stack->capacity == stack->size; }
bool is_empty(Stack *stack) { return stack->size == 0; }

bool push(Stack *stack, int item) {
  if (is_full(stack)) {
    return false;
  }

  stack->array[stack->size] = item;
  stack->size++;

  return true;
}

bool pop(Stack *stack, int *item) {
  if (is_empty(stack)) {
    return false;
  }

  *item = stack->array[stack->size - 1];
  stack->size--;

  return true;
}

bool peek(Stack *stack, int *item) {
  if (is_empty(stack)) {
    return false;
  }

  *item = stack->array[stack->size - 1];

  return true;
}
