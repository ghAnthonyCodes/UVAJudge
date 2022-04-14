#include <bits/stdc++.h>
using namespace std;

int main() {

  int T;
  scanf("%d", &T);
  char cardc[10];
  string card;
  for (int tc = 1; tc <= T; tc++) {
    list<string> topHand;
    list<string> botHand;
    for (int i=0; i<27; i++) {
      scanf("%s", cardc);
      card = cardc;
      botHand.push_front(card);
    }
    for (int i=0; i<25; i++) {
      scanf("%s", cardc);
      card = cardc;
      topHand.push_front(card);
    }

    // Operations
    int y = 0;
    int x;
    for (int i=0; i<3; i++) {
      card = botHand.front(); 
      botHand.pop_front();
      if (card[0] >= '0' && card[0] <= '9')
        x = card[0] - '0';
      else
        x = 10;
      y += x;
      for (int i=0; i<10-x; i++)
        botHand.pop_front();
    }

    // Add cards in hand back to bottom
    while (!topHand.empty()) {
      botHand.push_front(topHand.back());
      topHand.pop_back();
    }

    // Get card
    for (int i=0; i<y-1; i++) {
      botHand.pop_back(); 
    }
    
    printf("Case %d: %s\n", tc, botHand.back().c_str());
  }
  return 0;
}
