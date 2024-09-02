#include<iostream>
using namespace std;

int N, M, sum;
int num[100001];


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> num[i];
		if (i > 0)
			num[i] += num[i - 1];
	}
	for (int i = 0; i < M; i++)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		a -= 2, b -= 1;
		if (a < 0)
			cout << num[b] << '\n';
		else
			cout << num[b] - num[a] << '\n';
	}
}
