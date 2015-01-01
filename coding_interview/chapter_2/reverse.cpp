#include "node.h"

Node* reverse(Node* list) {
  Node* pre = NULL;
  Node* cur = list;
  Node* next;
  while (cur) {
    next = cur->next;
    cur->next = pre;
    pre = cur;
    cur = next;
  }

  return pre;
}

int main() {
  int n;
  cin>>n;
  Node* list = list_input(n);
  Node* new_list = reverse(list);
  list_output(new_list);

  return 0;
}
