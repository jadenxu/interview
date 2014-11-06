#include "node.h"

Node* partitionList(Node* head, int k) {
  if (!head) {
    return NULL;
  }

  Node* end = head;
  int length = 1;
  while (end->next) {
    end = end->next;
    length++;
  }
  
  Node* sentry = new Node(0);
  sentry->next = head;
  Node* cur = sentry;
  for (int i = 0; i < length; i++) {
    if (cur->next->data >= k) {
      end->next = cur->next;
      cur->next = cur->next->next;
      end->next->next = NULL;
      end = end->next;
    } else {
      cur = cur->next;
    }
  }

  return sentry->next;
}

int main() {
  int n;
  cin>>n;
  Node* list = list_input(n);
  int k;
  cin>>k;
  Node* new_list = partitionList(list, k);
  list_output(new_list);

  return 0;
}
