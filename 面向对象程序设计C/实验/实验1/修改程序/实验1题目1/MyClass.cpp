#include<iostream>
using namespace std;

#include"Myclass.h"
MyClass::MyClass(int a, int b)
{
	x = a;
	y = b;
}
void MyClass::Print()
{
	cout << "x = " << x << endl;
	cout << "y = " << y << endl;
}