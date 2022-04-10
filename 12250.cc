#include <bits/stdc++.h>
using namespace std;

map<string, string> M = {
  { "HELLO", "ENGLISH" },
  { "HOLA", "SPANISH" },
  { "HALLO", "GERMAN" },
  { "BONJOUR", "FRENCH" },
  { "CIAO", "ITALIAN" },
  { "ZDRAVSTVUJTE", "RUSSIAN" },
};

int main() {

  char S[16];
  int tc = 1;
  while (scanf("%s\n", S) != EOF) {
    string s = S; 
    if (s == "#")
      return 0;
    if (M.find(s) == M.end())
      printf("Case %d: UNKNOWN\n", tc++);
    else
      printf("Case %d: %s\n", tc++, M[s].c_str());
  }
  return 0;
}
