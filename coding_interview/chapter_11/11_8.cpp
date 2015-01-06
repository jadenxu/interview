#include <iostream>
#include <vector>
using namespace std;

struct Node {
  Node() {}
  Node(int _data): data(_data), left(NULL), right(NULL), left_size(0) {}
  int data;
  Node* left;
  Node* right;
  int left_size;
};

class Tree {
public:
  Tree(): root(NULL) {}
  Tree(Node* _root): root(_root) {}
  
  void insert(int data) {
    if (!root) {
      root = new Node(data);
      return;
    }

    Node* parent = NULL;
    Node* cur = root;
    while (cur) {
      if (data <= cur->data) {
        cur->left_size++;
        parent = cur;
        cur = cur->left;
      } else {
        parent = cur;
        cur = cur->right;
      }
    }

    if (data <= parent->data) {
      parent->left = new Node(data);  
    } else {
      parent->right = new Node(data);
    }
  }

  int getRank(int data) {
    Node* cur = root;
    int rank = 0;
    while (cur) {
      if (data == cur->data) {
        return rank;
      } else if (data < cur->data) {
        cur = cur->left;
      } else {
        rank += cur->left_size + 1;
        cur = cur->right;
      }
    }

    return -1;
  }

private:
  Node* root;
};

int main() {
  int a[7] = {5, 3, 2, 6, 8, 9, 10};
  vector<int> v(a, a + 7);
  Tree tree;
  for (int i = 0; i < v.size(); i++) {
    cout<<a[i]<<" ";
    tree.insert(a[i]);
  }
  cout<<endl;
  int data;
  cin>>data;
  cout<<tree.getRank(data)<<endl;

  return 0;
}
