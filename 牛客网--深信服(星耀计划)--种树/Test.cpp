//��Ŀ����������һ����ά���飬ֻ����0��1��0��ʾ��ʯ����������1���������������������������ط�����������

//����
//2 3
//0 1 1
//1 1 0

//�����8

//����˼·�����͵Ķ�̬�滮��Ŀ����״̬������

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
	//ѭ����j��ʾ��ǰi���״̬��k��ʾ��һ���״̬
	//(j&(j<<1))!=0  ��ʾ״̬jû�����ڵ���
	//(j&line[i])!=0 ��ʾ״̬jû��������ʯ��
	//(j&k)==0  ��ʾ��i-1��û�����ڵ���
	cout << res;
	system("pause");
	return 0;
}