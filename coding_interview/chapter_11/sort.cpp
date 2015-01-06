#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

void swap(int& a, int& b) {
  int tmp = a;
  a = b;
  b = tmp;
}

void bubble_sort(vector<int>& v) {
  bool switch_on;
  do {
    switch_on = false;
    for (int i = 0; i < v.size() - 1; i++) {
      if (v[i] > v[i + 1]) {
        swap(v[i], v[i + 1]);
        switch_on = true;
      }
    }
  } while (switch_on);
}

void selection_sort(vector<int>& v) {
  for (int i = v.size() - 1; i > 0; i--) {
    int max = v[0], max_index = 0;
    for (int j = 1; j <= i; j++) {
      if (v[j] > max) {
        max = v[j];
        max_index = j;
      }
    }
    swap(v[max_index], v[i]);
  }
}

void insertion_sort(vector<int>& v) {
  for (int i = 1; i < v.size(); i++) {
    int cur = v[i], k;
    for (k = i - 1; k >= 0 && v[k] > cur; k--) {
      v[k + 1] = v[k];
    }
    v[k + 1] = cur;
  }
} 

void merge(vector<int>& v, vector<int>& aux, int low, int mid, int high) {
  for (int i = low; i <= high; i++) {
    aux[i] = v[i];
  }
  int cur_l = low, cur_r = mid + 1, cur = low;
  while (cur_l <= mid && cur_r <= high) {
    if (aux[cur_l] < aux[cur_r]) {
      v[cur++] = aux[cur_l++];
    } else {
      v[cur++] = aux[cur_r++];
    }
  }
  while (cur_l <= mid) {
    v[cur++] = aux[cur_l++];
  }
  while (cur_r <= high) {
    v[cur++] = aux[cur_r++];
  }
}

void merge_sort(vector<int>& v, vector<int>& aux, int low, int high) {
  if (low < high) {
    int mid = (low + high) / 2;
    merge_sort(v, aux, low, mid);
    merge_sort(v, aux, mid + 1, high);
    merge(v, aux, low, mid, high);
  }
}

void merge_sort(vector<int>& v) {
  vector<int> aux(v.size());
  merge_sort(v, aux, 0, v.size() - 1);
}

void printVector(vector<int>& v) {
  for (int i = 0; i < v.size(); i++) {
    cout<<v[i]<<" ";
  }
  cout<<endl;
}

int main() {
  int size = 10;
  vector<int> num;
  srand(time(0));
  for (int i = 0; i < size; i++) {
    num.push_back(rand() % 100);
  }
  
  vector<int> bubble_num = num;
  bubble_sort(bubble_num);
  printVector(bubble_num);

  vector<int> selection_num = num;
  selection_sort(selection_num);
  printVector(selection_num);
  
  vector<int> insertion_num = num;
  insertion_sort(insertion_num);
  printVector(insertion_num);
  
  vector<int> merge_num = num;
  merge_sort(merge_num);
  printVector(merge_num);
  
  return 0;
}
