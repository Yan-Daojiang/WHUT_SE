/*重载运算符+，-，实现复数的加减法*/
#include<iostream>
using namespace std;
class Complex    //定义复数类
{
public:
	Complex(double r = 0.0, double i = 0.0) {
		real = r; imag = i;
	}
	Complex operator + (Complex c2)    //将运算符"+"重载为成员函数 
	{ 
		return Complex(real + c2.real, imag + c2.imag);
	}
	Complex operator - (Complex c2)    //将运算符"-"重载为成员函数
	{
		return Complex(real - c2.real, imag - c2.imag);
	}
	void Display()    //结果输出函数
	{
		cout << real << "+" <<"("<< imag << "i"<< ")"<< endl;
	}
private:
	double real, imag;
};
int main()
{
	Complex c1(6, 7), c2(7);
	Complex c3, c4,c5, c6;    //用于存储运算结果
	c3 = c1 + c2;
	c4 = c1-c2;
	c5 = c2 + c1;
	c6 = c2 - c1;
	cout << "实验要求的四个复数计算结果如下:" << endl;
	c3.Display();
	c4.Display();
	c5.Display();
	c6.Display();	

}