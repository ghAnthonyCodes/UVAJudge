#include <bits/stdc++.h>
using namespace std;

int main() {

  int T, N, d;
  scanf("%d", &T);
  for (int tc = 1; tc <= T; tc++) {
    scanf("%d", &N);
    int mile = 0, juice = 0;
    for (int n=0; n<N; n++) {
      scanf("%d", &d);      
      mile += (int)(10.0*ceil((d+1)/30.0));
      juice += (int)(15.0*ceil((d+1)/60.0));
    }
    printf("Case %d: ", tc);
    if (mile < juice)
      printf("Mile %d\n", mile);
    else if (juice < mile)
      printf("Juice %d\n", juice);
    else
      printf("Mile Juice %d\n", juice);
  }
  return 0;
}
