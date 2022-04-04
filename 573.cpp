#include <cstdio>
#include <cmath>
#include <algorithm>

int main() {
   float h, u, d, f;
   while (scanf("%f %f %f %f", &h, &u, &d, &f) != EOF) {
      if (h == 0) 
         break;
      float loss = f*u/100.0;
      float height = 0;
      int day = 1;

      while (1) {

         // Sim day
         height += u;
         if (height > h) {
            printf("success on day %d\n", day);
            break;
         }

         // Sim night
         height -= d;
         if (height < 0) {
            printf("failure on day %d\n", day);
            break;
         }

         u = std::max(0.0f, u - loss);
         day++;
      }
   }
   return 0;
}
