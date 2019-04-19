#include<iostream>
#include<math.h>
using namespace std;
class Rectangle;
class Circle;

 class Point{
public:
	Point() { x = 0; y = 0; }
	Point(double xv,double yv) { x = xv; y = yv; }
	Point(Point& pt) { x = pt.x;  y = pt.y; }
	double getx() { return x; }
	double gety() { return y; }
	double Area() { return 0; }
	void Show() { cout << "x=" << x << ' ' << "y=" << y << endl; }
private:
	double x,y;
};
 //Rectangle�Թ��еķ�ʽ�̳�Point��
 class Rectangle :public Point {
 public:
	 Rectangle(double x, double y, double a, double b) :Point(x, y)
	 {length = a; width = b;}
	 void position(Point &pt) {
		 pt.Show();
		
		 if (pt.getx()>8||pt.getx()<5|| pt.gety()>5|| pt.gety()<1)
			 cout << "������ھ��ε��ⲿ" << endl;
		 else if(pt.getx()==5|| pt.getx()==8&& pt.gety()<=5&&pt.gety()>=1)
			 cout << "������ھ�����" << endl;
		 else if ((pt.gety() == 1 || pt.gety() == 5) && pt.getx() <= 8 && pt.getx() >= 1)
			 cout<<  "������ھ�����" << endl;
		 else
			 cout << "������ھ����ڲ�" << endl;
	 }
 private :
	 double length, width;
 };
//Circle���Թ��еķ�ʽ�̳�Point��
 class Circle : public Point {
 public:	 
	 Circle(double x0, double y0, double r):Point(x0,y0)
	 { radius = r;}
	 void position(Point &pt) {
		 double l; 
		 l = sqrt((pt.getx() - getx())*(pt.getx() - gety() ) + (pt.gety() - gety())*(pt.gety() -gety()));
		 pt.Show();
		 if (l > radius)
			 cout << "�������Բ������" << endl;
		 else if (l == radius)
			 cout << "�������Բ��" << endl;
		 else
			 cout << "�������Բ���ڲ�" << endl;
	 }
 private: 
	 double radius;
 };

 int main()
 {
	 Circle c1(5, 5, 3);
	 Rectangle r1(5,5,3,4);
	 Point p1(5,5);
	 Point p2(4,2);
	 Point p3(5, 11); 
	 Point p4(6, 2);
	 c1.position(p1);
	 c1.position(p2);
	 c1.position(p3);
	 r1.position(p1);
	 r1.position(p3);
	 r1.position(p4);
 }
