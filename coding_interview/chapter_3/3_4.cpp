#include <iostream>
using namespace std;

void hanoi(int diskSize, char src, char dst, char help) {
  if (diskSize == 0) {
    cout<<"move "<<diskSize<<" from "<<src<<" to "<<dst<<endl;
    return;
  }
  
  hanoi(diskSize - 1, src, help, dst);
  cout<<"move "<<diskSize<<" from "<<src<<" to "<<dst<<endl;
  hanoi(diskSize - 1, help, dst, src);
}

int main() {
  hanoi(3, 'A', 'B', 'C');

  return 0;
}
