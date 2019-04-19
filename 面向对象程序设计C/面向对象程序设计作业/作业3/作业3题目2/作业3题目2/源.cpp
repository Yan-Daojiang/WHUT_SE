/*定义Time类声明为Date类的友元类，通过Time类中的display函数引用Date类对象的私有数据，输出年，月，日和时，分，秒*/
#include<iostream>
using namespace std;
class Time;  //由于Time类的定义在后面，因此需要进行引用性声明
class Date  //定义Date类
{
public:
	Date(int y = 2018, int m = 4, int d = 12) :year(y), month(m), day(d) {}
	friend class Time;    //将Time类声明为Date类的友元类
private:
	int year, month, day;
};

//实现友元类Time
class Time
{
public:
	//使用初始换列表进行初始化
	Time(int h = 19, int min = 19, int s = 59) :hour(h), minute(min), second(s) {}
	void display(Date &d1,Time &t1)     //对Date类中的私有数据成员进行访问
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
