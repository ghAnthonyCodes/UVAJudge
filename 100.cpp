#include <cstdio>
#include <vector>
#define ll long long

int main() {
   ll i, j, x, y;
   while (scanf("%lld %lld", &i, &j) != EOF) {
      ll ml = 0;
      if (j < i) {
         x = j;
         y = i;
      } else {
         x = i;
         y = j;
      }
      for (ll s = x; s <= y; s++) {
         ll l = 1;
         ll sp = s;
         while (sp != 1) {
            if (sp & 1)
               sp = sp*3 + 1;
            else
               sp >>= 1;
            l++;
         }
         ml = std::max(l, ml);
      }
      printf("%lld %lld %lld\n", i, j, ml);
   }
   return 0;
}
