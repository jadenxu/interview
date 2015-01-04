#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void fillColor_help(
  int x, int y, 
  int color, int origin_color,
  vector<vector<int> >& grid, vector<vector<bool> >& visited) {
  if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || visited[x][y]) {
    return;
  }

  visited[x][y] = true;
  if (grid[x][y] == origin_color) {
    grid[x][y] = color;
    fillColor_help(x - 1, y, color, origin_color, grid, visited);
    fillColor_help(x + 1, y, color, origin_color, grid, visited);
    fillColor_help(x, y - 1, color, origin_color, grid, visited);
    fillColor_help(x, y + 1, color, origin_color, grid, visited);
  }
}

void fillColor_1(int x, int y, int color, vector<vector<int> >& grid) {
  vector<vector<bool> > visited(grid.size(), vector<bool>(grid[0].size(), false));
  fillColor_help(x, y, color, grid[x][y], grid, visited);
}

void fillColor_2(int x, int y, int color, vector<vector<int> >& grid) {
  int x_step[4] = {-1, 1, 0, 0};
  int y_step[4] = {0, 0, -1, 1};
  int origin_color = grid[x][y];

  vector<vector<bool> > visited(grid.size(), vector<bool>(grid[0].size(), false));
  queue<pair<int, int> > q;
  q.push(pair<int, int>(x, y));
  visited[x][y] = true;

  while (!q.empty()) {
    pair<int, int> tmp = q.front();
    q.pop();
        
    if (grid[tmp.first][tmp.second] != origin_color) {
      continue;
    }
    grid[tmp.first][tmp.second] = color;

    for (int i = 0; i < 4; i++) {
      int cur_x = tmp.first + x_step[i], cur_y = tmp.second + y_step[i];
      if (cur_x >= 0 && cur_y >= 0 && 
          cur_x < grid.size() && cur_y < grid[0].size() && !visited[cur_x][cur_y]) {
        visited[cur_x][cur_y] = true;
        q.push(pair<int, int>(cur_x, cur_y));
      }
    }
  }
}

int main() {
  int n, m;
  cin>>n>>m;
  
  vector<vector<int> > grid(n, vector<int>(m, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin>>grid[i][j];
    }
  }
  int x, y, color;
  cin>>x>>y>>color;
  
  fillColor_2(x, y, color, grid);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout<<grid[i][j]<<" ";
    }
    cout<<endl;
  }
}
