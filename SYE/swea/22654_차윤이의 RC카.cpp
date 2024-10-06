#include <iostream>

using namespace std;

struct Point
{
	int y;
	int x;
};

int N;
Point st;
char MAP[5][5];

// ��, ��, ��, ��
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

// A: ������ �̵�, L: �������� 90�� ȸ��, R: ���������� 90�� ȸ��
// T: �̵� �Ұ�, X: ���� ��ġ, Y: ������
// Ŀ�ǵ带 ���� ���� �� �������� �����ߴ���
int CanArrive(string command)
{
	int curDir = 0;	// ���� �ٶ󺸰� �ִ� ����
	Point cur = st;
	int ny, nx;
	for (int i = 0; i < command.length(); i++)
	{
		if (command[i] == 'A')
		{
			ny = cur.y + dy[curDir];
			nx = cur.x + dx[curDir];

			if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
			if (MAP[ny][nx] == 'T') continue;

			cur.y = ny;
			cur.x = nx;
		}
		else if (command[i] == 'L')
			curDir = (curDir - 1) % 4;
		else if (command[i] == 'R')
			curDir = (curDir + 1) % 4;
	}

	if (MAP[cur.y][cur.x] == 'Y')
		return 1;
	else
		return 0;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> MAP[i][j];
				if (MAP[i][j] == 'X')
					st = { i, j };
			}
		}

		cout << "#" << test_case << " ";

		int Q;
		cin >> Q;
		for (int i = 0; i < Q; i++)
		{
			int C;
			cin >> C;
			string command;
			cin >> command;

			cout << CanArrive(command) << " ";
		}

		cout << "\n";
	}

	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}