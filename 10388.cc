#include <bits/stdc++.h>
using namespace std;

int main() {
  int T;
  char janeS[100];
  char johnS[100];
  string janeStr, johnStr;
  scanf("%d\n\n", &T);
  while (T--) {
    // Top face down) is left, bottom is right
    list<char> janeFaceD;
    list<char> janeFaceU;

    // Top face up is left, bottom face up is right
    list<char> johnFaceD;
    list<char> johnFaceU;
    scanf("%s\n", janeS); 
    scanf("%s\n\n", johnS); 
    janeStr = janeS;
    johnStr = johnS;

    // Get deck
    for (int i=0; i<janeStr.length(); i++) {
      janeFaceD.push_back(janeStr[i]);
      johnFaceD.push_back(johnStr[i]);
    }

    // Play game
    int turns = 0;
    while (1) {

      // Each play flips a card
      janeFaceU.push_front(janeFaceD.front());
      johnFaceU.push_front(johnFaceD.front());
      turns++;

      // Remove the card from face down decks
      janeFaceD.pop_front();
      johnFaceD.pop_front();

      // Check for snap condition
      if (janeFaceU.front() == johnFaceU.front()) {
        if (random()/141%2 == 0) {
          printf("Snap! for Jane: ");
          while (!johnFaceU.empty()) {
            janeFaceU.push_front(johnFaceU.back());
            johnFaceU.pop_back();
          }

          for (auto& c : janeFaceU)
            printf("%c", c);
          printf("\n");
        } else {
          printf("Snap! for John: ");
          while (!janeFaceU.empty()) {
            johnFaceU.push_front(janeFaceU.back());
            janeFaceU.pop_back();
          }

          for (auto& c : johnFaceU)
            printf("%c", c);
          printf("\n");

        }
      }

      // Check if either's decks ran out
      if (janeFaceD.empty()) {
        if (janeFaceU.empty()) {
          printf("John wins.\n");
          break;
        }
        while (!janeFaceU.empty()) {
          janeFaceD.push_front(janeFaceU.front());
          janeFaceU.pop_front();
        }
      }

      // Check if either's decks ran out
      if (johnFaceD.empty()) {
        if (johnFaceU.empty()) {
          printf("Jane wins.\n");
          break;
        }
        while (!johnFaceU.empty()) {
          johnFaceD.push_front(johnFaceU.front());
          johnFaceU.pop_front();
        }
      }

      // Check turn count
      if (turns == 1000)  {
        printf("Keeps going and going ...\n");
        break;
      }
    }

    if (T > 0)
      printf("\n");
  }
  return 0;
}
