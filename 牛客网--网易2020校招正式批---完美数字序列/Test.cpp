С�׶���һ�����������������ģ����ҽ�����������2<=i<=n��������1<=j<=i����ÿ�����ֶ�Ҫ���ڵ���ǰ���������ֵĺ͡�
���ڸ�����������Ai��С������������ҳ����һ�����������У��������������ġ�

//����˼·���������start���������飬���������в��ϸ���start����󳤶�

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