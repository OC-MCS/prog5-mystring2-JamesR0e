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
	/*for (int i = 0; i < (strlen(a) + 1); i++)
	{
		ptr[i] = a[i];
	}*/
	strcpy_s(ptr, (strlen(a) + 1), a);
}
MyString::MyString(MyString& other)
{
	ptr = new char[strlen(other.ptr) + 1];
	/*for (int i = 0; i < (strlen(other.ptr) + 1); i++)
	{
		ptr[i] = other.ptr[i];
	}*/
	strcpy_s(ptr, (strlen(other.ptr) + 1), other.ptr);
}
MyString::~MyString()
{
	delete[] ptr;
}
void MyString::operator=(MyString other)
{
	delete[] ptr;
	ptr = new char[strlen(other.ptr) + 1];
	/*for (int i = 0; i < (strlen(other.ptr) + 1); i++)
	{
		ptr[i] = other.ptr[i];
	}*/
	strcpy_s(ptr, (strlen(other.ptr) + 1), other.ptr);
}
MyString MyString::operator+(MyString other)
{
	MyString a; //testing purposes
	return a;//testing purposes
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

