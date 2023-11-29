#include<iostream>
#include<exception>
#include<cctype>

using namespace std;


class invalidCharacterException : public exception {
public:
	const char* what() const throw() {
		return "Invalid Character Exception";
	}
};

class invalidRangeException : public exception {
public:
	const char* what() const throw() {
		return "Invalid Range Exception";
	}
};

char character(char start, int offset) {
	if (!isalpha(start)) {
		throw invalidCharacterException();
	}

	char result = start + offset;

	if (!isalpha(result) || (islower(start) != islower(result))) {
		throw invalidRangeException();
	}

	return result;
}

int main() {
	try {
		cout << "character('a', 1) should return: " << character('a', 1) << endl;
		cout << "character('Z', -1) should return: " << character('Z', -1) << endl;
		cout << "character('?', 5) should throw an exception" << endl;
		cout << "Result" << character('?', 5) << endl;
	}
	catch (const exception& e) {
		cerr << "Exception caught: " << e.what() << endl;
	}


	try {
		cout << "character('A', 32) should throw an exception" <<  endl;
		cout << "Result: " << character('A', 32) << endl;
	}
	catch (const exception& e) {
		cerr << "Exception caught: " << e.what() << endl;
	}

	return 0;
}

