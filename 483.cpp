#include <cstdio>
#include <string>
#include <vector>

int main() {
   std::vector<char> C;
   char c;
   while ((c = getchar()) != EOF) {
      if (c == ' ') {
         for (int i=C.size()-1; i>=0; i--)
            printf("%c", C[i]);
         printf(" ");
         C = std::vector<char>();
      } else if (c == '\n') {
         for (int i=C.size()-1; i>=0; i--)
            printf("%c", C[i]);
         printf("\n");
         C = std::vector<char>();
      } else {
         C.push_back(c);
      }
   }
   return 0;
}
