#include<iostream>
using namespace std;
//�ж�һ����������ɵ������Ƿ񹹳������ 
void judge_two(int a[],int i,int j,int &count)
{
	if (i<j&&a[i]>a[j])
		count++;
}
//��һ�����в��ΪΪ����Ԫ�ص�����Խ����ж�
int judge(int a[],int n)
{
	int i =0, j = 0, count = 0;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			judge_two(a, i, j, count);
	return count;
}
int main()
{
	//input
	int n, count = 0, a[100];
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	//output
	cout << judge(a, n)<<endl;

	//system("pause");
	return 0;
}