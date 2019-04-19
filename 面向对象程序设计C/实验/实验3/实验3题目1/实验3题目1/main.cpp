/*************************实验三：多态性的实现：**************
********************平面图形求周长，立体图形求体积，及底面积和周长*************************/
#include <iostream>
using namespace std;
#define Pi 3.14   //宏定义Pi的值

class Geometric_shape {
public:
	virtual double area()=0;
	virtual double perimeter() = 0;
	virtual double volume() = 0;
	virtual void Show() = 0;
};
class Circle:public Geometric_shape{
public:
	Circle(int x) { r = x; }
    double area() {
		return Pi*r*r;
	}
    double perimeter() {
		return 2 * Pi*r;
	}
	double volume() { return 0; }
	void Show() {
		cout << "圆的周长为:" << perimeter() << "圆的面积为:" << area() << endl;
	}
private:
	int r;
};
class Rectangle:public Geometric_shape{
public:
	Rectangle(int x, int y) { a = x; b = y; }
	double area() {
		return a*b;
	}
	double perimeter() {
		return 2 * (a + b);
	}
	double volume() { return 0; }
	void Show() {
		cout << "矩形的面积:" << area() << "矩形的周长:" << perimeter() << endl;
	}
private:
	int a, b;
};
class Triangle:public Geometric_shape{
public:
	Triangle(int x,int y,int z ) { a = x, b = y, c = z; }
	double area() {
		return a*b / 2;
	}
	double perimeter() {
		return a + b + c; }
	double volume() { return 0;
	}
	void Show() {
		cout << "三角形的面积为:" << area() << "三角形的周长为:" << perimeter() << endl;
	}
private:
	int a, b, c;
};
class Box:public Geometric_shape {
public:
	Box(int x, int y, int z) { a = x, b = y, c = z; }
	double area() {
		return a*b;
	}
	double perimeter() { 
		return 2 * (a + b);
	}
	double volume() { 
		return a*b*c;
	}
	void Show() { 
		cout << "长方体的底面积为:" << area() << "长方体的底面周长为:" << perimeter() << "长方体的体积为:" << volume() << endl;
	}
private:
	int a, b, c;
};
class Cylinder:public Geometric_shape {
public:
	Cylinder(int x, int y) { r = x, h = y; };
	double area() {
		return Pi*r*r;
	}
	double perimeter() {
		return 2 * Pi*r;
	}
	double volume() {
		return Pi*r*r*h ; 
	}
	void Show() {
		cout << "圆柱的底面积:" << area() << "圆柱的地面周长:" << perimeter() << "圆柱的体积" << volume() << endl;
	}
private:
	double r, h;
};
class Cone :public Geometric_shape {
public:
	Cone(int x, int y) {
		r = x, h=y ;
	};
	double area() {
		return Pi*r*r;
	}
	double perimeter() {
		return 2 * Pi*r; 
	}
	double volume() {
		return Pi*r*r*h / 3; 
	}
	void Show() { 
		cout << "圆锥的底面积:" << area() << "圆锥的地面周长:" << perimeter() << "圆锥的体积:" << volume() << endl;
	}
private:
	int r, h;
};
class T_pyramid:public Geometric_shape {
public:
	T_pyramid(int x, int y, int z, int w) { a = x, b = y, c = z, h = w; }
	double area() {
		return a*b / 2;
	}
	double perimeter() { 
		return a + b + c;
	}
	double volume() { 
		return a*b*c*h/2;
	}
	void Show() {
		cout << "三棱柱的底面积为:" << area() << "三棱柱的底面周长为:" << perimeter() <<"三棱柱的体积为:"<<volume()<< endl;
	}
private:
	int a, b, c,h;
};
class T_prism:public Geometric_shape {
public:
	T_prism(int x, int y, int z, int w) { a = x, b = y, c = z, h = w; }
	double area() { 
		return a*b / 2; 
	}
	double perimeter() { 
		return a + b + c; 
	}
	double volume() { 
		return a*b*c*h / 6;
	}
	void Show() {
		cout << "三棱锥的底面积为:" << area() << "三棱锥的底面周长为:" << perimeter() << "三棱锥的体积为:" << volume() << endl;
	}
private:
	int a, b, c, h;
};

/*程序主函数部分*/
int main()
{
	Geometric_shape *gs[] = { new	Circle(10),
		new 	Rectangle(6,8),
		new		Triangle(3,4,5),
		new 	Box(6,8,3),
		new	 	Cylinder(10,3),
		new 	Cone(10,3),
		new		T_pyramid(3,4,5,3),
		new 	T_prism(3,4,5,3) };
	for (int i = 0; i<8; i++)
	{
		gs[i]->Show();
		cout << endl;
	}
	for (int i = 0; i<8; i++)
	{
		gs[i]->Show();
		cout << endl;
	}
	cout << "平面图形：" << endl;
	for (int i = 0; i<3; i++)
	{
		cout << "图形周长：" << gs[i]->perimeter() << '\t';
		cout << "图形面积：" << gs[i]->area() << '\t';
		cout << "图形体积：" << gs[i]->volume() << endl;
	}
	cout << "立体图形：" << endl;
	for (int i = 3; i<8; i++)
	{
		cout << "图形底周长：" << gs[i]->perimeter() << '\t';
		cout << "图形底面积：" << gs[i]->area() << '\t';
		cout << "图形体积  ：" << gs[i]->volume() << endl;
	}
	return 0;
}
