#include "TreeNode.h"

int treeHeight(TreeNode* root) {
  if (!root) {
    return 0;
  }
  
  return 1 + max(treeHeight(root->left), treeHeight(root->right));
}

// for this method, the complexity is O(NlogN)
bool checkBalance_1(TreeNode* root) {
  if (!root) {
    return true;
  }

  return abs(treeHeight(root->left) - treeHeight(root->right)) <= 1 &&
    checkBalance_1(root->left) && checkBalance_1(root->right);
}

int checkHeight(TreeNode* root) {
  if (!root) {
    return 0;
  }

  int leftHeight = checkHeight(root->left);
  if (leftHeight == -1) {
    return -1;
  }

  int rightHeight = checkHeight(root->right);
  if (rightHeight == -1) {
    return -1;
  }

  if (abs(leftHeight - rightHeight) <= 1) {
    return 1 + max(leftHeight, rightHeight);
  } else {
    return -1;
  }
}

// perform balance check and tree height calculate at the same time
// complexity is O(N)
bool checkBalance_2(TreeNode* root) {
  return checkHeight(root) != -1;
}

int main() {
  int n;
  cin>>n;
  TreeNode* root = tree_input(n);
  
  cout<<checkBalance_2(root)<<endl;

  return 0;
}
