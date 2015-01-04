#include <iostream>
#include <vector>
using namespace std;

int count_help(int n, int index, vector<int>& deno) {
  if (n == 0) {
    return 1;
  } 
  if (n < 0) {
    return 0;
  }
  if (index < 0 && n > 0) {
    return 0;
  }

  return count_help(n, index - 1, deno) + count_help(n - deno[index], index, deno);
}

int count_1(int n, vector<int>& deno) {
  return count_help(n, deno.size() - 1, deno);
}

int count_2(int n, vector<int>& deno) {
  vector<vector<int> > count(n + 1, vector<int>(deno.size(), 0));
  for (int i = 0; i < deno.size(); i++) {
    count[0][i] = 1;
  }

  for (int i = 1; i < n + 1; i++) {
    for (int j = 0; j < deno.size(); j++) {
      int x = (i - deno[j] >= 0) ? count[i - deno[j]][j] : 0;
      int y = (j > 0) ? count[i][j - 1] : 0;
      count[i][j] = x + y;
    }
  }
  return count[n][deno.size() - 1];
}

int main() {
  int n;
  cin>>n;
  int v[4] = {1, 5, 10, 25};
  vector<int> deno(v, v + 4);
  cout<<count_1(n, deno)<<" "<<count_2(n, deno)<<endl;

  return 0;
}
