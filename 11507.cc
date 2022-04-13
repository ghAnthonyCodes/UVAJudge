#include <bits/stdc++.h>
using namespace std;

#define RIGHT 0
#define DOWN  1
#define LEFT  2
#define UP    3
#define IN    4
#define OUT   5

map<int, string> M = {
  { RIGHT, "+x" },
  { LEFT, "-x" },
  { DOWN, "-y" },
  { UP, "+y" },
  { IN, "+z" },
  { OUT, "-z" },
};

int main() {

  int L;
  char b[5];
  string B;
  while (scanf("%d", &L) != EOF) {
    if (L == 0)
      break;
    int dir = RIGHT;
    for (int i=0; i<L-1; i++) {
      scanf("%s", b);
      B = b;

      // Starting right
      if (dir == RIGHT) {
        if (B == "-y")
          dir = DOWN;
        else if (B == "+y")
          dir = UP;
        else if (B == "-z")
          dir = OUT;
        else if (B == "+z")
          dir = IN;
      }

      // Startup up
      else if (dir == UP) {
        if (B == "-y")
          dir = RIGHT;
        else if (B == "+y")
          dir = LEFT;
        else if (B == "-z")
          dir = UP;
        else if (B == "+z")
          dir = UP;
      }

      // Startup down
      else if (dir == DOWN) {
        if (B == "-y")
          dir = LEFT;
        else if (B == "+y")
          dir = RIGHT;
        else if (B == "-z")
          dir = DOWN;
        else if (B == "+z")
          dir = DOWN;
      }

      // Startup left
      else if (dir == LEFT) {
        if (B == "-y")
          dir = UP;
        else if (B == "+y")
          dir = DOWN;
        else if (B == "-z")
          dir = IN;
        else if (B == "+z")
          dir = OUT;
      }

      // Startup in
      else if (dir == IN) {
        if (B == "-y")
          dir = IN;
        else if (B == "+y")
          dir = IN;
        else if (B == "-z")
          dir = RIGHT;
        else if (B == "+z")
          dir = LEFT;
      }

      // Startup out
      else if (dir == OUT) {
        if (B == "-y")
          dir = OUT;
        else if (B == "+y")
          dir = OUT;
        else if (B == "-z")
          dir = LEFT;
        else if (B == "+z")
          dir = RIGHT;
      }
    }
    printf("%s\n", M[dir].c_str());
  }
  return 0;
}
