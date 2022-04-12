#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d\n", &n);
  char buff[128];
  vector<string> lines;
  for (int i=0; i<6; i++) {
    scanf("%s\n", buff);
    lines.push_back(buff);
  }
  int ptr=0;
  string ans = "";
  for (int i=0; i<n; i++) {
    if (lines[0][ptr] == '.') {
      ans += "1";
      ptr += 4;
    } else if (lines[3][ptr] == '*') {
      ans += "2";
      ptr += 4;
    } else {
      ans += "3";
      ptr += 4;
    }
  }
  printf("%s\n", ans.c_str());
  return 0;
}
