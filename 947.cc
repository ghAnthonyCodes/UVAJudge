#include <bits/stdc++.h>
using namespace std;

bool isConsistent(vector<int> &G, vector<int> &T, int a, int b) {

  // DAT
  vector<int> remain = vector<int>(10, 0);
  for (auto& t : T)
    remain[t]++;

  int aa = 0, bb = 0;
  for (int i=0; i<G.size(); i++) {
    if (G[i] == T[i]) {
      aa++;
      remain[G[i]]--;
    }
  }
  for (int i=0; i<G.size(); i++) {
    if (G[i] != T[i] && remain[G[i]] > 0) {
      bb++;
      remain[G[i]]--;
    }
  }
  return (a == aa) && (b == bb);
}

int main() {
  
  int Tin, t, a, b;
  vector<int> T, G;
  scanf("%d", &Tin);
  while (Tin--) {
    scanf("%d %d %d", &t, &a, &b);
    G = vector<int>();
    T = vector<int>();
    while (t > 0) {
      T.push_back(t % 10);
      G.push_back(1);
      t /= 10;
    }
    int consistent = 0;
    while (1) {
      // isConsistent(i, 2, 2, 1234);
      if (isConsistent(G, T, a, b))
        consistent++;
      G[G.size()-1]++;
      int ptr = G.size()-1;
      while (ptr >= 0 && G[ptr] == 10) {
        G[ptr] = 1;
        ptr--;
        if (ptr < 0)
          break;
        G[ptr]++;
      }
      if (ptr == -1)
        break;
    }
    printf("%d\n", consistent);
  }
  return 0;
}
