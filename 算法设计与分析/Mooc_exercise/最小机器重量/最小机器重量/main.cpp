#include<iostream>
using namespace std;
//�����ʾ
int w[100][100];//w[i][j]Ϊ��i������ڵ�j����Ӧ�̵�����
int c[100][100];//c[i][j]Ϊ��i������ڵ�j����Ӧ�̵ļ۸�
int bestx[100];//bestx[i]��ʾһ���������׺�����Ž⣬������ŵ�i������Ĺ�Ӧ�̣�
int x[100];//x[i]��ʱ��ŵ�i������Ĺ�Ӧ��
int cw = 0, cc = 0, bestw = 10000;
int cost;//�޶��۸�
int n;//������
int m;//��Ӧ����

//���ݷ����
void Backtrack(int t)
{
	int j;
	if (t > n)
	{
		bestw = cw;
		for (j = 1; j <= n; j++)
			bestx[j] = x[j];
	}
	else
	{
		for (j = 1; j <= m; j++)
		{
			if (cc + c[t][j] <= cost && cw + w[t][j] < bestw)
			{
				x[t] = j;
				cc += c[t][j];
				cw += w[t][j];
				Backtrack(t + 1);
				cc -= c[t][j];
				cw -= w[t][j];
			}
		}
	}
}
//�������������
int main()
{
	int i, j;
	cin >> n;
	cin >> m;
	cin >> cost;
	
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
			cin >> w[i][j];
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
			cin >> c[i][j];

	Backtrack(1);

	for (i = 1; i < n; i++)
		cout << bestx[i] << ' ';
	cout << bestx[n];	//��Ŀ��Ҫ���������һ�е�������пո�
	cout << endl;
	cout << bestw<<endl;
	//system("pause");
	return 0;
}
