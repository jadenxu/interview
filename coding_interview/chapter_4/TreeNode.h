#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
  TreeNode() {
    left = right = NULL;
  }
  TreeNode(int _data) {
    data = _data;
    left = right = NULL;
  } 
  int data;
  TreeNode* left;
  TreeNode* right;
  TreeNode* parent;
};

TreeNode* tree_input(int depth) {
  vector<vector<TreeNode*> > level_vector(depth);
 
  for (int i = 0; i < depth; i++) {
    for (int j = 0; j < 1 << i; j++) { 
      char tmp;
      cin>>tmp;
      if (tmp >= '0' && tmp <= '9') {
        TreeNode* tmp_node = new TreeNode(tmp - '0');
        level_vector[i].push_back(tmp_node);
      } else {
        level_vector[i].push_back(NULL);
      }
    }
  }

  for (int i = 0; i < level_vector.size() - 1; i++) {
    for (int j = 0; j < level_vector[i].size(); j++) {
      if (level_vector[i][j] == NULL) {
        continue;
      } 
      level_vector[i][j]->left = level_vector[i+1][j*2];
      level_vector[i][j]->right = level_vector[i+1][j*2+1];
    }
  }
  
  return level_vector[0][0];
}

bool isNull(vector<TreeNode*> v) {
  TreeNode* address;
  for(int i = 0; i < v.size(); i++) {
    if (v[i]) {
      return false;
    }
  }
  return true;
}

void tree_output(TreeNode* root) {
  vector<TreeNode*> pre_level;
  vector<TreeNode*> cur_level;
  pre_level.push_back(root);
  while(!isNull(pre_level)) {
    for (int i = 0; i < pre_level.size(); i++) {
      if (pre_level[i]) {
        cout<<pre_level[i]->data<<" ";
        cur_level.push_back(pre_level[i]->left);
        cur_level.push_back(pre_level[i]->right);
      } else {
        cout<<"# ";
        cur_level.push_back(NULL);
        cur_level.push_back(NULL);
      }
    }
    cout<<endl;
    pre_level.clear();
    pre_level = cur_level;
    cur_level.clear();
  }
}
