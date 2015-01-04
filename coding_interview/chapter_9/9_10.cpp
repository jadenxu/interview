#include <iostream>
#include <vector>
using namespace std;

struct Box {
  Box() {}
  Box(int _l, int _w, int _h): l(_l), w(_w), h(_h) {}
  int l;
  int w;
  int h;
};

int maxHeight(vector<Box>& boxes, vector<int>& height, int bottom) {
  if (height[bottom] != -1) {
    return height[bottom];
  }

  for (int i = 0; i < boxes.size(); i++) {
    if (boxes[i].l > boxes[bottom].l && boxes[i].w > boxes[i].w 
        && boxes[i].h > boxes[bottom].h) {
      height[bottom] = max(height[bottom], maxHeight(boxes, height, i));      
    }
  }

  height[bottom] += boxes[bottom].h;
  return height[bottom];
}

int maxHeight(vector<Box>& boxes) {
  vector<int> height(boxes.size(), -1);
  int max_height = -1;
  for (int i = 0; i < boxes.size(); i++) {
    max_height = max(max_height, maxHeight(boxes, height, i));
  }

  return max_height;
}

int main() {

}
