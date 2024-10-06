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

int N, K;	// N: �ʵ��� ũ��, K: ���� �� �� �ִ� Ƚ��
int minCnt = 21e8;
char MAP[10][10];
bool visited[10][10];

// ��, ������, �Ʒ�, ������ ���� ���� �� ��, ��, ��, �� �� �̵��Ϸ��� �ʿ��� ���� Ƚ��
// ȸ���� + ���� ��
int turns[4][4] = { 1, 2, 3, 2,
					2, 1, 2, 3,
					3, 2, 1, 2,
					2, 3, 2, 1 };

// ��, ��, ��, ��
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

void init()
{
	minCnt = 21e8;
	memset(visited, false, sizeof(visited));
}

// G: �̵� ���� ��, T: ����, X: �����, Y: ������
// DFS�� ������ ����鼭 ���������� ���� ����Ƚ���� ���ϱ�
// ����ġ, ���� �� Ƚ��, ���� Ƚ��
void DFS(Point cur, int cutCnt, int cnt)
{
	if (MAP[cur.y][cur.x] == 'Y')
	{
		minCnt = min(minCnt, cnt);
		return;
	}

	if (cnt >= minCnt)
		return;

	// �� �� �� �� �� �̵�
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

		st.dir = 0;	// �׻� ���� �ٶ󺸴� ���·� ����
		DFS(st, 0, 0);

		// ��������� ���������� �����ϱ� ���� �ּ� ���� Ƚ���� ���
		// ���������� �� �� ���ٸ� -1 ���
		if (minCnt == 21e8)
			minCnt = -1;

		cout << "#" << test_case << " " << minCnt << "\n";
	}

	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}