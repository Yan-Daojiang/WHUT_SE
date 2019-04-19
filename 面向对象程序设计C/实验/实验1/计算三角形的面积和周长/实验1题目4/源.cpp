/*����һ��������Triangle��
��Triangle�����Ե�myPoint���3������p1��p2��p3��Ϊ���ݳ�Ա����ʾ�����ε��������㡣
Triangle����м��������ε��ܳ�������Ĺ��ܡ�*/
#include<iostream>
using namespace std;
class Tringle;     //����Tringle��
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
		//���������������	
		p1.SetPoint(x1, y1);
		p2.SetPoint(x2, y2);
		p3.SetPoint(x3, y3);
	}
	//��������ε���������
	void print()
	{
		cout << "�����ε��������������ֱ�Ϊ" << endl;
		p1.Printit();
		p2.Printit();
		p3.Printit();
	}

	//����������ļ���
	double area()
	{
		//���������ε����߳�
		double a, b, c;
		a = p1.GetLength(p2);    //����������֮��ľ��뼴Ϊ�����εı߳�
		b = p2.GetLength(p3);
		c = p3.GetLength(p1);
		double p = (a + b + c) / 2;
		return sqrt(p*(p - a)*(p - b)*(p - c));    //���ú��׹�ʽ���������ε����
	}
	//�������ܳ��ļ���
	double primeter()
	{
		double a, b, c;
		a = p1.GetLength(p2);
		b = p2.GetLength(p3);
		c = p3.GetLength(p1);
		double p = (a + b + c) / 2;
		return a + b + c;    //���������ε��ܳ�
	}
private:
	myPoint p1, p2, p3;
};
int main()
{
	Tringle trin(0, 0, 0, 3, 4, 0);    //����һ��������ʵ��
	trin.print();    //��������ε���������
	cout << "\n" << "�����ε����Ϊ" << trin.area() << endl;    //��������ε����
	cout << "�����ε��ܳ�Ϊ" << trin.primeter() << endl;    //��������ε��ܳ�
}

