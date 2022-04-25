#include <bits/stdc++.h>
using namespace std;

unsigned int convertToInt(string S) {
  stringstream ss;
  if (S[0] == '0') {
    if (S[1] == 'x')
      return stoul(S, nullptr, 16);  
    return stoul(S, nullptr, 8);
  }
  return stoul(S, nullptr, 10);
}

int main() {

  int TC;
  char init[10];

  while (scanf("%s %d", init, &TC) != EOF) {
    if (TC == 0)
      return 0;

    int actual = convertToInt(init);
    char opC[10];
    char guessC[10];
    int score = 0;
    for (int t=0; t<TC; t++) {
      scanf("%s %s", opC, guessC);
      int guess = convertToInt(guessC);
      string op = opC;
      if (op == "++i") {
        if (guess == actual + 1) {
          score++;
        }
        actual = guess;
      } else if (op == "i++") {
        if (guess == actual)
          score++;
        actual = guess + 1;
      } else if (op == "--i") {
        if (guess == actual - 1) {
          score++;
        }
        actual = guess;
      } else if (op == "i--") {
        if (guess == actual) {
          score++;
        }
        actual = guess - 1;
      } else { 
        if (guess == actual)
          score++;
        actual = guess;
      }
    }
    printf("%d\n", score);
  }
  return 0;
}
