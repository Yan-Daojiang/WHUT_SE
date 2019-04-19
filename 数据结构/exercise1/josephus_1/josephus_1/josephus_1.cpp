/***
** @author: Yan_Daojiang
** @date: 2018/10/11
**@description:编号为1，2，···，n的n个人围坐在一圆桌旁。
*从第一个人开始报数，报到一个预先约定的正整数m时，停止报数，报m的人退席，
*下一个人又重新从1开始报数，依此重复，直至所有的人都退席。
*编一程序输出他们退席的编号序列
**测试数据： m=20，n=7，退席的人的编号依次为6，1，7，5，3，2，4
***/
#include<iostream>
using namespace std;
void josephus(int p[], int m, int n) {
	int i, j, t;
	for (i = 0; i <= n - 1; i++)
		p[i] = i + 1;
	t = 0;
	cout << "退席次序:" << endl;
	for (i = n; i >= 1; i--) {
		t = (t + m - 1) % i;
		cout << p[t] << " ";
		for (j = t + 1; j <= i - 1; j++)
			p[j - 1] = p[j];
	}
	cout << endl;
}
int main() {
	int m, n,p[100];
	cout<<"请输入人数n和预先约定数m"<<endl;
	cin >> m >> n;
	josephus(p, n, m);
}