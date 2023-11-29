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

