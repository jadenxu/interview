#include "TreeNode.h"

bool checkBST(TreeNode* root, int min, int max) {
  if (!root) {
    return true;
  }

  return root->data > min && 
         root->data <= max && 
         checkBST(root->left, min, root->data) &&
         checkBST(root->right, root->data, max);
}

bool checkBST(TreeNode* root) {
  return checkBST(root, INT_MIN, INT_MAX);
}

int main() {
  int depth;
  cin>>depth;
  TreeNode* root = tree_input(depth);
  cout<<checkBST(root)<<endl;
  
  return 0;
}
