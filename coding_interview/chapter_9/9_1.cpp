#include <iostream>
#include <vector>
using namespace std;

int numPaths_2(int n) {
  vector<int> paths(n, 0);
  paths[0] = 1; paths[1] = 2; paths[2] = 4;
  for (int i = 3; i < n; i++) {
    paths[i] = paths[i - 1] + paths[i - 2] + paths[i - 3];
  }

  return paths[n - 1];
}

int numPaths_1(int n) {
  if (n == 0) {
    return 1;
  }
  int paths = 0;
  if (n >= 1) {
    paths += numPaths_1(n - 1);
  } 
  if (n >= 2) {
    paths += numPaths_1(n - 2);
  }
  if (n >= 3) {
    paths += numPaths_1(n - 3);
  }

  return paths;
}

int main() {
  int n;
  cin>>n;
  cout<<numPaths_1(n)<<" "<<numPaths_2(n)<<endl;

  return 0;
}
