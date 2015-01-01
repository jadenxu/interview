#include "TreeNode.h"
#include "../chapter_2/node.h"

vector<Node*> levelTraverse(TreeNode* root) {
  vector<Node*> levels;
  vector<TreeNode*> pre_level;
  vector<TreeNode*> cur_level;
  pre_level.push_back(root);
  while (!pre_level.empty()) {
    Node* head = NULL;
    Node* tail = NULL;
    for (int i = 0; i < pre_level.size(); i++) {
      if (!head) {
        head = tail = new Node(pre_level[i]->data);
      } else {
        tail->next = new Node(pre_level[i]->data);
        tail = tail->next;
      }

      if (pre_level[i]->left) {
        cur_level.push_back(pre_level[i]->left);
      }
      if (pre_level[i]->right) {
        cur_level.push_back(pre_level[i]->right);
      }
    }
    pre_level.clear();
    pre_level = cur_level;
    cur_level.clear();
    levels.push_back(head);
  }

  return levels;
} 

int main() {
  int depth;
  cin>>depth;
  TreeNode* root = tree_input(depth);

  vector<Node*> levels = levelTraverse(root);
  for (int i = 0; i < levels.size(); i++) {
    Node* tmp = levels[i];
    while(tmp) {
      cout<<tmp->data<<" ";
      tmp = tmp->next;
    }
    cout<<endl;
  }
}
