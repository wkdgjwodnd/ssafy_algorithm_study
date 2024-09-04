#include <iostream>
#include <cstring>

using namespace std;

int N;	// 무게 추 개수 (최대 9개)
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

	// 만약에 남은 무게추를 오른쪽에 다 올려도 조건이 유지된다면,
	// 2^N * N! 식을 이용해서 남은 무게추를 올리는 경우의 수를 바로 계산해버리자
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

		// 기본적으로 왼쪽에 올리기
		DFS(lev + 1, left + weights[i], right);

		// 오른쪽에 추 올려도 왼쪽 무게가 오른쪽 무게보다 크거나 같을때만 오른쪽에 올리기
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

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}