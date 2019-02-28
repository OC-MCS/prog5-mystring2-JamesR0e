//=====================================================
// James Roe
// 3/1/19
// Programming Assignment #5
// Description: MyString Class
//=====================================================
#include <iostream>
#include "MyString.h"
using namespace std;

//====================================================== 
// main: test driver for the MyString class
// parameters:  n/a
// return type: n/a
//====================================================== 
int main()
{
	//testing default constructor and parameter constructor

	MyString a("hello");
	char lol[] = " World";
	MyString b(lol);
	MyString c;
	MyString d;
	cout << "output a: " << a << endl; //output should be 'hello'
	cout << "output b: " << b << endl; //output should be ' World'
	cout << "output c: " << c << endl; //output should be blank

	//Testing assignment operator
	c = c;
	cout << "output c: " << c << endl; //output should be blank
	c = a;
	cout << "output c: " << c << endl; //output should be 'hello'
	d = "wassup";
	cout << "output d: " << d << endl; //output should be 'wassup'

	//Testing addition operator
	cout << "output a + b:" << a + b << endl; //output should be 'hello World'
	d = a + b;
	cout << "output d: " << d << endl; //output should be 'hello World'

	//Testing comparison operator
	if (a == c) //should return true
	{
		cout << "Comparison Worked!" << endl;
	}

	//Testing multiple assignment
	a = b = c;
	cout << "output a: " << a << endl; //output should be 'hello'
	cout << "output b: " << b << endl; //output should be 'hello'

	//more nullptr testing
	MyString e;
	MyString f(e);
	MyString g;
	e = "greetings";
	cout << "output e: " << e << endl; //output should be 'greetings'
	g = e + f;
	cout << "output g: " << g << endl; //output should still be 'greetings'
	MyString h;
	MyString i;
	MyString j;
	h = i + j;
	cout << "output h: " << h << endl; //output should be nothing
	if (i == j) //should return true
	{
		cout << "Comparison Worked!" << endl;
	}
	return 0;
}