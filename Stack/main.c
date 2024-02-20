#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int *array;
  int capacity;
  int size;
} Stack;

Stack *create_stack(int capacity);
bool push(Stack *stack, int item);
bool pop(Stack *stack, int *item);
bool is_full(Stack *stack);
bool is_empty(Stack *stack);
bool peek(Stack *stack, int *item);
void destroy_stack(Stack *stack);

int main() {
  Stack *stack = create_stack(5);
  if (!stack) {
    printf("Error creating a stack\n");
    return 1;
  }


  printf("size: %d\n", stack->size);
  printf("capacity: %d\n", stack->capacity);

  push(stack, 1);
  push(stack, 2);
  printf("size: %d\n", stack->size);

  push(stack, 3);
  push(stack, 4);
  printf("size: %d\n", stack->size);

  int popped_val = 0;
  pop(stack, &popped_val);
  pop(stack, &popped_val);
  printf("size: %d\n", stack->size);

  int peek_val = 0;
  peek(stack, &peek_val);
  printf("peek: %d\n", peek_val);

  push(stack, 3);
  push(stack, 4);
  push(stack, 4);
  printf("size: %d\n", stack->size);
  printf("capacity: %d\n", stack->capacity);
  if (is_full(stack)) {
    printf("Stack full\n");
  }

  bool push_val = push(stack, 4);
  if (!push_val) {
    printf("ERROR: Stack full can't push further\n");
  }

  destroy_stack(stack);

  return 0;
}

Stack *create_stack(int capacity) {
  if (capacity <= 0) {
    return NULL;
  }

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

bool is_empty(Stack *stack) {
  return stack->size == 0;
}

bool is_full(Stack *stack) {
  return stack->capacity == stack->size;
}

bool push(Stack *stack, int item) {
  if(is_full(stack)) {
    return false;
  }


  stack->array[stack->size] = item;
  stack->size++;

  return true;
}

bool pop(Stack *stack, int *item) {
  if(is_empty(stack)) {
    return false;
  }

  *item = stack->array[stack->size-1];
  stack->size--;

  return true;
}

bool peek(Stack *stack, int *item) {
  if(is_empty(stack)) {
    return false;
  }

  *item = stack->array[stack->size-1];

  return true;
}

void destroy_stack(Stack *stack) {
  free(stack->array);
  free(stack);
}
