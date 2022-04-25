#include <bits/stdc++.h>
using namespace std;

#define vi vector<int> 
#define INF 10000000

bool green(int t, int cycle) {
  // 20:  0 to 14 green
  //     15 to 19 orange
  //     20 to 39 red
  // need to find out where we are in entire cycle
  // printf("green(%d, %d)\n", t, cycle);
  int rem = t % (cycle*2);
  // printf("  rem: %d\n", rem);
  bool R = rem < (cycle - 5);
  // printf("    T: %d\n", R);
  return R;
}

string sToTime(int seconds) {
  char ret[10];
  sprintf(ret, "%02d:%02d:%02d", seconds/3600, (seconds % 3600)/60, seconds%60);
  string R = ret;
  return R;
}

int main() {

  int cycle;
  int q = 0;
  int start = INF;
  vector<int> V;
  while (scanf("%d", &cycle)) {

    // Exit condition
    if (cycle == 0) {
      q++;
      if (q > 1)
        return 0;
      // Solve
      else {
        int t = start;
        while (t <= 5*3600) {
          bool allGreen = true;
          for (auto& c : V) {
            // printf("Checking(%d, %d)->%d\n", t, c, green(t, c)); 
            allGreen &= green(t, c);
          }
          if (allGreen) {
            printf("%s\n", sToTime(t).c_str());
            break;
          }
          t++;
          if (t > 5*3600) {
            printf("Signals fail to synchronise in 5 hours\n");
            break;
          }
        }

        // Reset variables
        V = vi();
        start = INF;
      }
      continue;
    }
    q = 0;
    V.push_back(cycle);
    start = min(start, cycle);
  }

  return 0;
}


