#include<iostream>
using namespace std;
int maxSubSum(int a[], int n)
{
	int i, max = 0, sum = 0;
	for (i = 0; i < n; i++)
	{
		sum += a[i];//�����ۼ�
		if (sum < 0) //����ǰ�����к�Ϊ���������¿�ʼ��һ������
			sum = 0;
		if (sum > max)//���ָ��������µ�ǰ���
			max = sum;
	}
	return max;
}
 
int main()
{
	int a[] = { 1,2,-1,8 };
	cout << maxSubSum(a, 4) << endl;
	system("pause");
	return 0;
}