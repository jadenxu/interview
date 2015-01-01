#include "node.h"
#include <stack>

bool isPalindrome(Node* head) { 
  stack<int> st;
  Node* slow = head;
  Node* fast = head;
  while (slow && fast && fast->next) {
    st.push(slow->data);
    slow = slow->next;
    fast = fast->next->next;
  }
  if (fast) {
    slow = slow->next;
  }
  while(slow) {
    if (slow->data != st.top()) {
      return false;
    }
    st.pop();
    slow = slow->next;
  }

  return true;
}

int main() {
  int n;
  cin>>n;
  Node* list = list_input(n);
  cout<<isPalindrome(list)<<endl;
}
