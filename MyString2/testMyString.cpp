#include <iostream>
#include "MyString.h"
using namespace std;

int main()
{
	char lol[] = "hello";
	MyString a;
	cout << a << endl;
	MyString b(lol);
	cout << b;
	a = b;
	cout << a;




	return 0;
}