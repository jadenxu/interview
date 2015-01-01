#include "TreeNode.h"

int treeDepth(TreeNode* root) {
  if (!root) {
    return 0;
  }

  return 1 + max(treeDepth(root->left), treeDepth(root->right));
}

int getCandidates(TreeNode* root, vector<TreeNode*>& nodes, int depth) {
  if (!root) {
    return 0;
  }

  int cur_depth = 1 + max(getCandidates(root->left, nodes, depth), 
                          getCandidates(root->right, nodes, depth));
  if (cur_depth == depth) {
    nodes.push_back(root);
  }

  return cur_depth;
}

bool match_tree(TreeNode* root_1, TreeNode* root_2) {
  if (!root_1 && !root_2) {
    return true;
  }
    
  if (!root_1 || !root_2) {
    return false;
  }

  if (root_1->data != root_2->data) {
    return false;
  } 

  return match_tree(root_1->left, root_2->left) && match_tree(root_1->right, root_2->right);
}

TreeNode* subtree(TreeNode* root, TreeNode* target) {
  int depth = treeDepth(target);
  vector<TreeNode*> candidates;
  getCandidates(root, candidates, depth);

  for (int i = 0; i < candidates.size(); i++) {
    if (match_tree(candidates[i], target)) {
      return candidates[i];
    }
  }
  
  return NULL;
}

int main() {
  int depth_1;
  cin>>depth_1;
  TreeNode* root_1 = tree_input(depth_1);

  int depth_2;
  cin>>depth_2;
  TreeNode* root_2 = tree_input(depth_2);

  cout<<subtree(root_1, root_2)->data<<endl;

  return 0;
}
