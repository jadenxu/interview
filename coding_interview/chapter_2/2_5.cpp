#include "node.h"

Node* addLists_back(Node* list_1, Node* list_2) {
  Node* sentry = new Node();
  Node* end = sentry;
  Node* tmp;

  int result, carry = 0;
  while (list_1 || list_2) {
    result = carry;
    if (list_1) {
      result += list_1->data;
      list_1 = list_1->next;
    }
    if (list_2) {
      result += list_2->data;
      list_2 = list_2->next;
    }
    carry = result / 10;
    tmp = new Node(result % 10);
    end->next = tmp;
    end = end->next;
  } 
  
  if (carry) {
    tmp = new Node(carry);
    end->next = tmp;
    end = end->next;
  }

  return sentry->next;
}

Node* addLists_sameLength_forward(Node* list_1, Node* list_2, int& carry) {
  if (!list_1 && !list_2) {
    carry = 0;
    return NULL;
  }

  int result;
  Node* next_node = addLists_sameLength_forward(
    list_1 ? list_1->next : NULL, 
    list_2 ? list_2->next : NULL, 
    result);

  result += list_1->data + list_2->data; 
  carry = result / 10;
  Node* tmp = new Node(result % 10);
  tmp->next = next_node;

  return tmp;
}

int length(Node* list) {
  int length = 0;

  while(list) {
    length++;
    list = list->next;
  }

  return length;
}

Node* padZeros(Node* head, int num) {
  for (int i = 0; i < num; i++) {
    Node* tmp = new Node(0);
    tmp->next = head;
    head = tmp;
  }

  return head;
}

Node* addLists_forward(Node* list_1, Node* list_2) {
  int carry;
  int len_1 = length(list_1);
  int len_2 = length(list_2);
  if (len_1 < len_2) {
    list_1 = padZeros(list_1, len_2 - len_1);
  } else {
    list_2 = padZeros(list_2, len_1 - len_2);
  }

  Node* head = addLists_sameLength_forward(list_1, list_2, carry);
  
  if (carry) {
    Node* tmp = new Node(carry);
    tmp->next = head;
    head = tmp;
  }

  return head;
}

int main() {
  int n;
  cin>>n;
  Node* list_1 = list_input(n);
  
  int m;
  cin>>m;
  Node* list_2 = list_input(m);

  list_output(addLists_forward(list_1, list_2));

  return 0;
}
