#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
int main() {
  char input[100]; 
  std::string I;
  int map[26] = { 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 9, 9, 9, 9 };
  while (cin.getline(input, 100)) {
    I = input;
    for (auto& c : I) {
      if (c == '-' || c == '1' || c == '0')
        printf("%c", c);
      else
        printf("%d", map[c-'A']);
    }
    printf("\n");
  }
  return 0;
}
