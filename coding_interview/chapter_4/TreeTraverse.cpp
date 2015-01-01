#include "TreeNode.h"

void inorder(TreeNode* root, vector<int>& v) {
  if (!root) {
    return;
  }

  inorder(root->left, v);
  v.push_back(root->data);
  inorder(root->right, v);
}

// for tree, DFS is same as preorder. 
// but for graph, we need check whether the node is already
// visited to avoid infinite loop
void preorder(TreeNode* root, vector<int>& v) {
  if (!root) {
    return;
  }

  v.push_back(root->data);
  preorder(root->left, v);
  preorder(root->right, v);
}

void postorder(TreeNode* root, vector<int>& v) {
  if (!root) {
    return;
  }

  postorder(root->left, v);
  postorder(root->right, v);
  v.push_back(root->data);
}

// For graph, rememeber to check whether the node is already 
// visited
void BFS(TreeNode* root, vector<int>& v) {
  if (!root) {
    return;
  }

  queue<TreeNode*> q;
  q.push(root);
  while (!q.empty()) {
    TreeNode* tmp = q.front();
    v.push_back(tmp->data);
    q.pop();
    if (tmp->left) {
      q.push(tmp->left);
    }
    if (tmp->right) {
      q.push(tmp->right);
    }
  }
}

void printVector(vector<int>& v) {
  for (int i = 0; i < v.size(); i++) {
    cout<<v[i]<<" ";
  }
  cout<<endl;
}

int main() {
  int depth;
  cin>>depth;
  TreeNode* root = tree_input(depth);
  
  vector<int> v_inorder;
  inorder(root, v_inorder);
  cout<<"Inorder: ";
  printVector(v_inorder);

  vector<int> v_preorder;
  preorder(root, v_preorder);
  cout<<"Preorder: ";
  printVector(v_preorder);

  vector<int> v_postorder;
  postorder(root, v_postorder);
  cout<<"Postorder: ";
  printVector(v_postorder);

  vector<int> v_bfs;
  BFS(root, v_bfs);
  cout<<"BFS: ";
  printVector(v_bfs);
  return 0;
}
