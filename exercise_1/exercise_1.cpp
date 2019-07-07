#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;

const string VOWEL_LETTERS = "aeiou";

struct Result {
	int vowels{0};
	int consonants{0};
	int others{0};
};

void count_words(char character, int& vowels, int& consonants, int& others) {
	if (isalpha(character)) {
		if (VOWEL_LETTERS.find(tolower(character)) != string::npos) {
			++vowels;
		} else {
			++consonants;
		}
	} else {
		++others;
	}
};

int main(int argc, char **argv) {
	Result result;
	string word;

	if (argc == 1) {
		cout<<"Enter words (q to quit):\n";
			while ((cin >> word)&&(word != "q")) {
				count_words(word[0], result.vowels, result.consonants,  result.others);
			}
	} else {
		ifstream input_file;
		input_file.open(argv[1]);
		if (input_file.is_open()) {
			while (input_file>>word) {
				count_words(word[0], result.vowels, result.consonants,  result.others);
			}
			input_file.close();
		} else {
			cerr<<"Unable to open file.\n";
		}
	}

	cout<<result.vowels<<" words beginning with vowel\n";
	cout<<result.consonants<<" words beginning with consonant\n";
	cout<<result.others<<" others\n";

	return 0;
}
