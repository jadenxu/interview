#include <iostream>
using namespace std;

class Cqueue {
  public:
    Cqueue(int size = 3) {
      array = new int[size];
      counter = 0;
      this->size = size;
    }
    ~Cqueue() {
      delete [] array;
    }
    void enqueue(int num) {
      if (counter == size) {
        cerr<<"Queue is full!!!"<<endl;
        return;
      }
      if (counter == 0) {
        front = back = 0;
        array[back] = num;
      } else {
        back = (back + 1) % size;
        array[back] = num;
      }
      counter++;
    }
    int dequeue() {
      if (counter == 0) {
        cerr<<"Queue is empty!!!"<<endl;
        return -1;
      }
      int tmp = array[front];
      front = (front + 1) % size;
      counter--;
      return tmp;
    }
    bool empty() {
      return counter == 0;
    }
  private:
    int* array;
    int front;
    int back;
    int counter;
    int size;
};

int main() {
  Cqueue q;
  q.enqueue(1);
  q.enqueue(2);
  q.enqueue(3);
  cout<<q.dequeue()<<endl;
  q.enqueue(4);
  cout<<q.dequeue()<<endl;
  q.enqueue(5);
  while (!q.empty()) {
    cout<<q.dequeue()<<endl;
  }

  return 0;
}
