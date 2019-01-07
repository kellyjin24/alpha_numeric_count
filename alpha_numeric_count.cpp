#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int i;
int numAlphaNum(char []);
int numAlpha(char []);
int numDigits(char []);
int numWords(char []);
int startTed(char []);
int endTed(char []);
int middleTed(char []);

int main() {
	string str;
	char answer;
	
	// Initialize

	cout << endl;
	cout << "This program is a text statistical analyzer. It accepts an input from the user" << endl;
	cout << "that can include letters ('a', ..., 'z', 'A', ..., 'Z'), digits (0, ..., 9)," << endl;
	cout << "special characters (space and new line), and punctuation characters ('.', ',', ';')." << endl;
	cout << "This program recognizes a word to be a sequence of alphanumeric characters (letters" << endl;
	cout << "and numbers), delimited by two separators. A separator is any non-alphanumeric character." << endl;
	cout << "To end an input, the user must enter the '#' key." << endl;
	cout << endl;

	cout << "Would you like to enter a message to be analyzed? (y/n): ";
	cin >> answer;
	cout << endl;
	
	if (answer == 'y') {
		do {
			// User input into a string
			cout << "Enter a message (# to end message): ";
			getline(cin, str, '#');
			cout << endl;
	
			// String size
			i = str.size();

			// Declare a char array with the size of the string
			char ch[i];
	
			// Transfer string input to char array
			for (int a = 0; a <= i; a++) {
				ch[a] = str[a];
			}

			// Print
			cout << "Your message: ";
			for (int b = 0; b <= i; b++) {
			cout << ch[b];
			}
			cout << endl;
			cout << endl;

			// Total number of alphanumeric characters
			cout << "i. The number of alphanumeric characters is: ";
			cout <<	numAlphaNum(ch);
			cout << endl;
			cout << endl;

			// Total number of letters and their frequency with respect to alphranumeric characters
			double num1, den;
			double alphaFreq;

			num1 = numAlpha(ch);
			den = numAlphaNum(ch);
			alphaFreq = (num1/den) * 100;	

			cout << "ii. The number of letter characters is: ";
			cout << numAlpha(ch) << endl;
			cout << "That means " << alphaFreq;
			cout << "% of your alphanumeric characters were made up of letters!";
			cout << endl;
			cout << endl;

			// Total number of digits and their frequency with respect to alphanumeric characters
			double num2;
			double digitFreq;

			num2 = numDigits(ch);
			digitFreq = (num2/den) * 100;

			cout << "iii. The number of digits is: ";
			cout << numDigits(ch) << endl;
			cout << "That means " << digitFreq;
			cout << "% of your alphanumeric characters were made up of numbers!";
			cout << endl;
			cout << endl;

			// Total number of words
			cout << "iv. The number of words (alphanumeric characters) is: ";
			cout << numWords(ch);
			cout << endl;
			cout << endl;

			// Total number of words starting with "ted" and their frequency with respect
			// to the total number of words
			double num3, den2;
			double startTedFreq;

			num3 = startTed(ch);
			den2 = numWords(ch);
			startTedFreq = (num3/den2) * 100;

			cout << "v. The number of words starting with 'ted': ";
			
			cout << startTed(ch) << endl;
			cout << "That means " << startTedFreq;
			cout << "% of the words start with 'ted'!";
			cout << endl;
			cout << endl;

			// Total number of words ending with "ted" and their frequency with respect 
			// to the total number of words
			double num4;
			double endTedFreq;

			num4 = endTed(ch);
			endTedFreq = (num4/den2) * 100;

			cout << "vi. The number of words ending with 'ted': ";
			cout << endTed(ch) << endl;
			cout << "That means " << endTedFreq;
			cout << "% of words end with 'ted'!";
			cout << endl;
			cout << endl;

			// Total number of words having "ted" in the middle and their frequency with respect 
			// to the total number of words
			double num5;
			double middleTedFreq;

			num5 = middleTed(ch);
			middleTedFreq = (num5/den2) * 100;

			cout << "vii. The number of words having 'ted' in the middle: ";
			cout << middleTed(ch) << endl;
			cout << "That means " << middleTedFreq;
			cout << "% of words have 'ted' in the middle!";
			cout << endl;
			cout << endl;

			// Total number of sequence of "ted" and their frequency with respect to the total number of words
			double num6;
			double totalTedFreq;

			num6 = num3 + num4 + num5;
			totalTedFreq = (num6/den2) * 100;

			cout << "viii. The number of words having 'ted': ";
			
			cout << num6 << endl;
			cout << "That means " << totalTedFreq;
			cout << "% of words have 'ted' included in them!";
			cout << endl;
			cout << endl;

			cout << "Would you like to enter another message? (y/n): ";
			cin >> answer;

		} while (answer != 'n');
	}

	cout << endl;
	cout << "Program exited. Have a nice day!" << endl;
	cout << endl;

	return 0;
}

