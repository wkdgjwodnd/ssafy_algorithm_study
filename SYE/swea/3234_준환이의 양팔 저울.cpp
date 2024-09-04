#include <iostream>
#include <cstring>

using namespace std;

int N;	// ���� �� ���� (�ִ� 9��)
int cnt;
int totalWeights;
int weights[9];
bool check[9];

void init()
{
	cnt = 0;
	totalWeights = 0;
	memset(check, false, sizeof(check));
}

void DFS(int lev, int left, int right)
{
	if (lev == N)
	{
		cnt++;
		return;
	}

	// ���࿡ ���� �����߸� �����ʿ� �� �÷��� ������ �����ȴٸ�,
	// 2^N * N! ���� �̿��ؼ� ���� �����߸� �ø��� ����� ���� �ٷ� ����ع�����
	if (left >= totalWeights - left)
	{
		int remainCnt = N - lev;
		int cases = 1;

		cases = 1 << remainCnt;	// 2^N
		for (int i = remainCnt; i > 0; i--)
		{
			cases *= i;
		}

		cnt += cases;

		return;
	}

	for (int i = 0; i < N; i++)
	{
		if (check[i]) continue;

		check[i] = true;

		// �⺻������ ���ʿ� �ø���
		DFS(lev + 1, left + weights[i], right);

		// �����ʿ� �� �÷��� ���� ���԰� ������ ���Ժ��� ũ�ų� �������� �����ʿ� �ø���
		if (left >= right + weights[i])
			DFS(lev + 1, left, right + weights[i]);

		check[i] = false;
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		init();
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			cin >> weights[i];
			totalWeights += weights[i];
		}

		DFS(0, 0, 0);

		cout << "#" << test_case << " " << cnt << "\n";
	}

	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}