#include<iostream>
#include<algorithm>
using namespace std;
//�������
int slove(int n, int k, int a[])
{
	//̰�Ĳ���Ϊ�ñ���������ҿ�ʼ���и���
	sort(a, a + n);    //������������

	int mark = a[0];
	int count = 1;

	for (int i = 1; i < n; i++)
	{
		if (a[i] > mark + k)
		{
			mark = a[i];
			count++;
		}
	}
	return count;
}
int main()
{
	int n, k;   
	cin >> n >> k;
	int* a = new int[n];	
	for (int i = 0; i < n; i++)
		cin >> a[i];
	
	cout<<slove(n, k, a)<<endl;

	system("pause");
	return 0;
}