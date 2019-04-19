#include<iostream>
#include<cstring>
#include<stdlib.h>
using namespace std;
class EditString;
//设置String类处理字符串的设置及长度问题
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
		curror = 0;    //初始换光标的位置
	}
	void SetString();    //处理字符串的长度并返回内容
	void Delete();    //删除光标处的字符串
	void replace(char c);    //对光标处的内容进行替换
	void add(char c);    //对光标处的字符串进行插入
private:
	char Char;
	int curror, n;
	char *str;
};
void String::SetString()
{
	cout << "原字符串的长度为：" << strlen(str) << endl;
	cout <<"原字符串的内容"<< str << endl;
}
void EditString::SetString()
{
	cout << "光标右移：" << n << endl;
	str[curror + n];
}
void EditString:: replace(char c)
{
	cout << "替换字母:" << c << "" << endl;
	str[n + curror] = c;
	cout << "替换光标出的字符后为：" << str <<endl;
}
void EditString::add(char c)
{
	{
		cout << "插入字母:" << c << "" << endl;
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
		cout << "插入之后的字符串为:" << str << endl;
	}
}
void EditString::Delete()
{
	int i ;
	for (i = n + curror; i < strlen(str); i++)
		str[i] = str[i + 1];
	cout<<"删除光标处的字符后为：" << str << endl;
}
int main()
{
	EditString n1("abcdefghijk", 3);
	n1.String::SetString();    //对原字符串的长度及内容进行输出
	n1.SetString();    //锁定贯标的位置
	n1.Delete();    //删除光标处的字符
	n1.replace('K');    //用K替换光标处的字符
	n1.add('W');    //在光标处插入一个字符W
}