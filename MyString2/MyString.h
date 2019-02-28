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
	MyString(const char*);
	//copy constructor
	MyString(MyString&);
	//a destructor
	~MyString();
	//assignment operator
	MyString operator=(const MyString & other);
	//addition operator
	MyString operator+(const MyString & other);
	//comparison == operator
	bool operator==(const MyString & other);
	//getter cstring ptr
	char* getcstringptr() const;
};

