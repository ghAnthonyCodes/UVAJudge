#include <bits/stdc++.h>
using namespace std;

struct node {
  node(int val) {
    value = val;
  }
  int value;
  node *left = NULL;
  node *right = NULL;
};

map<char, int> M = {
  { 'A',  0 }, { '2',  1 }, { '3',  2 }, { '4',  3 },
  { '5',  4 }, { '6',  5 }, { '7',  6 }, { '8',  7 },
  { '9',  8 }, { 'T',  9 }, { 'J', 10 }, { 'Q', 11 },
  { 'K', 12 }, 
};

// Ex
// 0 9 10 11 12
double evalHand(vector<int> hand) {
  vector<set<int>> S = { { *hand.begin() } };
  hand.erase(hand.begin());

  while (!hand.empty()) {
    bool added = false;
    for (auto& h : hand) {
      if (S[S.size()-1].find(h) != S[S.size()-1].end())
        continue;
      // printf("Does %d connect to current set: ", h);
      for (auto& s : S[S.size()-1]) {
        if ((h == ((s  +  1) % 13)) || (h == ((s  + 12) % 13))) {
          S[S.size()-1].insert(h);
          hand.erase(find(hand.begin(), hand.end(), h));
          // printf("yes\n");
          added = true;
          break;
        }
      }
      if (added)
        break;
    }

    // We didn't add anything new to our current set
    if (!added) {
      if (!hand.empty()) {
        S.push_back({ *hand.begin() });  
        hand.erase(hand.begin());
      }
    }
  }

  vector<int> runs;
  // printf("Set Sizes: ");
  int r5 = 0;
  int r4 = 0;
  int r3 = 0;
  int r2 = 0;
  for (auto& s : S) {
    runs.push_back((int)s.size());
    // printf("%d ", runs[runs.size()-1]);
    if (s.size() == 5)
      r5++;
    else if (s.size() == 4)
      r4++;
    else if (s.size() == 3)
      r3++;
    else if (s.size() == 2)
      r2++;
  }
  // printf("\n");
  if (r5 > 0)
    return 100.0;
  if (r4 > 0)
    return 10.0;
  if (r3 > 0 && r2 > 0)
    return 5.0;
  if (r3 > 0)
    return 3.0;
  if (r2 > 1)
    return 1.0;
  return 0.0;
}

int main() {

  char A[5], B[5], C[5], D[5], E[5];
  while(scanf("%s %s %s %s %s", A, B, C, D, E) != EOF) {
    string done = A;
    if (done == "#")
      return 0;
    int deck[13];
    for (int i=0; i<13; i++) 
      deck[i] = 4;
    deck[M[A[0]]]--;
    deck[M[B[0]]]--;
    deck[M[C[0]]]--;
    deck[M[D[0]]]--;
    deck[M[E[0]]]--;
    vector<int> hand = { M[A[0]], M[B[0]], M[C[0]], M[D[0]], M[E[0]] };
    double maxE = evalHand(hand) - 1.0;
    // printf("Hand return: %lf\n", maxE);
    int toExchange = -1;
    for (int exchange=0; exchange<5; exchange++) {
      double expectedValue = -2.0;
      vector<int> handC = hand;
      for (int newCard = 0; newCard<13; newCard++) {
        handC[exchange] = newCard;
        double val = evalHand(handC);
        double prob = max(0.0, deck[newCard]/47.0);
        expectedValue += val*prob;
      }
      // printf("Exchange %d, E = %lf\n", exchange, expectedValue);
      if (expectedValue > maxE) {
        toExchange = exchange;
        maxE = expectedValue;
      }
    }
    if (toExchange == -1)
      printf("Stay\n");
    else {
      printf("Exchange ");
      string es;
      switch (toExchange) {
        case 0: { es = A; break; }
        case 1: { es = B; break; }
        case 2: { es = C; break; }
        case 3: { es = D; break; }
        case 4: { es = E; break; }
      }
      printf("%s\n", es.c_str());
    }
  }

  return 0;
}
