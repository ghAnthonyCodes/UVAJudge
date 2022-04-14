#include <bits/stdc++.h>
using namespace std;

// Returns false if we ever lose
bool simRound(set<int> A, set<int> B, int wins) {
  if (A.empty())
    return wins < 2;

  bool loss = false;
  for (auto& a : A) {
    for (auto& b : B) {
      set<int> newA = A;
      set<int> newB = B;
      newA.erase(a);
      newB.erase(b);
      if (b > a)
        loss |= simRound(newA, newB, wins+1);
      else
        loss |= simRound(newA, newB, wins);
    }
  }
  return loss;
}

int main() {
  int a, b, c, x, y;
  while (scanf("%d %d %d %d %d", &a, &b, &c, &x, &y)) {
    if (a == 0) return 0;
    int card = -1;
    set<int> dealt = { a, b, c, x, y };
    for (int i=1; i<=52; i++) {
      if (dealt.find(i) != dealt.end())
        continue;
      bool possibleLoss = simRound({ a, b, c}, { x, y, i }, 0);
      if (!possibleLoss && card == -1) 
        card = i;
    }
    printf("%d\n", card);
  }
}
