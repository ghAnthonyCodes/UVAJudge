#include <cstdio>
#include <map>
#include <iostream>
using namespace std;


int main() {
  std::map<std::string, char> M = { 
    { ".-", 'A' },
    { "-...", 'B' }, 
    { "-.-.", 'C' }, 
    { "-..", 'D' }, 
    { ".", 'E' }, 
    { "..-.", 'F' }, 
    { "--.", 'G' }, 
    { "....", 'H' }, 
    { "..", 'I' }, 
    { ".---", 'J' }, 
    { "-.-", 'K' }, 
    { ".-..", 'L' }, 
    { "--", 'M' }, 
    { "-.", 'N' }, 
    { "---", 'O' }, 
    { ".--.", 'P' }, 
    { "--.-", 'Q' }, 
    { ".-.", 'R' }, 
    { "...", 'S' },
    { "-", 'T' }, 
    { "..-", 'U' }, 
    { "...-", 'V' }, 
    { ".--", 'W' }, 
    { "-..-", 'X' }, 
    { "-.--", 'Y' }, 
    { "--..", 'Z' }, 
    { "-----", '0' }, 
    { ".----", '1' },
    { "..---", '2' },
    { "...--", '3' },
    { "....-", '4' },
    { ".....", '5' },
    { "-....", '6' },
    { "--...", '7' },
    { "---..", '8' },
    { "----.", '9' },
    { ".-.-.-", '.' },
    { "--..--", ',' },
    { "..--..", '?' },
    { ".----.", '\'' },
    { "-.-.--", '!' },
    { "-..-.", '/' },
    { "-.--.", '(' },
    { "-.--.-", ')' },
    { ".-...", '&' },
    { "---...", ':' },
    { "-.-.-.", ';' },
    { "-...-", '=' },
    { ".-.-.", '+' },
    { "-....-", '-' },
    { "..--.-", '_' },
    { ".-..-.", '"' },
    { ".--.-.", '@' },
  };
  int T;
  char line[2001];
  cin.getline(line, 5);
  sscanf(line, "%d", &T);

  for (int t=0; t<T; t++) {
    if (t > 0)
      printf("\n");
    printf("Message #%d\n", t+1);
    cin.getline(line, 2001);
    std::string lineStr = line;

    // Find the words
    std::string word = "";
    for (int i=0; i<lineStr.length(); i++) {

      // end of word
      if (i > 0 && lineStr[i] == ' ' && lineStr[i-1] == ' ') {
        printf(" ");
      }

      // End of letter
      else if (lineStr[i] == ' ') {
        // lookup letter  
        printf("%c", M[word]);
        word = "";
      }
      else {
        word += lineStr[i];
      }
    }
    if (word.length() > 0)
      printf("%c", M[word]);
    printf("\n");
  }

}
