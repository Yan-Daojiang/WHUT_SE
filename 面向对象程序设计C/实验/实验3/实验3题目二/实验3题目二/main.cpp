/*���������+��-��ʵ�ָ����ļӼ���*/
#include<iostream>
using namespace std;
class Complex    //���帴����
{
public:
	Complex(double r = 0.0, double i = 0.0) {
		real = r; imag = i;
	}
	Complex operator + (Complex c2)    //�������"+"����Ϊ��Ա���� 
	{ 
		return Complex(real + c2.real, imag + c2.imag);
	}
	Complex operator - (Complex c2)    //�������"-"����Ϊ��Ա����
	{
		return Complex(real - c2.real, imag - c2.imag);
	}
	void Display()    //����������
	{
		cout << real << "+" <<"("<< imag << "i"<< ")"<< endl;
	}
private:
	double real, imag;
};
int main()
{
	Complex c1(6, 7), c2(7);
	Complex c3, c4,c5, c6;    //���ڴ洢������
	c3 = c1 + c2;
	c4 = c1-c2;
	c5 = c2 + c1;
	c6 = c2 - c1;
	cout << "ʵ��Ҫ����ĸ���������������:" << endl;
	c3.Display();
	c4.Display();
	c5.Display();
	c6.Display();	

}