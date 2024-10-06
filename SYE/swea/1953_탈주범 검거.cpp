#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

struct Point
{
	int y;
	int x;
};

int N, M;	// N: 세로 크기, M: 가로 크기
int L;		// 탈출 후 소요된 시간
int MAP[50][50];
int dist[50][50];

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

// 각 터널별 상하좌우가 연결되었는지 여부를 나타내는 배열
bool tunnels[8][4] = {
	{0, 0, 0, 0},
	{1, 1, 1, 1},
	{1, 1, 0, 0},
	{0, 0, 1, 1},
	{1, 0, 0, 1},
	{0, 1, 0, 1},
	{0, 1, 1, 0},
	{1, 0, 1, 0} };

void init()
{
	memset(dist, 0, sizeof(dist));
}

bool CanGo(int curType, int nextType, int dir)
{
	if (nextType == 0)
		return false;

	int dirReverse = 0;
	switch (dir)
	{
	case 0:
		dirReverse = 1;
		break;

	case 1:
		dirReverse = 0;
		break;

	case 2:
		dirReverse = 3;
		break;

	case 3:
		dirReverse = 2;
		break;
	}

	if (tunnels[curType][dir] == 1 && tunnels[nextType][dirReverse] == 1)
		return true;
	else
		return false;
}

int BFS(Point st)
{
	queue<Point> q;
	q.push(st);
	dist[st.y][st.x] = 1;

	int cnt = 0;
	while (!q.empty())
	{
		Point cur = q.front();
		q.pop();

		if (dist[cur.y][cur.x] > L)	break;

		cnt++;

		int curTunnel = MAP[cur.y][cur.x];
		int ny, nx;
		for (int i = 0; i < 4; i++)
		{
			ny = cur.y + dy[i];
			nx = cur.x + dx[i];

			if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
			if (dist[ny][nx] > 0) continue;
			if (!CanGo(curTunnel, MAP[ny][nx], i)) continue;

			dist[ny][nx] = dist[cur.y][cur.x] + 1;
			q.push({ ny, nx });
		}
	}

	return cnt;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	Point st;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		init();
		cin >> N >> M >> st.y >> st.x >> L;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				cin >> MAP[i][j];
			}
		}

		int cnt = 0;
		if (L == 1)
			cnt = 1;
		else
			cnt = BFS(st);

		// 탈주범이 위치할 수 있는 장소의 개수 구하라
		cout << "#" << test_case << " " << cnt << "\n";
	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}