#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

int main() {
   char ss[10];
   while (cin.getline(ss, 10)) {
      std::string S = ss;
      cout << S << endl;
   }
   return 0;
}
