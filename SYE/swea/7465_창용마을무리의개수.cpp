#include<iostream>

using namespace std;

int N, M;
int parent[101];

void ParentInit()
{
	for (int i = 1; i <= N; i++)
	{
		parent[i] = i;
	}
}

int GetParent(int a)
{
	if (parent[a] == a)
		return a;

	int ret = GetParent(parent[a]);
	parent[a] = ret;
	return ret;
}

void UnionSet(int a, int b)
{
	int setA = GetParent(a);
	int setB = GetParent(b);

	if (setA == setB)
		return;

	parent[setB] = setA;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N >> M;
		ParentInit();
		for (int i = 0; i < M; i++)
		{
			int a, b;
			cin >> a >> b;
			UnionSet(a, b);
		}

		int cnt = 0;
		for (int i = 1; i <= N; i++)
		{
			if (GetParent(i) == i)
				cnt++;
		}

		cout << "#" << test_case << " " << cnt << "\n";
	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}