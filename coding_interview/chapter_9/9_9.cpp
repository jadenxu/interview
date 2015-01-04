#include <iostream>
#include <vector>
using namespace std;

bool checkValid(vector<int>& cur, int x, int y) {
  for (int i = 0; i < x; i++) {
    if (cur[i] == y) {
      return false;
    }
    if (abs(cur[i] - y) == x - i) {
      return false;
    }
  }

  return true;
}

void queens(int n, int row, vector<int>& cur, vector<vector<int> >& pos) {
  if (row == n) {
    pos.push_back(cur);
    return;
  }
  for (int i = 0; i < n; i++) {
    if (checkValid(cur, row, i)) {
      cur.push_back(i);
      queens(n, row + 1, cur, pos);
      cur.pop_back();
    }
  }
}

vector<vector<int> > queens(int n) {
  vector<vector<int> > pos;
  vector<int> cur;
  queens(n, 0, cur, pos);

  return pos;
}

int main() {
  int n;
  cin>>n;
  vector<vector<int> > pos = queens(n);
  for (int k = 0; k < pos.size(); k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (j == pos[k][i]) {
          cout<<"#";
        } else {
          cout<<" ";
        }
      }
      cout<<endl;
    }
    cout<<endl;
  }
  
  return 0;
}
