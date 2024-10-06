#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

struct Point
{
	int y;
	int x;
	int dir;
};

int N, K;	// N: 필드의 크기, K: 나무 벨 수 있는 횟수
int minCnt = 21e8;
char MAP[10][10];
bool visited[10][10];

// 위, 오른쪽, 아래, 왼쪽을 보고 있을 때 상, 우, 하, 좌 로 이동하려면 필요한 조작 횟수
// 회전값 + 전진 값
int turns[4][4] = { 1, 2, 3, 2,
					2, 1, 2, 3,
					3, 2, 1, 2,
					2, 3, 2, 1 };

// 상, 우, 하, 좌
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

void init()
{
	minCnt = 21e8;
	memset(visited, false, sizeof(visited));
}

// G: 이동 가능 땅, T: 나무, X: 출발지, Y: 목적지
// DFS로 나무를 베어가면서 목적지까지 가는 조작횟수를 구하기
// 현위치, 나무 벤 횟수, 조작 횟수
void DFS(Point cur, int cutCnt, int cnt)
{
	if (MAP[cur.y][cur.x] == 'Y')
	{
		minCnt = min(minCnt, cnt);
		return;
	}

	if (cnt >= minCnt)
		return;

	// 상 하 좌 우 로 이동
	int ny, nx;
	for (int i = 0; i < 4; i++)
	{
		ny = cur.y + dy[i];
		nx = cur.x + dx[i];

		if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
		if (visited[ny][nx]) continue;
		if (MAP[ny][nx] == 'T' && cutCnt == K) continue;

		visited[ny][nx] = true;

		if (MAP[ny][nx] == 'T')
			DFS({ ny, nx, i }, cutCnt + 1, cnt + turns[cur.dir][i]);
		else
			DFS({ ny, nx, i }, cutCnt, cnt + turns[cur.dir][i]);

		visited[ny][nx] = false;
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	//freopen("input.txt", "r", stdin);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		init();
		cin >> N >> K;

		Point st;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> MAP[i][j];
				if (MAP[i][j] == 'X')
					st = { i, j };
			}
		}

		st.dir = 0;	// 항상 위를 바라보는 상태로 시작
		DFS(st, 0, 0);

		// 출발지에서 목적지까지 도착하기 위한 최소 조작 횟수를 출력
		// 목적지까지 갈 수 없다면 -1 출력
		if (minCnt == 21e8)
			minCnt = -1;

		cout << "#" << test_case << " " << minCnt << "\n";
	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}