int numAlphaNum(char ch[]) {
	int count = 0;

	for (int a = 0; a <= i; a++) {
		if (ch[a] >= 'a' && ch[a] <= 'z') {
			count++;
		}

		if (ch[a] >= 'A' && ch[a] <= 'Z') {
			count++;
		}
	
		if (ch[a] >= '0' && ch[a] <= '9') { 
			count++;
		}		
	}

	return count;
}

int numAlpha(char ch[]) {
	int count = 0;

	for (int a = 0; a <= i; a++) {
		if (ch[a] >= 'a' && ch[a] <= 'z') {
			count++;
		}

		if (ch[a] >= 'A' && ch[a] <= 'Z') {
			count++;
		}
	}

	return count;
}

int numDigits(char ch[]) {
	int count = 0;

	for (int a = 0; a <= i; a++) {
		if (ch[a] >= '0' && ch[a] <= '9') {
			count++;
		}		
	}

	return count;
}

int numWords(char ch[]) {
	int count = 0;
	
	if ((ch[0] >= 'a' && ch[0] <= 'z') || (ch[0] >= 'A' && ch[0] <= 'Z') || (ch[0] >= '0' && ch[0] <= '9')) {
		count++;
	}

	for (int a = 0; a <= i; a++) {
		if (ch[a] == ' ' || ch[a] == '.' || ch[a] == ',' || ch[a] == '\n' || ch[a] == ';') {
			if ((ch[a + 1] >= 'a' && ch[a + 1] <= 'z') || (ch[a + 1] >= 'A' && ch[a + 1] <= 'Z') || (ch[a + 1] >= '0' && ch[a + 1] <= '9')) {
				count++;
			}	
		}
	}
	
	return count;
}		

int startTed(char ch[]) {
	int count = 0;

	if (ch[0] == 't' || ch[0] == 'T') {
		if (ch[1] == 'e' || ch[1] == 'E') {
			if (ch[2] == 'd' || ch[2] == 'D') {
				count++;
			}
		}
	} 

	for (int a = 0; a <= i; a++) {
		if (ch[a] == ' ' || ch[a] == '.' || ch[a] == ',' || ch[a] == '\n' || ch[a] == ';') {
			if (ch[a + 1] == 't' || ch[a + 1] == 'T') {
				if (ch[a + 2] == 'e' || ch[a + 2] == 'E') {
					if (ch[a + 3] == 'd' || ch[a + 3] == 'D') {
						count++;
					}
				}
			}
		}
	}

	return count;

}	

int endTed(char ch[]) {
	int count = 0;

	if (ch[i - 1] == 'd' || ch[i - 1] == 'D') {
		if (ch[i - 2] == 'e' || ch[i - 2] == 'E') {
			if (ch[i - 3] == 't' || ch[i - 3] == 'T') {
				if (ch[i - 4] == ' ' || ch[i - 4] == '.' || ch[i - 4] == ',' || ch[i - 4] == '\n' || ch[i - 4] == ';') {
					count = 0;
				}		

				else {

					count++;
				}

				
			}
		}
	}

	for (int a = i; a >= 0; a--) {
		if (ch[a] == ' ' || ch[a] == '.' || ch[a] == ',' || ch[a] == '\n' || ch[a] == ';') {
			if (ch[a - 1] == 'd' || ch[a - 1] == 'D') {
				if (ch[a - 2] == 'e' || ch[a - 2] == 'E') {
					if (ch[a - 3] == 't' || ch[a - 3] == 'T') {
						if (ch[i - 4] == ' ' || ch[i - 4] == '.' || ch[i - 4] == ',' || ch[i - 4] == '\n' || ch[i - 4] == ';') {
							count = 0;
						}

						else{
							count++;
						}
					}
				}
			}
		}
	
	}

	return count;
}

int middleTed(char ch[]) {
	int count = 0;

	for (int a = 0; a <= i; a++) {
		if ((ch[a] >= 'a' && ch[a] <= 'z') || (ch[a] >= 'A' && ch[a] <= 'Z') || (ch[a] >= '0' && ch[a] <= '9')) {
			if (ch[a + 1] == 't' || ch[a + 1] == 'T') {
				if (ch[a + 2] == 'e' || ch[a + 2] == 'E') {
					if (ch[a + 3] == 'd' || ch[a + 3] == 'D') {
						if ((ch[a + 4] >= 'a' && ch[a + 4] <= 'z') || (ch[a + 4] >= 'A' && ch[a + 4] <= 'Z') || (ch[a + 4] >= '0' && ch[a + 4] <= '9')) {
							count++;
						}
					}
				}
			}
		}
	}

	return count;
}

