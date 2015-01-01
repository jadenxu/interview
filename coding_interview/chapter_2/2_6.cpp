#include "node.h"

bool hasCircle(Node* head) {
  Node* fast = head;
  Node* slow = head;
  while (slow && fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast) {
      return true;
    }
  }
  
  return false;
}

Node* circleBegin(Node* head) {
  Node* fast = head;
  Node* slow = head;
  while (slow && fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
    if (fast == slow) {
      break;
    }
  }

  if (!slow || !fast || !fast->next) {
    return NULL;
  }

  fast = head;
  while (fast != slow) {
    fast = fast->next;
    slow = slow->next;
  }

  return fast;
} 

int main() {
  int n;
  cin>>n;
  Node* head = list_input(n);
  
  int k;
  cin>>k;
  if (k != -1) {
    Node* k_pos = head;
    for (int i = 0; i < k; i++) {
      k_pos = k_pos->next;
    }
    Node* end = head;
    while(end->next) {
      end = end->next;
    }
    end->next = k_pos;
  }
  
  cout<<circleBegin(head)->data<<endl;

  return 0;
}
