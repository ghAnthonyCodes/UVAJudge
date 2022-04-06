#include <iostream>
#include <string>
#include <map>
using namespace std;
int main() {
   int N;
   std::string S;
   std::map<std::string, int> M;
   scanf("%d\n", &N);
   while (N--) {
      getline(cin, S);
      char nameBuffer[100];
      int ptr=0;
      while (S[ptr] != ' ') {
         nameBuffer[ptr] = S[ptr];
         ptr++;
      }
      nameBuffer[ptr] = '\0';
      std::string country = nameBuffer;
      if (M.find(country) == M.end())
         M[country] = 1;
      else
         M[country]++;
   }
   for (auto& item : M)
      printf("%s %d\n", item.first.c_str(), item.second);
   return 0;
}
