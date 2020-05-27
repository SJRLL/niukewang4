//题目描述：输入一个二维数组，只包含0和1，0表示岩石不能种树，1表述可以种树，但是相邻两个地方不能种树。

//例：
//2 3
//0 1 1
//1 1 0

//输出：8

//解题思路：典型的动态规划题目，找状态！！！

#include<vector>
#include<stdlib.h>
#include<iostream>
using namespace std;

int cat[15][15];
int line[15];
int dp[15][2200];
int res = 0;
const int MOD = 100000000;
int n, m;

int main()
{
	cin >> m >> n;
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> cat[i][j];
			line[i] = line[i] * 2 + (cat[i][j] == 0 ? 1 : 0);
		}
	}

	for (int i = 0; i < (1 << n); ++i)
	{
		if (((i&line[0]) == 0) && ((i&(i << 1)) == 0))
		{
			dp[0][i] = 1;
		}
	}

	for (int j = 0; j < (1 << n); ++j)
	{
		if (((j&line[0]) == 0) && ((j&(j << 1)) == 0))
		{
			dp[0][j] = 1;
		}
	}

	for (int i = 1; i < m; ++i)
	{
		for (int j = 0; j < (1 << n); ++j)
		{
			if ((j&(j << 1)) != 0 || ((j&line[i]) != 0))
			{
				continue;
			}
			for (int k = 0; k < (1 << n); ++k)
			{
				if ((j&k) == 0)
				{
					dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
				}
			}
			if (i == m - 1)
			{
				res = (res + dp[i][j]) % MOD;
			}
		}
	}
	//循环里j表示当前i层的状态，k表示上一层的状态
	//(j&(j<<1))!=0  表示状态j没有相邻的树
	//(j&line[i])!=0 表示状态j没有种在岩石上
	//(j&k)==0  表示与i-1层没有相邻的树
	cout << res;
	system("pause");
	return 0;
}