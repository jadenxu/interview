#include "node.h"

int findLastKth(Node* list, int k) {
  Node* fast = list;
  Node* slow = list;
  for (int i = 0; i < k; i++) {
    fast = fast->next;
  }
  while (fast) {
    fast = fast->next;
    slow = slow->next;
  }

  return slow->data;
}

int main() {
  int n, k;
  cin>>n;
  Node* list = list_input(n);
  cin>>k;
  cout<<findLastKth(list, k)<<endl;
}
