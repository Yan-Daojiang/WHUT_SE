/************************************************************
����һ��student��,����ѧ������,�Ա�,ѧ��,���伸��˽�г�Ա����
�������������ڳ�ʼ��ѧ��������ѧ�š��Ա������Ĺ��캯��.һ��
��Ĭ�ϲ����Ĺ��캯�����ڶ����Ǵ�Ĭ�ϲ����Ĺ��캯������������
������Ĭ�ϲ����Ĺ��캯�������⻹��һ���������ѧ����Ϣ�ĺ�����
��дһ��������,������ͬ����ѧ������,�������
************************************************************/
#include<iostream>
using namespace std;
#include<string>
//����һ��ѧ����
class Student
{
private:
	string name;
	string num;
	int sex;    //0��ʾ������1��ʾŮ��
	int age;
public:
	Student(string sname, string snum, int ssex, int sage)    //��Ĭ�ϲ����Ĺ��캯��
	{
		name = sname;
		num = snum;
		sex = ssex;
		age = sage;
	}
	Student( string snum = "20180102", int ssex = 1, int sage = 20, string sname = "Lisi")    //��Ĭ�ϲ����Ĺ��캯��
	{
		name = sname;
		num = snum;
		sex = ssex;
		age = sage;
	}
	Student(int ssex, string sname="Wangwu", string snum = "20180103", int sage = 22)    //������Ĭ�ϲ����Ĺ��캯��
		/*�������ж��Ĭ�ϲ������������������ж���*/
	{
		name = sname;
		num = snum;
		sex = ssex;
		age = sage;
	}
	void print()    //���ѧ����Ϣ����
	{
		cout << name << "\t" << num << "\t" << sex << "\t" << age << "\t" << endl;
	}
};
int main()
{
	Student stu1("Zhang", "20180101", 1, 20);    //�����ĸ�����
	Student stu2;    //ȫ������Ĭ�ϲ���
	Student stu3(0);    //���ò���Ĭ�ϲ���
	cout << "ѧ����Ϣ���£�����Ϊ������ѧ�ţ��Ա����䣨1��ʾ�У�2��ʾŮ��" << endl;
	stu1.print();
	stu2.print();
	stu3.print();
}