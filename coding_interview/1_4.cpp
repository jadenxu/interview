#include <iostream>
using namespace std;

void replaceSpaces(char* str) {
  int spaces_counter = 0;
  int tmp = 0;
  char* end = str;
  while(*end) {
    if (*end++ == ' ') {
      tmp++;
    } else {
      spaces_counter += tmp;
      tmp = 0;
    }
  }
  end--;
  
  end = end - tmp;
  char* new_end = end + 2 * spaces_counter;
  cout<<*end<<endl;
  cout<<tmp<<endl;
  cout<<spaces_counter<<endl;

  while(end != str) {
    if (*end == ' ') {
      *new_end-- = '0';
      *new_end-- = '2';
      *new_end-- = '%';
      end--;
    } else {
      *new_end-- = *end--;
    }
  }
}

int main() {
  // Avoid to do char* buffer = "blabla".
  // In C11, this will generate a const char*
  char buffer[256];
  strcpy(buffer, "a b  c  d             ");
  replaceSpaces(buffer);
  cout<<buffer<<endl;

  return 0;
}
