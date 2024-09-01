#include<iostream>
using namespace std;

int n;
char map[51][51];
int Max;

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

void Find()
{
	int cnt = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if (map[i][j] == map[i][j + 1])
			{
				cnt++;
			}
			else
			{
				if (Max < cnt)
					Max = cnt;
				cnt = 1;
			}
		}
		if (Max < cnt)
			Max = cnt;
		cnt = 1;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if (map[j][i] == map[j + 1][i])
			{
				cnt++;
			}
			else
			{
				if (Max < cnt)
					Max = cnt;
				cnt = 1;
			}
		}
		if (Max < cnt)
			Max = cnt;
		cnt = 1;
	}
}

void search()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				int ny = i + dy[k];
				int nx = j + dx[k];
				if (ny < 0 || ny >= n || nx < 0 || nx >= n)
					continue;
				char temp = map[i][j];
				map[i][j] = map[ny][nx];
				map[ny][nx] = temp;
				Find();
				map[ny][nx] = map[i][j];
				map[i][j] = temp;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> map[i];
	}
	search();
	cout << Max;
}
