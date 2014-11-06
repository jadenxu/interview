#include "node.h"

// The node has to be either a head or in the middle
bool deleteNode(Node* node) {
  if (!node || !node->next) {
    return false;
  }
  node->data = node->next->data;
  node->next = node->next->next;
  return true;
}

int main()
{
  int n;
  cin>>n;
  Node* list = list_input(n);
  int k;
  cin>>k;
  Node* node = list;
  for (int i = 0; i < k; i++) {
    node = node->next;
  }
  deleteNode(node);
  list_output(list);

  return 0;
}
