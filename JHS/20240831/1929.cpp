#include<iostream>
#include<cmath>
using namespace std;

int n, m;
int arr[1000001];

void init()
{
	for (int i = 2; i < 1000001; i++)
	{
		arr[i] = 1;
	}
}

void solve(int first, int second)
{
	for (int i = 2; i <= sqrt(second); i++)
	{
		if (arr[i])
		{
			for (int j = i * i; j <= second; j += i)
			{
				if (arr[j])
					arr[j] = 0;
			}
		}
	}
	for (int i = first; i <= second; i++)
	{
		if (arr[i])
			cout << i << '\n';
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	init();
	cin >> m >> n;
	solve(m, n);
}
