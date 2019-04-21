#include<iostream>
#include <algorithm>
using namespace std;
#define MAX 50001
//�����ʾ
struct Cow								//��ţ����������
{
	int no;								//ţ���
	int b;								//��ʼʱ��
	int e;								//����ʱ��
	bool operator<(const Cow &s) const	//����<��ϵ����
	{
		if (e == s.e)						//����ʱ����ͬ����ʼʱ���������
			return b <= s.b;
		else							//���򰴽���ʱ���������
			return e <= s.e;
	}
};

Cow A[50001] ;	//�±�0����
//�������ʾ
int ans[MAX];								//ans[i]��ʾ��A[i].noͷţ���������
void solve(int nums)								//��������ݻ�Ӽ�
{
	int n = nums;
	
	//memset(ans, 0, sizeof(ans));				//��ʼ��Ϊ0	for (int i = 0; i <= MAX; i++)		ans[i] = 0;

	int num = 1;							//�������
	for (int i = 1; i <= n; i++)					//i��j��Ϊ�������±�
	{
		if (ans[i] == 0)					//��iͷţ��û�а�������
		{
			ans[i] = num;					//��iͷţ��������num
			int preend = A[i].e;				//ǰһ�����ݻ�Ľ���ʱ��
			for (int j = i + 1; j <= n; j++)		//����һ�������ݻ�Ӽ�
			{
				if (A[j].b > preend && ans[j] == 0)
				{
					ans[j] = num;			//�����ݻ�Ӽ��л������num������
					preend = A[j].e;		//���½���ʱ��
				}
			}
			num++;						//������һ�������ݻ�Ӽ�,num��1
		}
	}
}

int main()
{
	//Input
	int nums;
	cin >> nums;
	for (int i = 0; i <= nums; i++)
		if (i == 0)
			A[i].no = 0;
		else
		{
			A[i].no = i;
			cin >> A[i].b >> A[i].e;
		}

	//�������
	solve(nums);

	//Output
	int max = ans[1];
	for (int i = 2; i <= nums; i++)
		if (ans[i] > max)
			max = ans[i];
	cout << max<<endl;

	for (int i = 1; i <= nums; i++)
		cout<<ans[i]<<endl;

	system("pause");
	return 0;
}