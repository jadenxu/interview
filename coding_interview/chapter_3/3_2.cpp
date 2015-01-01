#include <iostream>
#include <stack>
using namespace std;

class minStack {
public:
  minStack() {
  }
  ~minStack() {
  }
  int top() {
    return container.top();
  }
  void pop() {
    if (!container.empty() && container.top() == min_container.top()) {
      min_container.pop();
    }
    container.pop();
  }
  void push(int num) {
    if (container.empty() || num <= min_container.top()) {
      min_container.push(num);
    }
    container.push(num);
  }
  int min() {
    if (min_container.empty()) {
      return INT_MAX;
    } else {
      return min_container.top();
    }
  }
  int size() {
    return container.size();
  }
  bool empty() {
    return container.empty();
  }

private:
  stack<int> container;
  stack<int> min_container;
};

int main() {
  minStack st;
  st.push(5);
  st.push(7);
  st.push(5);
  st.push(4);
  while(!st.empty()) {
    cout<<st.min()<<endl;
    st.pop();
  }

  return 0;
}
