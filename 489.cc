#include <bits/stdc++.h>
using namespace std;

int main() {
  int R;
  char sol[50];
  char guess[50];
  string Sol;
  string Guess;
  while (scanf("%d\n", &R) != EOF) {
    set<char> need;
    set<char> fail;
    if (R == -1)
      return 0;
    printf("Round %d\n", R);
    scanf("%s\n", sol);
    scanf("%s\n", guess);
    Sol = sol;
    Guess = guess;

    for (auto& c : Sol)
      need.insert(c);

    // play the game
    int fails = 0;
    bool win = false;
    for (int i=0; i<Guess.length(); i++) {
      // We already guessed this
      if (fail.find(Guess[i]) != fail.end()) {
        if (i == Guess.length()-1) {
          printf("You chickened out.\n");
        }
        continue;
      }

      // Guess
      if (need.find(Guess[i]) == need.end()) {
        fails++;
        fail.insert(Guess[i]);
        if (fails == 7) {
          printf("You lose.\n");
          break;
        }
      } else {
        fail.insert(Guess[i]);
        need.erase(Guess[i]);
        if (need.empty()) {
          printf("You win.\n");
          break;
        }
      }
      if (i == Guess.length()-1) {
        printf("You chickened out.\n");
      }
    }



  }
  return 0;
}
