#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
using namespace std;
//���������ȳ��������е���λ��
int slove(int a[], int b[], int lowa, int higha, int lowb, int highb)
{
	//������ֻ��һ��Ԫ��ʱ���ؽ�С��Ԫ��
	if (lowa == higha && lowb == highb)
		return a[lowa] < b[lowb] ? a[lowa] : b[lowb];
	else
	{
		int mida, midb;
		mida = (lowa + higha) / 2;
		midb = (lowb + highb) / 2;
		
		//�������е���λ�����ʱֱ�ӷ��������Ϊ��λ��
		if (a[mida] == b[midb])
			return a[mida];

		//�ֽ��������
		else if (a[mida] > b[midb])
		{
			if ((lowb + highb) % 2 == 0)
				return slove(a, b, lowa, mida, midb, highb);
			else
				return slove(a, b, lowa, mida, midb + 1, highb);
		}

		else if (a[mida] < b[midb])
		{
			if ((lowa + higha) % 2 == 0)
				return slove(a, b, mida, higha, lowb, midb);
			else
				return slove(a, b, mida + 1, higha, lowb, midb);
		}
	}
}

int main()
{
	//�ļ��ض�������
	freopen("D://Algorithm//Exercise//data//ex1//input.txt","r",stdin);
	freopen("D://Algorithm//Exercise//data//ex1//output.txt", "w", stdout);
	
	int n, a[300], b[300];

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];

	//output
	cout << slove(a, b, 0, n - 1, 0, n - 1)<<endl;
	
	fclose(stdin);
	fclose(stdout);

	//system("pause");
	return 0;
}