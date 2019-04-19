//
// Created by yan_daojiang on 18-11-6.
//

/***********************矩阵连乘问题******************/
/**********主要算法思想：递归******************/
#include <iostream>
using namespace std;
#define SIZE 100
#define INF 999999999

//利用递归计算一共有几种添加括号的方式
//参数n表示矩阵的数量，函数返回值为一共有多少种添加括号的方式
int Paren_Increa_Num(int n) {
    int count = 0;
    int k;
    //递归出口:只有一个矩阵的时添加括号方式为1
    if (n == 1)
        count = 1;
    else {
        for (k = 1; k <= n - 1; k++)
            count += Paren_Increa_Num(k)*Paren_Increa_Num(n - k);
    }
    return count;
}

//利用递归计算矩阵相乘所需要的最小的次数
//递归计算时穷举每种添加括号的方式
//第一个参数为矩阵的行列信息，后面两个参数为括号的位置
int Min_Mul(int m[], int left, int right)
{
    //递归出口：只有一个矩阵时计算次数为0
    if (left == right)
    {
        return 0;
    }

    int min = INF;//先将最小值初始化为一个很大的数
    int i;
    //在矩阵的后面依次添加括号
    for (i = left; i < right; i++)
    {
        //计算出这种完全加括号方式的计算次数
        int count = Min_Mul(m, left, i) + Min_Mul(m, i + 1, right);
        count += m[left - 1] * m[i] * m[right];
        //选出最小的
        if (count < min)
        {
            min = count;
        }
    }
    return min;
}


int main()
{
    int m[SIZE];//用一个长度足够的数组来保存连乘矩阵的相关的行数和列数
    int i, n;

    cout << "请输入矩阵的数量n:" << endl;
    cin >> n;

    //输入要进行计算的矩阵的行列
    for (i = 1; i <= n + 1; i++) {
        if (i == 1) {
            cout << "输入第一个矩阵的行数:";
            cin >> m[i - 1];
            continue;
        }
        if (i == n + 1) {
            cout << "输入最后一个矩阵的列数:";
            cin >> m[i - 1];
            break;
        }
        cout << "输入第" << i - 1 << "个矩阵的列数和第" << i << "个矩阵的行数:";
        cin >> m[i - 1];
    }
    cout << "**********************************" << endl;
    cout << n << "个矩阵连乘一共有" << Paren_Increa_Num(n) << "种添加括号的方式\n" <<
         "矩阵连乘的需要的数乘次数最少为:" << Min_Mul(m, 1, n) << endl;
    cout << "**********************************" << endl;
    return 0;
}