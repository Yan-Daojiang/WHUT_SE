/*����Time������ΪDate�����Ԫ�࣬ͨ��Time���е�display��������Date������˽�����ݣ�����꣬�£��պ�ʱ���֣���*/
#include<iostream>
using namespace std;
class Time;  //����Time��Ķ����ں��棬�����Ҫ��������������
class Date  //����Date��
{
public:
	Date(int y = 2018, int m = 4, int d = 12) :year(y), month(m), day(d) {}
	friend class Time;    //��Time������ΪDate�����Ԫ��
private:
	int year, month, day;
};

//ʵ����Ԫ��Time
class Time
{
public:
	//ʹ�ó�ʼ���б���г�ʼ��
	Time(int h = 19, int min = 19, int s = 59) :hour(h), minute(min), second(s) {}
	void display(Date &d1,Time &t1)     //��Date���е�˽�����ݳ�Ա���з���
	{
		cout << d1.year <<"."<<d1.month<<"."<<d1.day<<" "<<t1.hour<<":"<<t1.minute<<":"<<t1.second<< endl;
	}
private:
	int hour, minute, second;
};
int main()
{
	Date d1;
	Time t1;
	t1.display( d1,t1);
}
