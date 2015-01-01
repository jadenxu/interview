#include "TreeNode.h"

// If it is BST, we only need find the one which is between p and q

// If it has parents link, we could first go from p to root, and use
// a hash table to record the occurrence. Then go from q to root, 
// the first recorded one will be the common ancester
// Or we could first calculate the depth for p and q. Move one of them
// to make them at the same depth, and move them together untill they meet

// If it's just a normal tree, we could first search p, q on left. If only
// one appear, return the root. If both on left, we recursively search on left
// Otherwise, recursively search on right

bool cover(TreeNode* root, TreeNode* target) {
  if (!root) {
    return false;
  }
  return root == target && cover(root->left, target) && cover(root->right, target);
}

TreeNode* commonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
  if (!root) {
    return NULL;
  }
  if (root == p || root == q) {
    return root;
  }

  bool p_in_left = cover(root->left, p);
  bool q_in_left = cover(root->right, q);
  if (p_in_left != q_in_left) {
    return root;
  }

  if (p_in_left && q_in_left) {
    return commonAncestor(root->left, p, q);
  } else {
    return commonAncestor(root->right, p, q);
  }
}

int main() {

}
