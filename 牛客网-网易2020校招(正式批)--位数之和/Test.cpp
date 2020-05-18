定义S(n)，表示n在十进制下的各位数字和。
现在给定一个x, 请你求出最小正整数n，满足x<=S(n)

#include<bits/stdc++.h>
using namespace std;
int main(){
	int T, n, m;
	cin >> T;
	long long x;
	while (T--){
		cin >> x;
		n = x / 9;
		m = x % 9;
		if (m != 0)
			cout << m;
		for (int i = 0; i<n; i++)
			cout << "9";
		cout << endl;
	}

	return 0;
}