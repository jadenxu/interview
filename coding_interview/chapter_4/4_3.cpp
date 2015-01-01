#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include "TreeNode.h"
using namespace std;

TreeNode* treeFromArray(vector<int>& v, int left, int right) {
  if (left > right) {
    return NULL;
  }

  int mid = (left + right) / 2;
  TreeNode* root = new TreeNode(v[mid]);
  root->left = treeFromArray(v, left, mid - 1);
  root->right = treeFromArray(v, mid + 1, right);

  return root;
}

TreeNode* treeFromArray(vector<int>& v) {
  return treeFromArray(v, 0, v.size() - 1);
}

int main() {
  int size;
  cin>>size;
  srand(time(0));
  vector<int> v;
  for (int i = 0; i < size; i++) {
    v.push_back(rand() % 100);
  }  
  sort(v.begin(), v.end());
  TreeNode* root = treeFromArray(v);
  for (int i = 0; i < size; i++) {
    cout<<v[i]<<" ";
  }
  cout<<endl;
  tree_output(root);

  return 0;
}
