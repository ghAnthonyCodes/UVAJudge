#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
  int N;
  char line[1000];
  while (cin.getline(line, 1000)) {
    sscanf(line, "%d", &N);
    if (N == 0)
      return 0;
    char c;
    cin.getline(line, 1000);
    string lineStr = line;
    for (int i=0; i<lineStr.length(); i++) {
      c = lineStr[i];
      if ((c >= 'a' && c <= 'z'))
        printf("%c", (((c - 'a' + N) % 26 + 26) % 26) + 'a');
      else if ((c >= 'A' && c <= 'Z'))
        printf("%c", (((c - 'A' + N) % 26 + 26) % 26) + 'A');
      else
        printf("%c", c);
    }
    printf("\n");
  }
  return 0;
}
