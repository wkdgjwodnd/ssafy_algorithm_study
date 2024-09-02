#include<iostream>
using namespace std;

int t, n;
long long num[1000001];

void solve()
{
	for (int i = 1; i < 1000001; i++)
	{
		for (int j = i; j < 1000001; j += i)
		{
			num[j] += i;
		}
		num[i] += num[i - 1];
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> n;
		cout << num[n] << '\n';
	}
}
