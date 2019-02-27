#include <iostream>
#include <fstream>
#include "MyString.h"
using namespace std;

MyString::MyString()
{
	ptr = nullptr;
}
MyString::MyString(char* a)
{
	ptr = new char[strlen(a) + 1];
	strcpy_s(ptr, (strlen(a) + 1), a);
}
MyString::MyString(MyString& other)
{
	ptr = new char[strlen(other.ptr) + 1];
	strcpy_s(ptr, (strlen(other.ptr) + 1), other.ptr);
}
MyString::~MyString()
{
	delete[] ptr;
}
MyString MyString::operator=(MyString other)
{
	if (this != &other)
	{
		delete[] ptr;
		ptr = new char[strlen(other.ptr) + 1];
		strcpy_s(ptr, (strlen(other.ptr) + 1), other.ptr);
	}
	return *this;
}
MyString MyString::operator+(MyString other)
{
	MyString a;
	a.ptr = new char[strlen(ptr) + strlen(other.ptr) + 1];
	strcpy_s(a.ptr, (strlen(ptr) + strlen(other.ptr) + 1), ptr);
	strcat_s(a.ptr, (strlen(ptr) + strlen(other.ptr) + 1), other.ptr);
	return a;
}
bool MyString::operator==(MyString other)
{
	bool isequal = strcmp(ptr, other.ptr);
	return isequal;
}
char* MyString::getcstringptr() const
{
	return ptr;
}

//not a member
ostream &operator<<(ostream & strm, const MyString & obj)
{
	strm << obj.getcstringptr();
	return strm;
}

