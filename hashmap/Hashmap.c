#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdio.h>

#define TABLE_SIZE 5

typedef struct Node {
  char *key;
  int value;
  struct Node *next;
} Node;

typedef struct {
  Node *buckets[TABLE_SIZE];
} HashTable;

uint32_t hash();
HashTable *create_hash_table();
void insert();
int find();
void destroy_hash_table();

int main() {
  HashTable *table = create_hash_table(10);
  insert(table, "key1", 5);
  insert(table, "key2", 10);

  int val = find(table, "key1");
  printf("%d\n", val);
  val = find(table, "key2");
  printf("%d\n", val);

  destroy_hash_table(table);

  return 0;
}

HashTable *create_hash_table() {
  HashTable *hash_table = malloc(sizeof(HashTable));
  memset(hash_table->buckets, 0, sizeof(Node*) * TABLE_SIZE);
  return hash_table;
}

uint32_t hash(char *key) {
  unsigned long int value = 0;
  unsigned int i = 0; 
  unsigned int key_length = strlen(key);

  for (; i < key_length; ++i) {
    value = value * 37 + key[i];
  }

  return value % TABLE_SIZE;
}

void insert(HashTable *table, char *key, int value) {
  unsigned int bucketIdx = hash(key);
  Node *new_node = malloc(sizeof(Node));
  new_node->key = strdup(key);
  new_node->value = value;
  new_node->next = table->buckets[bucketIdx];
  table->buckets[bucketIdx] = new_node;
}

int find(HashTable *table, char *key) {
  unsigned int bucketIdx = hash(key);
  Node *node = table->buckets[bucketIdx];
  while (node != NULL && strcmp(node->key, key) != 0) {
    node = node->next;
  }

  if (node == NULL) return -1;
  return node->value;
}

void destroy_hash_table(HashTable *table) {
  if (table == NULL) return;

  for (int i = 1; i < TABLE_SIZE; i++) {
    Node *curr = table->buckets[i];
    while (curr != NULL) {
      Node *delete = curr;
      curr = curr->next;

      free(delete->key);
      free(delete);
    }
  }


  free(table);
}
