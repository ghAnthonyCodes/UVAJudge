#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cstring>
using namespace std;

std::vector<std::string> split(char *S) {
   std::vector<std::string> sVec;
   char *ptr;
   ptr = strtok(S, " ");
   while (ptr != NULL) {
      std::string s = ptr;
      ptr = strtok(NULL, " ");
      sVec.push_back(s);
   }
   return sVec;
}

int main() {
   // 13 bit numbers
   //        A, A#, B, C, C#, D, D#, E, F, F#, G, G#
   std::vector<int> keys = { 0b101101011010 };
   for (int key=1; key<12; key++)
      keys.push_back((keys[key-1] >> 1) | ((keys[key - 1] & 1) << 11));
   std::map<string, int> M = {
      { "A",  11 }, { "A#", 10 }, { "B",   9 }, { "C",   8 },
      { "C#",  7 }, { "D",   6 }, { "D#",  5 }, { "E",   4 },
      { "F",   3 }, { "F#",  2 }, { "G",   1 }, { "G#",  0 },
   };
   std::map<int, std::string> M2 = {
      { 0, "C" },
      { 1, "C#" },
      { 2, "D" },
      { 3, "D#" },
      { 4, "E" },
      { 5, "F" },
      { 6, "F#" },
      { 7, "G" },
      { 8, "G#" },
      { 9, "A" },
      { 10, "A#" },
      { 11, "B" },
   };
   char S[1014];
   std::string note;
   while (true) {
      cin.getline(S, 1024);
      std::vector<std::string> notes = split(S);
      if (notes[0] == "END")
         return 0;

      int key = 0;
      for (auto& note : notes)
         key |= (1 << M[note]);
      bool firstKey = true;
      for (int k=0; k<keys.size(); k++) {
         if ((keys[k] | key) == keys[k]) {
            if (firstKey) {
               printf("%s", M2[k].c_str());
               firstKey = false;
            } else {
               printf(" %s", M2[k].c_str());
            }
         }
      }
      printf("\n");

   }
   return 0;
}
