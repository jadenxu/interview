#include <iostream>
#include <stack>
#include <ctime>
#include <cstdlib>

using namespace std;

void stackSort(stack<int>& s) {
  stack<int> buffer;
  while(!s.empty()) {
    int tmp = s.top();
    s.pop();
    while (!buffer.empty() && tmp > buffer.top()) {
      s.push(buffer.top());
      buffer.pop();
    }
    buffer.push(tmp);
  }

  while(!buffer.empty()) {
    s.push(buffer.top());
    buffer.pop();
  }
}

int main() {
  stack<int> s;
  srand(time(0));
  for (int i = 0; i < 10; i++) {
    s.push(rand() % 100);
  }
  stackSort(s);
  while (!s.empty()) {
    cout<<s.top()<<endl;
    s.pop();
  }

  return 0;
}
