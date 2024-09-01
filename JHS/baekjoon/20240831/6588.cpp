#include<iostream>
#include<cmath>
using namespace std;

int t, n, m, flag;
int arr[1000001];

void init()
{
	for (int i = 2; i < 1000001; i++)
	{
		arr[i] = 1;
	}
	for (int i = 2; i <= sqrt(1000000); i++)
	{
		if (arr[i])
		{
			for (int j = i * i; j <= 1000000; j += i)
			{
				if (arr[j])
					arr[j] = 0;
			}
		}
	}
}

void solve(int num)
{
	flag = 0;
	for (int i = 3; i < num; i += 2)
	{
		if (arr[i] & arr[num - i])
		{
			cout << num << " = " << i << " + "
				<< num - i << '\n';
			return;
		}
	}
	cout << "Goldbach's conjecture is wrong." << '\n';
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	init();
	while (cin >> n)
	{
		if (!n)
			break;
		solve(n);
	}
}
