#include "TreeNode.h"

// If target has right subtree, then it will be the most left node in 
// the right subtree. If target doesn't have, it will be the first parent
// that the traversed node is its left child
TreeNode* nextNode(TreeNode* target) {
  if (!target) {
    return NULL;
  }

  if (target->right) {
    TreeNode* cur = target->right;
    while (cur->left) {
      cur = cur->left;
    }
    return cur;
  } else {
    TreeNode* cur = target;
    TreeNode* cur_parent = target->parent;
    while (cur_parent && cur_parent->left != cur) {
      cur = cur_parent;
      cur_parent = cur->parent;
    }
    return cur_parent; 
  }
}

int main() {

}
