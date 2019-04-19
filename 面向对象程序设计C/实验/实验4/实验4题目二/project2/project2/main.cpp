#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;
int save();    //�ֱ��������棬��������Һ���
int out();
int find_std();
//����ѧ����Ϣ�ṹ��
struct Student 
{
	char num[8];    //����ѧ��
	char name[8];    //����ѧ������
	float score;    //����ѧ���ķ���
};
int main() {
	int choice, n;
	do {
		//�˵�ѡ��
		cout << "ѡ��(1:�������� 2:������� 3:�������������� �����˳�):";
		cin >> choice;
		switch (choice) {
		case 1: {
			save();    //����ѧ����Ϣ���ļ���
			break;
		}
		case 2: {
			out();    //���ļ��е���Ϣ�������Ļ��
			break;
		}
		case 3: {
			find_std();    //���ҷ���ĳһ������ͬѧ
			break;
		}
		default:
			break;
		}	
	}while (choice != 0);
}

//���屣��ѧ����Ϣ����
int save() {
	int n;    //ͨ��n����ѧ����Ϣ����
	cout << "ѧ������:";
	cin >> n;

	Student *stu;
	//����һ���ṹ�����鱣��ѧ������Ϣ
	stu = new Student[n];
	for (int i = 0; i < n; i++) 
	{
		//��ѧ������Ϣ���浽���鵱��
		cout << "��" << i+1 << "��ѧ��(ѧ�� ���� �ɼ�) :";
		cin >> stu[i].num;
		cin >> stu[i].name;
		cin >> stu[i].score;
	}

	//���ļ�
	fstream books;
	books.open("stud.dat", ios::out | ios::binary);
	if (!books)
	{
		cout << "Open file error" << endl;    //������ļ�ʧ�ܾͷ���
		return 1;
	}

	//���������Ϣ���浽�ļ���
	books.write((char*)&n, sizeof(n));
	for (int i = 0; i<n; i++) 
	{
		books.write((char*)&stu[i], sizeof(stu[i]));
	}
	books.close();
}

//�������ѧ����Ϣ����
int out(){
	int count;    //�洢ѧ����Ϣ��
	Student temp;
	fstream books;

	books.open("stud.dat", ios::in | ios::binary);    //���ļ�
	if (!books)
	{
		cout << "Cannot not open file!" << endl;    //����ļ���ʧ�ܾͷ���
		return 1;
	}

	//���ļ��л�ȡ�����˶��ٸ�ѧ������Ϣ
	books.read((char*)&count, sizeof(count));
	//��ѧ������Ϣ���ļ���ȡ��
	cout << "ѧ��\t����\t�ɼ�" << endl;
	for (int i = 0; i<count; i++)
	{
		books.read((char*)&temp, sizeof(temp));
		cout << temp.num << "\t" << temp.name << "\t" << temp.score << endl;
	}
	books.close();
	return 0;
} 

//���ļ��в���ĳ��ѧ������ĳЩѧ���������Ϣ
int find_std() {
	int count;
	Student *stu;
	char name[8];    //������Ҫ��ѯ���˵���������������һ����
	cout << "��������:";
	cin >> name;
	fstream books;
	books.open("stud.dat", ios::in | ios::binary);    //���ļ�
	if (!books) 
	{
		cout << "Cannot not open file!" << endl;    //����ļ���ʧ�ܾͷ���
		return 1;
	}
	//���ļ��л�ȡ�����˶��ٸ�ѧ������Ϣ
	books.read((char*)&count, sizeof(count));
	stu= new Student[count];    //����һ���µ����鱣����ļ���ȡ����ѧ����Ϣ����ͨ��ѧ��������ȷ��������ĳ���

	//ͨ��ѭ�����������е�Ԫ�ظ�ֵ
	cout << "ѧ��\t����\t�ɼ�" << endl;
	for (int i = 0; i < count; i++) {
		books.read((char*)&stu[i], sizeof(stu[i]));

		//���Ҫ���ҵ��˵����ָպ����о�ֱ�����ͬѧ
		if (strcmp(name, stu[i].name) == 0)
			cout << stu[i].num << "\t"<<stu[i].name<<"\t"<<stu[i].score<<endl;
		else

		//���ֻ��������һ�����غϣ��͸��������ٴν��бȽ�
		for (int j = 0; j < 3; j++) 
		{
			if (name[j] == stu[i].name[j])
				cout << stu[i].num << "\t" << stu[i].name << "\t" << stu[i].score << endl;    //���������ϸ��������˽������
			break;    //����Ѿ�ȷ�������������˳���ѭ��
		}
	}

	//�ر��ļ�
	books.close();	

	return 0;
}
