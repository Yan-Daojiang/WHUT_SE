/*创建一个student类，包含姓名成绩，设计友元函数输出等级*/
#include<iostream>
#include<string>
using namespace std;
class Student
{
public:
	Student(string sname,float sgrades)
	{
		name = sname;
		grades = sgrades;
	}
	friend void printf(Student &stu);    //声明友元函数
private:
	string name;    //将类的数据成员设为私自有
	float grades;
};

void printf(Student &stu)    //定义友元函数，通过类的友元函数访问该类的所有数据成员
//友元函数的入口参数一般是对象名或者对象指针
{
	if (stu.grades >=90)
	    cout << stu.name << "\t\t"<<stu.grades << "\t" << "优" << endl;
	if (stu.grades>=80&&stu.grades<90)
		cout << stu.name << "\t\t" << stu.grades << "\t" << "良" << endl;
	if (stu.grades>=70&&stu.grades<80)
		cout << stu.name << "\t\t" << stu.grades << "\t" << "中" << endl;
	if (stu.grades>=60&&stu.grades<70)
		cout << stu.name << "\t\t" << stu.grades << "\t" << "合格" << endl;
	if (stu.grades<60)
		cout << stu.name << "\t\t" << stu.grades << "\t" << "不合格" << endl;		
}

int main()
{
	cout << "姓名\t" << "\t\t" << "分数" << "\t" << "等级"<<endl;
	//定义各个对象，调用友元函数，输出学生的成绩信息
	Student stu1("student1",95);
	printf(stu1);
	Student stu2("student2",81);
	printf(stu2);
	Student stu3("student3", 77);
	printf(stu3);
	Student stu4("student4", 68);
	printf(stu4);
	Student stu5("student5", 55);
	printf(stu5);

}