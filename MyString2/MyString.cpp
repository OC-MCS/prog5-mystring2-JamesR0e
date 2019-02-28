#include <iostream>
#include <fstream>
#include "MyString.h"
using namespace std;

//====================================================== 
// default constructor: sets ptr to a nullptr
// parameters:  n/a
// return type: n/a
//====================================================== 
MyString::MyString()
{
	ptr = nullptr;
}

//====================================================== 
// parameter constructor: sets the ptr to allocated memory
// parameters: can be given a literal string or an array of characters
// return type: n/a
//====================================================== 
MyString::MyString(const char* a) 
{
	ptr = new char[strlen(a) + 1];
	strcpy_s(ptr, (strlen(a) + 1), a);
}

//====================================================== 
// copy constructor: itializing a mystring using a mystring
// parameters:  given a mystring
// return type: n/a
//====================================================== 
MyString::MyString(MyString& other)
{
	if (other.ptr != nullptr) //test
	{
		ptr = new char[strlen(other.ptr) + 1];
		strcpy_s(ptr, (strlen(other.ptr) + 1), other.ptr);
	}
	else
	{
		ptr = nullptr; //test
	}
}

//====================================================== 
// Destructor: deletes any allocated memory when a mystring instance is destroyed
// parameters:  n/a
// return type: n/a
//====================================================== 
MyString::~MyString()
{
	delete[] ptr;
}

//====================================================== 
// operator=: defines the = operator for MyString
// parameters: given an instance of mystring
// return type: Returns a mystring in the case that the string is the same
//====================================================== 
MyString MyString::operator=(const MyString & other)
{
	if (this != &other)
	{
		delete[] ptr;
		ptr = new char[strlen(other.ptr) + 1];
		strcpy_s(ptr, (strlen(other.ptr) + 1), other.ptr);
	}
	return *this;
}

//====================================================== 
// operator+: defines the + operator for MyString
// parameters:  given an instance of MyString
// return type: Returns a MyString of the 'sum'
//====================================================== 
MyString MyString::operator+(const MyString & other)
{
	MyString a;
	if (ptr == nullptr)
	{
		a.ptr = new char[strlen(other.ptr) + 1];
		strcpy_s(a.ptr, (strlen(other.ptr) + 1), other.ptr);
	}
	else if (other.ptr == nullptr)
	{
		a.ptr = new char[strlen(ptr) + 1];
		strcpy_s(a.ptr, (strlen(ptr) + 1), ptr);
	}
	else if (ptr == nullptr && other.ptr == nullptr)
	{
		a.ptr == '\0';
	}
	else
	{
		a.ptr = new char[strlen(ptr) + strlen(other.ptr) + 1];
		strcpy_s(a.ptr, (strlen(ptr) + strlen(other.ptr) + 1), ptr);
		strcat_s(a.ptr, (strlen(ptr) + strlen(other.ptr) + 1), other.ptr);
	}
	return a;
}

//====================================================== 
// operator==: defines the == operator for MyString
// parameters:  given an instance of MyString
// return type: returns true if equal
//====================================================== 
bool MyString::operator==(const MyString & other)
{
	bool isequal;
	if (ptr == nullptr && other.ptr == nullptr)
	{
		isequal = true;
	}
	else
	{
		isequal = strcmp(ptr, other.ptr);
	}
	return isequal;
}

//====================================================== 
// getcstringptr: gets the ptr
// parameters: n/a
// return type: returns the ptr
//====================================================== 
char* MyString::getcstringptr() const
{
	return ptr;
}

//====================================================== 
// &operator<<: cout for MyStrings
// parameters:  ostream instance and a mystream instance
// return type: ostream
//====================================================== 
//not a member function
ostream &operator<<(ostream & strm, const MyString & obj)
{
	if (obj.getcstringptr() != nullptr)
		strm << obj.getcstringptr();
	else
		strm << "\0";
	return strm;
}

