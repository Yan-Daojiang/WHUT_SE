/*定义一个三角形Triangle类
在Triangle类中以点myPoint类的3个对象p1、p2、p3作为数据成员，表示三角形的三个顶点。
Triangle类具有计算三角形的周长和面积的功能。*/
#include<iostream>
using namespace std;
class Tringle;     //声明Tringle类
class myPoint {
public:
	myPoint(double x0 = 0.0, double y0 = 0.0) :x(x0), y(y0) {}
	myPoint(myPoint &np) :x(np.x), y(np.y) {}
	double GetX() { return x; }
	double GetY() { return y; }
	void SetX(double x0) { x = x0; }
	void SetY(double y0) { x = y0; }
	void SetPoint(double x0, double y0) { x = x0; y = y0; }
	void SetPoint(myPoint &np) { x = np.x; y = np.y; }
	double  GetLength(myPoint p) {
		return sqrt((x - p.x)*(x - p.x) + (y - p.y)*(y - p.y));
	}
	void Printit() { cout << " (" << x << "," << y << ") "; }
private:
	double x, y;
};
class Tringle
{
public:
	Tringle(double x1, double y1, double x2, double y2, double x3, double y3) {
		//设置三个点的坐标	
		p1.SetPoint(x1, y1);
		p2.SetPoint(x2, y2);
		p3.SetPoint(x3, y3);
	}
	//输出三角形的三个坐标
	void print()
	{
		cout << "三角形的三个定点的坐标分别为" << endl;
		p1.Printit();
		p2.Printit();
		p3.Printit();
	}

	//三角形面积的计算
	double area()
	{
		//计算三角形的三边长
		double a, b, c;
		a = p1.GetLength(p2);    //计算两个点之间的距离即为三角形的边长
		b = p2.GetLength(p3);
		c = p3.GetLength(p1);
		double p = (a + b + c) / 2;
		return sqrt(p*(p - a)*(p - b)*(p - c));    //利用海伦公式计算三角形的面积
	}
	//三角形周长的计算
	double primeter()
	{
		double a, b, c;
		a = p1.GetLength(p2);
		b = p2.GetLength(p3);
		c = p3.GetLength(p1);
		double p = (a + b + c) / 2;
		return a + b + c;    //计算三角形的周长
	}
private:
	myPoint p1, p2, p3;
};
int main()
{
	Tringle trin(0, 0, 0, 3, 4, 0);    //定义一个三角形实例
	trin.print();    //输出三角形的三个坐标
	cout << "\n" << "三角形的面积为" << trin.area() << endl;    //输出三角形的面积
	cout << "三角形的周长为" << trin.primeter() << endl;    //输出三角形的周长
}

