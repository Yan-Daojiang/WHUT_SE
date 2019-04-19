#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;
int save();    //分别声明保存，输出及查找函数
int out();
int find_std();
//定义学生信息结构体
struct Student 
{
	char num[8];    //保存学号
	char name[8];    //保存学生姓名
	float score;    //保存学生的分数
};
int main() {
	int choice, n;
	do {
		//菜单选项
		cout << "选择(1:输入数据 2:输出数据 3:按姓名查找数据 其他退出):";
		cin >> choice;
		switch (choice) {
		case 1: {
			save();    //保存学生信息到文件中
			break;
		}
		case 2: {
			out();    //将文件中的信息输出到屏幕上
			break;
		}
		case 3: {
			find_std();    //查找符合某一条件的同学
			break;
		}
		default:
			break;
		}	
	}while (choice != 0);
}

//定义保存学生信息函数
int save() {
	int n;    //通过n接受学生信息数量
	cout << "学生人数:";
	cin >> n;

	Student *stu;
	//开辟一个结构体数组保存学生的信息
	stu = new Student[n];
	for (int i = 0; i < n; i++) 
	{
		//将学生的信息保存到数组当中
		cout << "第" << i+1 << "个学生(学号 姓名 成绩) :";
		cin >> stu[i].num;
		cin >> stu[i].name;
		cin >> stu[i].score;
	}

	//打开文件
	fstream books;
	books.open("stud.dat", ios::out | ios::binary);
	if (!books)
	{
		cout << "Open file error" << endl;    //如果打开文件失败就返回
		return 1;
	}

	//将数组的信息保存到文件中
	books.write((char*)&n, sizeof(n));
	for (int i = 0; i<n; i++) 
	{
		books.write((char*)&stu[i], sizeof(stu[i]));
	}
	books.close();
}

//定义输出学生信息函数
int out(){
	int count;    //存储学生信息数
	Student temp;
	fstream books;

	books.open("stud.dat", ios::in | ios::binary);    //打开文件
	if (!books)
	{
		cout << "Cannot not open file!" << endl;    //如果文件打开失败就返回
		return 1;
	}

	//从文件中获取保存了多少个学生的信息
	books.read((char*)&count, sizeof(count));
	//将学生的信息从文件中取出
	cout << "学号\t姓名\t成绩" << endl;
	for (int i = 0; i<count; i++)
	{
		books.read((char*)&temp, sizeof(temp));
		cout << temp.num << "\t" << temp.name << "\t" << temp.score << endl;
	}
	books.close();
	return 0;
} 

//从文件中查找某个学生或者某些学生的相关信息
int find_std() {
	int count;
	Student *stu;
	char name[8];    //保存想要查询的人的姓名或者姓名的一部分
	cout << "输入姓名:";
	cin >> name;
	fstream books;
	books.open("stud.dat", ios::in | ios::binary);    //打开文件
	if (!books) 
	{
		cout << "Cannot not open file!" << endl;    //如果文件打开失败就返回
		return 1;
	}
	//从文件中获取保存了多少个学生的信息
	books.read((char*)&count, sizeof(count));
	stu= new Student[count];    //开辟一个新的数组保存从文件中取出的学生信息，，通过学生的人数确定新数组的长度

	//通过循环对新数组中的元素赋值
	cout << "学号\t姓名\t成绩" << endl;
	for (int i = 0; i < count; i++) {
		books.read((char*)&stu[i], sizeof(stu[i]));

		//如果要查找的人的名字刚好其中就直接这个同学
		if (strcmp(name, stu[i].name) == 0)
			cout << stu[i].num << "\t"<<stu[i].name<<"\t"<<stu[i].score<<endl;
		else

		//如果只有姓名的一部分重合，就根据姓名再次进行比较
		for (int j = 0; j < 3; j++) 
		{
			if (name[j] == stu[i].name[j])
				cout << stu[i].num << "\t" << stu[i].name << "\t" << stu[i].score << endl;    //对姓名符合该条件的人进行输出
			break;    //如果已经确定符合条件就退出内循环
		}
	}

	//关闭文件
	books.close();	

	return 0;
}
