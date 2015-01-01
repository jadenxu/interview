#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool BFS (vector<vector<int> >& graph, int src, int target) {
  bool* visited = new bool[graph.size()];
  memset(visited, 0, graph.size() * sizeof(bool));

  queue<int> q;
  q.push(src);
  visited[src] = true;
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    
    if (cur == target) {
      return true;
    }

    for (int i = 0; i < graph[cur].size(); i++) {
      if (!visited[graph[cur][i]]) {
        visited[graph[cur][i]] = true;
        q.push(graph[cur][i]);
      }
    }
  }

  return false;
}

bool DFS(vector<vector<int> >& graph, bool* visited, int src, int target) {
  visited[src] = true;
  if (src == target) {
    return true;
  }

  for (int i = 0; i < graph[src].size(); i++) {
    if(!visited[graph[src][i]]) {
      if (DFS(graph, visited, graph[src][i], target)) {
        return true;
      }
    }
  }

  return false;
}

bool DFS(vector<vector<int> >& graph, int src, int target) {
  bool* visited = new bool[graph.size()];
  memset(visited, 0, graph.size() * sizeof(bool));
  return DFS(graph, visited, src, target); 
}

int main() { 
}
