#include <iostream>
#include <string>
#include <sstream>
#include <cctype>

using namespace std;

bool is_vowel(char x) {
	switch (x) {
		case 'a':
		case 'A':
		case 'e':
		case 'E':
		case 'i':
		case 'I':
		case 'o':
		case 'O':
		case 'u':
		case 'U':
			return true;
	}
	return false;
}

int main() {
	string line;
	string word;
	char c;
	while (c = getchar()) {
		if (c == EOF)
			break;
		if (isalpha(c)) {
			word += c;
		}
		else if (word.length() > 0) {
			if (is_vowel(word[0]))
				cout << word << "ay";
			else
				cout << word.substr(1, word.length() - 1) << word[0] << "ay";
			cout << c;
			word = "";
		}
		else {
			cout << c;
		}
	}
	return 0;
}