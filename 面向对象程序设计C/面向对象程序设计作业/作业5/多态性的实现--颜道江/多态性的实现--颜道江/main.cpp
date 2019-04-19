/**************************************��̼��������塢Բ�������ı�����������
Ҫ������һ�������Ļ���Body��������Ϊ�����࣬�ڸ����ж���������������Ĵ��麯����
�������ж���һ�����ݳ�Աdata����������Ϊ��İ뾶��������ı߳���Բ�������Բ�İ뾶��
������������������������������Բ����3�������࣬����3�����ж��м�������������ĺ����ľ���ʵ�֡�*/
#include<iostream>
using namespace std;
#define Pi 3.14    //�궨��е�ֵ
class Ball;    //�����������
class Cube;
class Cylinder;
class Body {
public:
	virtual void surface_area() = 0;    //��������㺯��
	virtual void volume() = 0;    //������㺯��
protected:
	double data;
};
class Ball :public Body {
public:
	Ball(double r){
		data = r;    //��������İ뾶 
	}
	void surface_area() {
		cout <<"�뾶Ϊ"<<data<<"��"<< "��ı����Ϊ:" << 4 * Pi*data*data << endl;    //��������
	}
	void volume() {
		cout << "�뾶Ϊ" << data << "��" << "��������Ϊ:" << 4 * Pi*data*data*data / 3 << endl;    //�������
	}
};
class Cube : public Body {
public:
	Cube(double a) {
		data = a;    //������������ⳤ
	}
	void surface_area() {
		cout << "�ⳤΪ" << data << "��" << "������ı����Ϊ:" << 6*data*data << endl;
	}
	void volume() {
		cout << "�ⳤΪ" << data << "��" << "����������Ϊ:" << data*data*data << endl;
	}
};
class Cylinder :public Body {
public:
	Cylinder(double r, double h) {
		data = r;    //����Բ����ĵ���뾶
		height = h;    //����Բ����ĸ�
	}
	void surface_area() {
		cout <<"����뾶Ϊ"<<data<<",��Ϊ"<<height<<"��"<< "Բ����ı����Ϊ:" << 2 * Pi*data*data + 2 * Pi*data*height << endl;
	}
	void volume() {
		cout << "����뾶Ϊ" << data <<",��Ϊ" << height << "��" << "Բ��������Ϊ:" << Pi*data*data*height << endl;
	}
private:
	double height;
};
//����������
int main() {
	int i = 0;
	Body *p[3];
	Ball b(5);
	Cube c(5);
	Cylinder cy(5, 8);
	p[0] = &b;
	p[1] = &c;
	p[2] = &cy;
	//ѭ���������������ı���������
	for (i = 0; i < 3; i++) {
		p[i]->surface_area();
		p[i]->volume();
	}
	return 0;
}
