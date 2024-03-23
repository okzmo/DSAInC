#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
  int value;
  struct Node *next;
} Node;

typedef struct {
  Node *head;
  int length;
} LinkedList;

LinkedList *create_linkedlist();
bool addCell(LinkedList *linked_list, int value);
bool removeCell(LinkedList *linked_list, int value);
void destroy_linkedlist(LinkedList *linked_list);

int main() {
  LinkedList *linked_list = create_linkedlist();
  addCell(linked_list, 1);
  addCell(linked_list, 2);
  addCell(linked_list, 3);
  addCell(linked_list, 4);
  addCell(linked_list, 5);
  printf("%d\n", linked_list->length);
  removeCell(linked_list, 2);
  printf("%d\n", linked_list->head->next->value);
  bool removeVal = removeCell(linked_list, 6);
  if (!removeVal) {
    printf("Error when removing value.\n");
  }

  destroy_linkedlist(linked_list);

}

LinkedList *create_linkedlist() {
  LinkedList *linked_list = malloc(sizeof(LinkedList));


  return linked_list;
}

bool addCell(LinkedList *list, int value) {
  if (list == NULL) return false;

  Node *new_node = malloc(sizeof(Node));
  if(new_node == NULL) return false;
  new_node->value = value;
  new_node->next = NULL;

  if (list->head == NULL) {
    list->head = new_node;
  } else {
    Node *curr = list->head;
    while (curr->next != NULL) {
      curr = curr->next;
    }

    curr->next = new_node;
  }

  list->length++;

  return true;
}

bool removeCell(LinkedList *list, int value) {
  if (list == NULL || list->head == NULL) return false;

  Node *curr = list->head;
  Node *prev = NULL;

  if(curr->value == value) {
    list->head = curr->next;
    free(curr);
    list->length--;

    return true;
  }


  while (curr != NULL && curr->value != value) {
    prev = curr;
    curr = curr->next;
  }

  if(curr == NULL) return false;

  prev->next = curr->next;
  free(curr);
  list->length--;

  return true;
}

void destroy_linkedlist(LinkedList *table) {
  if (table == NULL) return;

  Node *curr = table->head;
  while (curr != NULL) {
    Node *delete = curr;
    curr = curr->next;

    free(delete);
  }

  free(table);
}
