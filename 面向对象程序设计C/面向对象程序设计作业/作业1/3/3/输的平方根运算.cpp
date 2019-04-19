/*建立求某一个数的平方根函数，利用函数重载分别定义求整型、实型和双精度型数据*/
#include<iostream>
using namespace std;
#include<math.h>
int sq(int i)
{
	return sqrt(i);
}
float sq(float j)
{
	return sqrt(j);
}
double sq(double k)
{
	return sqrt(k);
}
int main()
{
	int i=16;
	float j=2.25;
	double k=1.123456789101112;
	cout<<"i的平方根是" << sq(i) << endl;
	cout<< "j平方根是" << sq(j) << endl;
	cout<< "k平方根是" << sq(k) << endl;
}