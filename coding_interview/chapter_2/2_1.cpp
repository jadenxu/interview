#include "node.h"
#include <unordered_set>

Node* deleteDuplicate(Node* list) {
  unordered_set<int> set;
  Node* pre = new Node(0);
  pre->next = list;
  Node* cur = pre;

  while(cur->next) {
    if (set.find(cur->next->data) == set.end()) {
      set.insert(cur->next->data);
      cur = cur->next;
    } else {
      cur->next = cur->next->next;
    }
  }

  return pre->next;
}

int main() {
  int n;
  cin>>n;
  Node* list = list_input(n);
  Node* new_list = deleteDuplicate(list);
  list_output(new_list);
}
