/*���������ĸ����������������ε�������ܳ�*/
#include<iostream>
using namespace std;

//��Ķ���
class Rectangle
{
public:
	Rectangle(float x,float y)    //��Ĭ�ϲ����Ĺ��캯��
	{
		a = x;
		b = y;
	}
	
	float area()
	{
		return a*b;    //������ε����		
	}
	float primeter()
	{
		return 2 * (a+b);
	}
private:
	float  a, b;
};
//������
int main()
{
	float area1, area2;
	float c1, c2;
	Rectangle rec1(10, 50), rec2(3.6, 4.5);    //����������ʵ����
	area1=rec1.area();
	c1 = rec1.primeter();
	c2 = rec2.primeter();
	area2 = rec2.area();
	/*���������εļ������������*/
	cout << "����1�����Ϊ" << area1 << endl;    //����һ
	cout << "����1���ܳ�Ϊ" << c1 << endl;

	cout << "����2�����Ϊ" << area2 << endl;    //���ζ�
	cout << "����2���ܳ�Ϊ" << c2 << endl;
}
