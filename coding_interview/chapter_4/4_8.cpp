#include "TreeNode.h"

void printPath(vector<int>& cur_path, int start) {
  for (int i = start; i < cur_path.size(); i++) {
    cout<<cur_path[i]<<" ";
  }
  cout<<endl;
}

void sumPath(TreeNode* root, int sum, vector<int>& cur_path) {
  if (!root) {
    return;
  }
  
  cur_path.push_back(root->data);
  int cur_sum = 0;
  for (int i = cur_path.size() - 1; i >= 0; i--) {
    cur_sum += cur_path[i];
    if (cur_sum == sum) {
      printPath(cur_path, i);
    }
  }

  sumPath(root->left, sum, cur_path);
  sumPath(root->right, sum, cur_path);
  cur_path.pop_back();
}

void sumPath(TreeNode* root, int sum) {
  vector<int> cur_path;
  sumPath(root, sum, cur_path);
}

int main() {
  int depth;
  cin>>depth;
  TreeNode* root = tree_input(depth);

  int sum;
  cin>>sum;
  sumPath(root, sum);

  return 0;
}
