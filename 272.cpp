#include <cstdio>
#include <vector>

int main() {
   char c;
   int quotes = 0;
   while ((c = getchar()) != EOF) {
      if (c != '"') {
         printf("%c", c);
         continue;
      }
      if (quotes & 1) 
         printf("''");
      else
         printf("``");
      quotes++;
   }
   return 0;
}
