#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

// 그래프를 DFS로 탐색한 결과 BFS로 탐색한 결과 출력

int map[1001][1001]; // 맵
int visited[1001]; // 방문여부
int path[1001];
int N, M;
queue<int> q;


void DFS(int now) {
	visited[now] = 1;
	cout << now << " ";
	
	for (int i = 1; i <= N; i++)
	{
		if (map[now][i] == 0 || visited[i] == 1) continue;
		if(map[now][i])
		DFS(i);
	}
}

void BFS(int now) {
	q.push(now);
	visited[now] = 1;
	cout << now << " ";

	while (!q.empty()) {
		now = q.front(); q.pop();
		for (int i = 1; i <= N; i++)
		{
			if (map[now][i] == 0 || visited[i] == 1) continue;
			q.push(i);
			visited[i] = 1;
			cout << i << " ";
		}
	}
}

void init() {
	memset(visited, 0, sizeof(visited));
}

int main() {
	int st;
	cin >> N >> M >> st;
	for (int i = 0; i < M; i++)
	{
		int from, to;
		cin >> from >> to;
		map[from][to] = 1;
		map[to][from] = 1;
	}

	DFS(st);
	init();

	cout << "\n";

	BFS(st);
}