/*����һ��student�࣬���������ɼ��������Ԫ��������ȼ�*/
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
	friend void printf(Student &stu);    //������Ԫ����
private:
	string name;    //��������ݳ�Ա��Ϊ˽����
	float grades;
};

void printf(Student &stu)    //������Ԫ������ͨ�������Ԫ�������ʸ�����������ݳ�Ա
//��Ԫ��������ڲ���һ���Ƕ��������߶���ָ��
{
	if (stu.grades >=90)
	    cout << stu.name << "\t\t"<<stu.grades << "\t" << "��" << endl;
	if (stu.grades>=80&&stu.grades<90)
		cout << stu.name << "\t\t" << stu.grades << "\t" << "��" << endl;
	if (stu.grades>=70&&stu.grades<80)
		cout << stu.name << "\t\t" << stu.grades << "\t" << "��" << endl;
	if (stu.grades>=60&&stu.grades<70)
		cout << stu.name << "\t\t" << stu.grades << "\t" << "�ϸ�" << endl;
	if (stu.grades<60)
		cout << stu.name << "\t\t" << stu.grades << "\t" << "���ϸ�" << endl;		
}

int main()
{
	cout << "����\t" << "\t\t" << "����" << "\t" << "�ȼ�"<<endl;
	//����������󣬵�����Ԫ���������ѧ���ĳɼ���Ϣ
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