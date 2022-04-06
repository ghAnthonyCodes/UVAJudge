#include <iostream>
#include <cmath>
using namespace std;

int main() {
  char input[16];
  while (cin.getline(input, 16)) {
    int h = (input[0] - '0')*10 + (input[1] - '0');
    int m = (input[2] - '0')*10 + (input[3] - '0');
    int s = (input[4] - '0')*10 + (input[5] - '0');
    int c = (input[6] - '0')*10 + (input[7] - '0');
    double totalTradSeconds = h*3600 + m*60 + s + c/100.0;
    double totalDecSeconds = totalTradSeconds/0.864;

    // tradSec   decSec*tradSecInaDay
    // ----    = ------------
    //           decSecInaDay

    // New time
    h = floor(totalDecSeconds / 10000.0);
    totalDecSeconds -= h*10000.0;
    m = floor(totalDecSeconds / 100.0);
    totalDecSeconds -= m*100.0;
    s = floor(totalDecSeconds);
    totalDecSeconds -= s;
    c = floor(totalDecSeconds*100.0);
    printf("%01d%02d%02d%02d\n", h, m, s, c);
  }
  
  return 0;
}
