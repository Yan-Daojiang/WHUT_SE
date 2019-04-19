/*************************ʵ��������̬�Ե�ʵ�֣�**************
********************ƽ��ͼ�����ܳ�������ͼ�������������������ܳ�*************************/
#include <iostream>
using namespace std;
#define Pi 3.14   //�궨��Pi��ֵ

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
		cout << "Բ���ܳ�Ϊ:" << perimeter() << "Բ�����Ϊ:" << area() << endl;
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
		cout << "���ε����:" << area() << "���ε��ܳ�:" << perimeter() << endl;
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
		cout << "�����ε����Ϊ:" << area() << "�����ε��ܳ�Ϊ:" << perimeter() << endl;
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
		cout << "������ĵ����Ϊ:" << area() << "������ĵ����ܳ�Ϊ:" << perimeter() << "����������Ϊ:" << volume() << endl;
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
		cout << "Բ���ĵ����:" << area() << "Բ���ĵ����ܳ�:" << perimeter() << "Բ�������" << volume() << endl;
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
		cout << "Բ׶�ĵ����:" << area() << "Բ׶�ĵ����ܳ�:" << perimeter() << "Բ׶�����:" << volume() << endl;
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
		cout << "�������ĵ����Ϊ:" << area() << "�������ĵ����ܳ�Ϊ:" << perimeter() <<"�����������Ϊ:"<<volume()<< endl;
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
		cout << "����׶�ĵ����Ϊ:" << area() << "����׶�ĵ����ܳ�Ϊ:" << perimeter() << "����׶�����Ϊ:" << volume() << endl;
	}
private:
	int a, b, c, h;
};

/*��������������*/
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
	cout << "ƽ��ͼ�Σ�" << endl;
	for (int i = 0; i<3; i++)
	{
		cout << "ͼ���ܳ���" << gs[i]->perimeter() << '\t';
		cout << "ͼ�������" << gs[i]->area() << '\t';
		cout << "ͼ�������" << gs[i]->volume() << endl;
	}
	cout << "����ͼ�Σ�" << endl;
	for (int i = 3; i<8; i++)
	{
		cout << "ͼ�ε��ܳ���" << gs[i]->perimeter() << '\t';
		cout << "ͼ�ε������" << gs[i]->area() << '\t';
		cout << "ͼ�����  ��" << gs[i]->volume() << endl;
	}
	return 0;
}
