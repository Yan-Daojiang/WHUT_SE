/*用面向对象的概念编程求两个长方形的面积和周长*/
#include<iostream>
using namespace std;

//类的定义
class Rectangle
{
public:
	Rectangle(float x,float y)    //带默认参数的构造函数
	{
		a = x;
		b = y;
	}
	
	float area()
	{
		return a*b;    //计算矩形的面积		
	}
	float primeter()
	{
		return 2 * (a+b);
	}
private:
	float  a, b;
};
//主函数
int main()
{
	float area1, area2;
	float c1, c2;
	Rectangle rec1(10, 50), rec2(3.6, 4.5);    //将两个矩形实例化
	area1=rec1.area();
	c1 = rec1.primeter();
	c2 = rec2.primeter();
	area2 = rec2.area();
	/*对两个矩形的计算结果进行输出*/
	cout << "矩形1的面积为" << area1 << endl;    //矩形一
	cout << "矩形1的周长为" << c1 << endl;

	cout << "矩形2的面积为" << area2 << endl;    //矩形二
	cout << "矩形2的周长为" << c2 << endl;
}
