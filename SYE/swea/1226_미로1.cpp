#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

struct Point
{
	int y;
	int x;
};

// 16*16 크기의 맵
// 1: 벽, 0: 길, 2: 출발점, 3: 도착점
int MAP[16][16];
bool visited[16][16];

// 상, 하, 좌, 우
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

void init()
{
	memset(visited, false, sizeof(visited));
}

int BFS(Point st)
{
	queue<Point> q;
	q.push(st);
	visited[st.y][st.x] = true;

	while (!q.empty())
	{
		Point cur = q.front();
		q.pop();

		if (MAP[cur.y][cur.x] == 3)
			return 1;

		int ny, nx;
		for (int i = 0; i < 4; i++)
		{
			ny = cur.y + dy[i];
			nx = cur.x + dx[i];

			if (ny < 0 || ny >= 16 || nx < 0 || nx >= 16) continue;
			if (MAP[ny][nx] == 1) continue;
			if (visited[ny][nx]) continue;

			q.push({ ny, nx });
			visited[ny][nx] = true;
		}
	}

	return 0;
}

int main(int argc, char** argv)
{
	int test_case;
	for (test_case = 1; test_case <= 10; ++test_case)
	{
		init();

		// 맵 입력받기
		int T;
		cin >> T;
		Point st;
		for (int i = 0; i < 16; i++)
		{
			string str;
			cin >> str;
			for (int j = 0; j < 16; j++)
			{
				MAP[i][j] = str[j] - '0';
				if (MAP[i][j] == 2)
					st = { i, j };
			}
		}

		// BFS 탐색으로 도착점 갈 수 있는지 확인
		int canArrive = BFS(st);

		cout << "#" << T << " " << canArrive << "\n";
	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}