//������·���滮����
#include<iostream>
using namespace std;
int slove(int m, int n)
{
	int dp[10][10];    //dp���鱣�浽��(0,0)��(m,n)��·��������
	int i, j;
	dp[0][0] = 0;
	for (i = 0; i < m; i++)
		dp[i][0] = 1;
	for (j = 0; j < n; j++)
		dp[0][j] = 1;
	for(i=1;i<m;i++)
		for (j=1; j < n; j++)
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
	return dp[m-1][n-1] ;
}
int main()
{
	int m, n;
	cin >> m >> n;
	cout<<slove(m, n)<<endl;
	system("pause");
	return 0;
}