#include <cstdio>
#include <string>
#include <map>
#include <limits>
#include <iostream>

int main () {
  int N, P, R;
  float D;
  char name[81];
  int rfp=1;
  char line[100];
  bool first = true;
  while (std::cin.getline(line, 100)) {
    // Parse N and P
    sscanf(line, "%d %d", &N, &P);
    if (N == 0 && P == 0) 
      break;
    if (first)
      first = false;
    else
      printf("\n");
    
    std::map<std::string, float> proposalAndCost;
    std::map<std::string, int> proposalFilledCount;

    // Fetch requirement names
    for (int n=0; n<N; n++) {
      std::cin.getline(line, 100);
    }

    int maxFilled = std::numeric_limits<int>::min();
    float minPrice = std::numeric_limits<float>::max();

    for (int p=0; p<P; p++) {
      std::cin.getline(line, 100);
      std::string proposalName = line;

      // Fetch d = price, r = requirements met
      std::cin.getline(line, 100);
      sscanf(line, "%f %d", &D, &R);
      proposalAndCost[proposalName] = D;
      proposalFilledCount[proposalName] = R;
      if (R > maxFilled) {
        maxFilled = R;
        minPrice = D;
      } else if (R == maxFilled) {
        minPrice = std::min(minPrice, D);
      }

      // Fetch each requirement met, but this doesn't matter
      for (int r=0; r<R; r++) {
        std::cin.getline(line, 100);
      }
    }

    // Fetch answer
    for (auto& item : proposalFilledCount) {
      if ((item.second == maxFilled) && (proposalAndCost[item.first] == minPrice)) {
        printf("RFP #%d\n", rfp++);
        printf("%s\n", item.first.c_str());
        break;
      }
    }
  }
  return 0;
}
