#pragma once
#include <iostream>
using namespace std;
class MyString;

ostream &operator<<(ostream & strm, const MyString & obj);

class MyString
{
private:
	char* ptr;
public:
	//default constructor
	MyString();
	//parameter constructor
	MyString(char*);
	//copy constructor
	MyString(MyString&);
	//a destructor
	~MyString();
	//assignment operator
	MyString operator=(MyString other);
	//addition operator
	MyString operator+(MyString other);
	//comparison == operator
	bool operator==(MyString other);
	//getter cstring ptr
	char* getcstringptr() const;
};

