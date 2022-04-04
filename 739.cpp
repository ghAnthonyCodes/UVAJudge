#include <cstdio>
#include <string>
#include <sstream>

//               A  B  C  D   E  F  G   H   I  J  K  L  M  N   O  P  Q  R  S  T   U  V   W  X   Y  Z
int map[26] = { -1, 1, 2, 3, -1, 1, 2, -1, -1, 2, 2, 4, 5, 5, -1, 1, 2, 6, 2, 3, -1, 1, -1, 2, -1, 2 };

int main() {
   char C[32];
   printf("%-8s %-24s %s\n", "", "NAME", "SOUNDEX CODE");
   while (scanf("%s", &C[0]) != EOF) {
      std::stringstream ss;
      std::string S = C;
      ss << S[0];
      int length = 1;
      char prev = map[S[0] - 'A'];
      for (int i=1; i<S.length(); i++) {
         if (map[S[i] - 'A'] == prev) {
            continue;
         }
         if (map[S[i] - 'A'] == -1) {
            prev = map[S[i] - 'A'];
            continue;
         }
         prev = map[S[i] - 'A'];
         ss << map[S[i] - 'A'];
         length++;
         if (length == 4) 
            break;
      }
      while (length++ <= 3)
         ss << '0';
      printf("%-8s %-24s %s\n", "", S.c_str(), ss.str().c_str());
   }
   printf("%-18s %s\n", "", "END OF OUTPUT");
   return 0;
}
