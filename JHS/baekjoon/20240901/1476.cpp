#include<iostream>
using namespace std;

int e, s, m;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> e >> s >> m;
	int a = 1, b = 1, c = 1;
	int cnt = 1;
	while (true)
	{
		if (a == e && b == s && c == m)
			break;
		a++, b++, c++, cnt++;
		if (a > 15) a = 1;
		if (b > 28) b = 1;
		if (c > 19) c = 1;
	}
	cout << cnt;
}
