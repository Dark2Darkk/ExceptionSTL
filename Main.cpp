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
