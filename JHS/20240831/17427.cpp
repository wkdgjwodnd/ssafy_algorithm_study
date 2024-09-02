#include<iostream>
using namespace std;

int n, Max;
long long num;
int arr[10000];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		num += n / i * i;
	}
	cout << num;
}
