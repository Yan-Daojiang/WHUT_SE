#include<iostream>
#include<cstring>
#include<stdlib.h>
using namespace std;
class EditString;
//����String�ദ���ַ��������ü���������
class String {
public :
	String(char *s) {
		str = new char[strlen(s) + 1];
		strcpy(str, s);
	}
	void SetString();	
private:
	char *str;
};
class EditString:public String {
public :
	EditString(char *s,int i) :String(s) {
		str = new char[strlen(s) + 2];
		strcpy(str, s);
		n = i;
		curror = 0;    //��ʼ������λ��
	}
	void SetString();    //�����ַ����ĳ��Ȳ���������
	void Delete();    //ɾ����괦���ַ���
	void replace(char c);    //�Թ�괦�����ݽ����滻
	void add(char c);    //�Թ�괦���ַ������в���
private:
	char Char;
	int curror, n;
	char *str;
};
void String::SetString()
{
	cout << "ԭ�ַ����ĳ���Ϊ��" << strlen(str) << endl;
	cout <<"ԭ�ַ���������"<< str << endl;
}
void EditString::SetString()
{
	cout << "������ƣ�" << n << endl;
	str[curror + n];
}
void EditString:: replace(char c)
{
	cout << "�滻��ĸ:" << c << "" << endl;
	str[n + curror] = c;
	cout << "�滻�������ַ���Ϊ��" << str <<endl;
}
void EditString::add(char c)
{
	{
		cout << "������ĸ:" << c << "" << endl;
		int max = strlen(str) + 1;
		max++;
		char *temp = new char[max];
		strcpy(temp, str);
		str = new char[max];
		strcpy(str, temp);
	    int j;
		for (j = curror+n; j<max - 1; j++)
		{
			str[j + 1] = temp[j];
		}
		str[curror+n] = c;
		delete[]temp;
		cout << "����֮����ַ���Ϊ:" << str << endl;
	}
}
void EditString::Delete()
{
	int i ;
	for (i = n + curror; i < strlen(str); i++)
		str[i] = str[i + 1];
	cout<<"ɾ����괦���ַ���Ϊ��" << str << endl;
}
int main()
{
	EditString n1("abcdefghijk", 3);
	n1.String::SetString();    //��ԭ�ַ����ĳ��ȼ����ݽ������
	n1.SetString();    //��������λ��
	n1.Delete();    //ɾ����괦���ַ�
	n1.replace('K');    //��K�滻��괦���ַ�
	n1.add('W');    //�ڹ�괦����һ���ַ�W
}