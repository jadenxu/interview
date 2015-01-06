#include <iostream>
#include <vector>
using namespace std;

struct Person {
  Person() {};
  Person(int _h, int _w): h(_h), w(_w) {}
  int h;
  int w;
};

int count(vector<Person>& v, int bottom, vector<int>& num) {
  if (num[bottom] != -1) {
    return num[bottom];
  }
  
  num[bottom] = 0;
  for (int i = 0; i < v.size(); i++) {
    if (v[i].h < v[bottom].h && v[i].w < v[bottom].w) {
      num[bottom] = max(num[bottom], count(v, i, num));
    }
  }
  num[bottom]++;
  
  return num[bottom];
}

int count(vector<Person>& v) {
  int max_num = 0;
  vector<int> nums(v.size(), -1);
  for (int i = 0; i < v.size(); i++) {
    max_num = max(max_num, count(v, i, nums));
  }

  return max_num;
}

int main () {
  Person v_array[6] = {Person(65, 100), Person(70, 150), Person(56, 90),
    Person(75, 190), Person(60, 95), Person(68, 110)};
  vector<Person> v(v_array, v_array + 6);
  cout<<count(v)<<endl;

  return 0;
}
