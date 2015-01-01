#include <iostream>
#include <stack>
using namespace std;

class Squeue {
public:
  Squeue() {
  }
  ~Squeue() {
  }
  void enqueue(int num) {
    newStack.push(num);
  }
  int dequeue() {
    if (empty()) {
      cerr<<"Queue is empty!!!"<<endl;
      return -1;
    }

    if (oldStack.empty()) {
      while(!newStack.empty()) {
        oldStack.push(newStack.top());
        newStack.pop();
      }
    }
    int tmp = oldStack.top();
    oldStack.pop();
    return tmp;
  }
  bool empty() {
    return oldStack.empty() && newStack.empty();
  }
  int size() {
    return oldStack.size() + newStack.size();
  }
private:
  stack<int> oldStack;
  stack<int> newStack;
};

int main () {
  Squeue q;
  q.enqueue(1);
  q.enqueue(2);
  q.enqueue(3);
  cout<<q.dequeue()<<endl;
  q.enqueue(4);
  q.enqueue(5);
  while (!q.empty()) {
    cout<<q.dequeue()<<endl;
  }

  return 0;
}
