#include<iostream>
using namespace std;
#define MAXN 50
int dp[MAXN][MAXN];		//��̬�滮����
int Split(int n,int k)		//����㷨
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= k; j++)
		{
			if (i == 1 || j == 1)
				dp[i][j] = 1;
			else if (i < j)
				dp[i][j] = dp[i][i];
			else if (i == j)
				dp[i][j] = dp[i][j - 1] + 1;
			else
				dp[i][j] = dp[i][j - 1] + dp[i - j][j];
		}
	return dp[n][k];
}
int main()
{
	cout << Split(5,5) << endl;
	system("pause");
	return 0;
}