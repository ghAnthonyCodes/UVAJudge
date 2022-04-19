#include <bits/stdc++.h>
#include <cstring>
using namespace std;

int strike(char c0, char c1) {
  if (c0 == 'X') {
    if (c1 == 'X')
      return 20;
    return 10 + c1 - '0';
  }
  if (c1 == '/')
    return 10;
  return c0 - '0' + c1 - '0';
}

int spare(char c0) {
  if (c0 == 'X')
    return 10;
  return c0 - '0';
}

vector<char> splitString(char L[100]) {
  vector<char> ret;
  string S;
  char *ptr;
  ptr = strtok(L, " ");
  while (ptr != NULL) {
    S = ptr;
    ret.push_back(S[0]);
    ptr = strtok(NULL, " ");
  }
  return ret;
}

int main() {

  char line[100];
  while (cin.getline(line, 100)) {
    if (strcmp(line, "Game Over") == 0)
      break;
    vector<char> V = splitString(line);

    // Solve
    int F[10] = { 0 };
    int frame = 0;
    int roll = 0;
    for (int i = 0; i < V.size(); i++) {
      if (V[i] == 'X') {
        F[frame] = 10 + strike(V[i+1], V[i+2]);
        // printf("F[%d] = %d\n", frame, F[frame]);
        frame++;
        roll = 0;
      } else if (V[i] == '/') {
        F[frame] = 10 + spare(V[i+1]);
        // printf("F[%d] = %d\n", frame, F[frame]);
        frame++;
        roll = 0;
      } else {
        if (roll == 0) {
          F[frame] = V[i] - '0';
          // printf("F[%d] = %d\n", frame, F[frame]);
          roll++;
        } else {
          F[frame] += V[i] - '0';
          // printf("F[%d] = %d\n", frame, F[frame]);
          frame++;
          roll = 0;
        }
      }
    }

    int tot = 0;
    for (auto& f : F) {
      tot += f;
    }
    printf("%d\n", tot);
  }

  return 0;
}
