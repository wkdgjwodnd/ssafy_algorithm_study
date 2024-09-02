#include <iostream>

using namespace std;

// �� N�� �־�������, i��~j�� ������ �� ���ϱ�
int N, M;
int nums[100001];
int acc[100001];

void GetAcc(int i, int j)
{
	int ret = acc[j] - acc[i - 1];
	cout << ret << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		cin >> nums[i];
		acc[i] += (nums[i] + acc[i - 1]);
	}
	
	int a, b;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		GetAcc(a, b);
	}

	return 0;
}