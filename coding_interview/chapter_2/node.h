#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;

struct Node {
  Node() {
    next = NULL;
  }
  Node(int data_in) {
    data = data_in;
    next = NULL;
  }
  int data;
  Node* next;
};


Node* list_input(int n) {
  Node* list = NULL;
  Node* end = NULL;
  for(int i = 0; i < n; i++) {
    int tmp;
    cin>>tmp;
    Node* new_node = new Node(tmp);
    if(!list) {
      list = new_node;
    } else {
      end->next = new_node;
    }
    end = new_node;
  }

  return list;
}

void list_output(Node* list) {
  while(list) {
    cout<<list->data<<" ";
    list = list->next;
  } 
  cout<<endl;
}

#endif
