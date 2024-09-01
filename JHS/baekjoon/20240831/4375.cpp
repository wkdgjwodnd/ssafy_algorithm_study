#include<iostream>
using namespace std;

int n;
long long num;
int cnt;

int main()
{
	while (cin >> n)
	{
		num = 1;
		cnt = 1;
		while (true)
		{
			num %= n;
			if (!num)
				break;
			num = ((num * 10) + 1)%n;
			cnt++;
		}
		cout << cnt << '\n';
	}
}
