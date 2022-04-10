#include <cstdio>

int main() {

  int T, a, b;
  scanf("%d", &T);
  for (int tc = 0; tc < T; tc++) {
    scanf("%d %d", &a, &b);
    if (a < b) 
      printf("<\n");
    else if (a > b) 
      printf(">\n");
    else
      printf("=\n");
  }
  return 0;
}
