/***
** @author: Yan_Daojiang
** @date: 2018/10/11
**@description:���Ϊ1��2����������n��n����Χ����һԲ���ԡ�
*�ӵ�һ���˿�ʼ����������һ��Ԥ��Լ����������mʱ��ֹͣ��������m������ϯ��
*��һ���������´�1��ʼ�����������ظ���ֱ�����е��˶���ϯ��
*��һ�������������ϯ�ı������
**�������ݣ� m=20��n=7����ϯ���˵ı������Ϊ6��1��7��5��3��2��4
***/
#include<iostream>
using namespace std;
void josephus(int p[], int m, int n) {
	int i, j, t;
	for (i = 0; i <= n - 1; i++)
		p[i] = i + 1;
	t = 0;
	cout << "��ϯ����:" << endl;
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
	cout<<"����������n��Ԥ��Լ����m"<<endl;
	cin >> m >> n;
	josephus(p, n, m);
}