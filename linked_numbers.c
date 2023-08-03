#include "./scan.c"
#include <stdio.h>

typedef struct Node {
  long int number;
  struct Node *next;
} Node;

struct List {
  int width;
  struct Node *node;
};

int main() {
  struct List list;
  struct Node *last_node = NULL;

  char is_eof = 0;

  while (!(is_eof)) {
    Node *node = malloc(sizeof(Node));
    if (node == NULL) {
      printf("Failed to allocate memory for node.\n");
      return 1;
    }

    node->number = scan(&is_eof);
    node->next = NULL;

    if (last_node == NULL)
      list.node = node;
    else
      last_node->next = node;

    last_node = node;
  };

  for (int i = 0; i < 2; i++) {
    struct Node *current_node = list.node;
    while (current_node != NULL) {
      printf("%ld ", current_node->number);
      current_node = current_node->next;
    }
  }

  return 0;
}
