#include <iostream>
#include <string>
#include <ctype.h>

using namespace std;

char checkIfPalindrome(string&);
string to_lower(string);
bool non_alpha(string&);
void delete_non_alpha(string&);
int find_position(string&);
void makeEasyString(string&);	//convert any given string to lower case and remove symbols

int main() {
	string test = "A new order begaun, a more Roman age bred Rowena.";
	string word = to_lower(test);
	makeEasyString(word);
	cout<<checkIfPalindrome(word);
	
  return 0;
}
string to_lower(string word) {
	int sz = word.size();
	char temp;
	for (int i = 0; i<sz; i++) {
		temp = tolower(word[i]);
		word[i] = temp;
	}
	return word;
}
bool non_alpha(string &word) {
	for (int i = 0; i < word.size(); i++) {
		if (!isalpha(word[i])) {
			return true;	//if non-alpha found return 1
		}
	}
	return false;		//if string contains only letters, return 0
}
void delete_non_alpha(string &word) {
	int pos = 0;
	const int number_of_chars=1;
	for (int i = 0; i < word.size(); i++) {
		if (!isalpha(word[i])) {
			pos = i;
			break;
		}
	}
	word.erase(pos,number_of_chars);
}
void makeEasyString(string &word) {
	while (non_alpha(word)) {
		delete_non_alpha(word);
	}
}
char checkIfPalindrome(string &word) {
	int end_of_word = word.size() - 1;
	for (int i = 0; i < word.size() / 2; i++) {
		if (word[i] != word[end_of_word]) {
			return 'N';
		}
		end_of_word--;
	}
	return 'Y';
}