#include <iostream>
using namespace std;

void reverse(char* str) {
  if (!str) {
    return;
  }

  char* end = str;
  while (*end) {
    ++end;
  }
  --end;
 
  char tmp;
  while (str < end) {
    tmp = *str;
    *str++ = *end;
    *end-- = tmp;
  }
}

int main() {
  char buffer[256];
  cin>>buffer;
  reverse(buffer);
  cout<<buffer<<endl;

  return 0;
}
