#include <cstdio>
#include <string>

int main() {
   char B[50];
   while (scanf("%s", &B[0]) != EOF) {
      // Is a arabic number
      if (B[0] >= '0' && B[0] <= '9') {
         int ptr = 0;
         int number = 0;
         while (B[ptr] != '\0') {
            number *= 10;
            number += B[ptr]-'0';
            ptr++;
         }

         // Convert arabic to roman
         std::string ans = "";
         while (number > 0) {
            if (number == 4) {
               ans += "IV";
               number -= 4;
            } else if (number == 9) {
               ans += "IX";
               number -= 9;
            } else if (number >= 40 && number <= 49) {
               ans += "XL";
               number -= 40;
            } else if (number >= 90 && number <= 99) {
               ans += "XC";
               number -= 90;
            } else if (number >= 400 && number <= 499) {
               ans += "CD";
               number -= 400;
            } else if (number >= 900 && number <= 999) {
               ans += "CM";
               number -= 900;
            } else if (number >= 1000) {
               ans += "M";
               number -= 1000;
            } else if (number >= 500) {
               ans += "D";
               number -= 500;
            } else if (number >= 100) {
               ans += "C";
               number -= 100;
            } else if (number >= 50) {
               ans += "L";
               number -= 50;
            } else if (number >= 10) {
               ans += "X";
               number -= 10;
            } else if (number >= 5) {
               ans += "V";
               number -= 5;
            } else if (number >= 1) {
               ans += "I";
               number -= 1;
            }
         }
         printf("%s\n", ans.c_str());
      } else {
         std::string R = B;
         int ans = 0;
         for (int i=0; i<R.length(); i++) {
            if (i == R.length()-1) {
               if (R[i] == 'I')
                  ans++;
               else if (R[i] == 'V')
                  ans += 5;
               else if (R[i] == 'X')
                  ans += 10;
               else if (R[i] == 'L')
                  ans += 50;
               else if (R[i] == 'C')
                  ans += 100;
               else if (R[i] == 'D')
                  ans += 500;
               else if (R[i] == 'M')
                  ans += 1000;
               continue;
            }
               
            if (R[i] == 'I' && R[i+1] == 'V')
               ans--;
            else if (R[i] == 'I' && R[i+1] == 'X')
               ans--;
            else if (R[i] == 'I')
               ans++;
            else if (R[i] == 'V')
               ans += 5;
            else if (R[i] == 'X' && R[i+1] == 'L')
               ans -= 10;
            else if (R[i] == 'X' && R[i+1] == 'C')
               ans -= 10;
            else if (R[i] == 'X')
               ans += 10;
            else if (R[i] == 'L')
               ans += 50;
            else if (R[i] == 'C' && R[i+1] == 'D')
               ans -= 100;
            else if (R[i] == 'C' && R[i+1] == 'M')
               ans -= 100;
            else if (R[i] == 'C')
               ans += 100;
            else if (R[i] == 'D')
               ans += 500;
            else if (R[i] == 'M')
               ans += 1000;
         }
         printf("%d\n", ans);
      }
   }
   return 0;
}
