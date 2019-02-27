#include <iostream>
#include "MyString.h"
using namespace std;

int main()
{
	char lol[] = "hello";
	MyString a(lol);
	cout << lol;
	MyString b(a);
	cout << b;
	char meow[] = "meow";
	MyString c(meow);
	cout << endl;
	cout << a + c << endl;
	





	return 0;
}