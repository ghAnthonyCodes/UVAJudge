#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vc vector<char>
#define vvc vector<vc>

void add_digit(vvc &V, int digit, int s, int start) {
  int width = s + 2;

  // Segment 0
  switch (digit) {
    case 2:
    case 3:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 0:
      for (int c = 0; c < s; c++)
        V[0][start + c + 1] = '-';
  }

  // Segment 1
  for (int r = 1; r < s + 1; r++) {
    switch (digit) {
      case 1:
      case 2:
      case 3:
      case 4:
      case 7:
      case 8:
      case 9:
      case 0:
        V[r][start + width - 1] = '|';
    }
    switch (digit) {
      case 4:
      case 5:
      case 6:
      case 8:
      case 9:
      case 0:
        V[r][start] = '|';
    }
  }

  // Segment 2
  switch (digit) {
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 8:
    case 9:
      for (int c = 0; c < s; c++)
        V[s + 1][start + c + 1] = '-';
  }

  // Segment 3
  for (int r = s + 2; r < 2*s + 2; r++) {
    switch (digit) {
      case 1:
      case 3:
      case 4:
      case 5:
      case 6:
      case 7:
      case 8:
      case 9:
      case 0:
        V[r][start + width - 1] = '|';
    }
    switch (digit) {
      case 2:
      case 6:
      case 8:
      case 0:
        V[r][start] = '|';
    }
  }

  // Segment 4
  switch (digit) {
    case 2:
    case 3:
    case 5:
    case 6:
    case 8:
    case 9:
    case 0:
      for (int c = 0; c < s; c++)
        V[2*s + 2][start + c + 1] = '-';
  }
}

int main() {
  int s;
  char B[16];
  while(1) {
    scanf("%d %s", &s, B);
    string digits = B;
    if (s == 0 && digits == "0")
      break;

    // Vector is 2*s + 3 tall
    vvc V = vvc(2*s + 3, vc((s+2)*digits.size() + digits.size() - 1, ' '));

    for (int i = 0; i < digits.size(); i++) {
      add_digit(V, digits[i]-'0', s, (s+2)*i + i);
    }

    for (auto row : V) {
      for (auto col : row) 
        printf("%c", col);
      printf("\n");
    }
    printf("\n");
  }
  return 0;
}

