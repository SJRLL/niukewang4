����S(n)����ʾn��ʮ�����µĸ�λ���ֺ͡�
���ڸ���һ��x, ���������С������n������x<=S(n)

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