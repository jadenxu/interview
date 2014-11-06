#include "node.h"
#include <unordered_set>

// Only for the one which might modify the header, we need to
// return a new Node*. In that case, it would be much easier 
// to use sentry node. Then we won't need to deal with the special
// case about header
void deleteDuplicate(Node* list) {
  unordered_set<int> set;
  Node* cur = list;
  set.insert(cur->data);

  while(cur->next) {
    if (set.find(cur->next->data) == set.end()) {
      set.insert(cur->next->data);
      cur = cur->next;
    } else {
      cur->next = cur->next->next;
    }
  }
}

void deleteDuplicate_NoHash(Node* list) {
  Node* cur = list;
  while(cur) {
    Node* runner = cur;
    while(runner->next) {
      if (runner->next->data == cur->data) {
        runner->next = runner->next->next;
      } else {
        runner = runner->next;
      }
    }
    cur = cur->next;
  }
}

int main() {
  int n;
  cin>>n;
  Node* list = list_input(n);
  deleteDuplicate(list);
  list_output(list);
}
