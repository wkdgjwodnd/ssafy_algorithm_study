#include <iostream>
#include <cstring>
#include <string>
#include <queue>

using namespace std;

struct Point
{
	int y;
	int x;
};

// W: 물, L: 땅
// 각 땅에서 물로 이동하기 위한 최소 이동 횟수를 구하고, 모든 이동 횟수의 합을 출력
int N, M;
int totalCnt;
string MAP[1000];
bool visited[1000][1000];
queue<pair<Point, int>> q;

// 상, 하, 좌, 우
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

void init()
{
	totalCnt = 0;
	memset(visited, false, sizeof(visited));
	while (!q.empty()) q.pop();
}

// 각 물에서 땅까지의 최소 거리를 BFS로 찾기
void BFS()
{
	while (!q.empty())
	{
		Point cur = q.front().first;
		int curCnt = q.front().second;
		q.pop();

		totalCnt += curCnt;

		int ny, nx;
		for (int i = 0; i < 4; i++)
		{
			ny = cur.y + dy[i];
			nx = cur.x + dx[i];

			if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
			if (MAP[ny][nx] == 'W') continue;
			if (visited[ny][nx]) continue;

			visited[ny][nx] = true;
			q.push({ { ny, nx }, curCnt + 1 });
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++)
	{
		init();
		cin >> N >> M;
		for (int i = 0; i < N; i++)
		{
			cin >> MAP[i];

			for (int j = 0; j < M; j++)
			{
				if (MAP[i][j] == 'W')
				{
					q.push({ {i, j}, 0 });
					visited[i][j] = true;
				}
			}
		}

		BFS();

		cout << "#" << test_case << " " << totalCnt << "\n";
	}

	return 0;
}