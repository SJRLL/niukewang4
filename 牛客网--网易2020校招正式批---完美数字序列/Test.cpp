小易定义一个数字序列是完美的，当且仅当对于任意2<=i<=n，都满足1<=j<=i，即每个数字都要大于等于前面所有数字的和。
现在给定数字序列Ai，小易想请你从中找出最长的一段连续子序列，满足它是完美的。

//解题思路：设置起点start，遍历数组，遍历过程中不断更新start和最大长度

#include <iostream>
using namespace std;

int main() {
	int n, m;
	cin >> n;
	while (n--) 
	{
		cin >> m;
		int nums[m];
		int start = 1;
		int res = 0;
		for (int i = 0; i < m; i++) 
		{
			cin >> nums[i];
		}
		int sum = nums[0];
		for (int i = 1; i < m; i++) 
		{
			if (sum <= nums[i])
			{
				sum += nums[i];
				res = max(res, i - start + 1);
			}
			else
			{
				start = i;
				sum = nums[i];
			}
		}
		cout << res << endl;
	}
}