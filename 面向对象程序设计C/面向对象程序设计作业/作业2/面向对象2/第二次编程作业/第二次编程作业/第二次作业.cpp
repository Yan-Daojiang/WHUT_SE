/************************************************************
建立一个student类,类中学生姓名,性别,学号,年龄几个私有成员变量
类中有三个用于初始化学生姓名、学号、性别和年龄的构造函数.一个
无默认参数的构造函数，第二个是带默认参数的构造函数，第三个是
带部分默认参数的构造函数。另外还有一个用于输出学生信息的函数。
编写一个主函数,声明不同三个学生对象,进行输出
************************************************************/
#include<iostream>
using namespace std;
#include<string>
//定义一个学生类
class Student
{
private:
	string name;
	string num;
	int sex;    //0表示男生，1表示女生
	int age;
public:
	Student(string sname, string snum, int ssex, int sage)    //无默认参数的构造函数
	{
		name = sname;
		num = snum;
		sex = ssex;
		age = sage;
	}
	Student( string snum = "20180102", int ssex = 1, int sage = 20, string sname = "Lisi")    //带默认参数的构造函数
	{
		name = sname;
		num = snum;
		sex = ssex;
		age = sage;
	}
	Student(int ssex, string sname="Wangwu", string snum = "20180103", int sage = 22)    //带部分默认参数的构造函数
		/*函数中有多个默认参数，从右向左诸葛进行定义*/
	{
		name = sname;
		num = snum;
		sex = ssex;
		age = sage;
	}
	void print()    //输出学生信息函数
	{
		cout << name << "\t" << num << "\t" << sex << "\t" << age << "\t" << endl;
	}
};
int main()
{
	Student stu1("Zhang", "20180101", 1, 20);    //传递四个参数
	Student stu2;    //全部采用默认参数
	Student stu3(0);    //采用部分默认参数
	cout << "学生信息如下：依次为姓名，学号，性别，年龄（1表示男，2表示女）" << endl;
	stu1.print();
	stu2.print();
	stu3.print();
}