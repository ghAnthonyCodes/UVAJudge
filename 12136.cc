#include <bits/stdc++.h>

int main() {
  int N;
  char A[10], B[10], C[10], D[10];
  scanf("%d", &N);
  for (int tc = 1; tc <= N; tc++) {
    scanf("%s %s %s %s", A, B, C, D);
    int busy_s = ((A[0] - '0')*10 + (A[1] - '0'))*60 + 10*(A[3] - '0') + (A[4] - '0');
    int busy_e = ((B[0] - '0')*10 + (B[1] - '0'))*60 + 10*(B[3] - '0') + (B[4] - '0');
    int meet_s = ((C[0] - '0')*10 + (C[1] - '0'))*60 + 10*(C[3] - '0') + (C[4] - '0');
    int meet_e = ((D[0] - '0')*10 + (D[1] - '0'))*60 + 10*(D[3] - '0') + (D[4] - '0');

    // If busy start is earlier than meet start, then busy end has to be before meet_s
    if (busy_s < meet_s) {
      if (busy_e < meet_s)
        printf("Case %d: Hits Meeting\n", tc);
      else 
        printf("Case %d: Mrs Meeting\n", tc);
    }
    else if (busy_s > meet_e)
      printf("Case %d: Hits Meeting\n", tc);
    else
      printf("Case %d: Mrs Meeting\n", tc);
  }

  return 0;
}
