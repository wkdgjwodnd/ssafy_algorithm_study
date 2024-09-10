#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> alist[1005];

struct Node {
	int n;
	int lev;
};

queue<Node> q;
int N, M;

int life[1005];
int result[1005];

void input() {
	   	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;

		alist[a].push_back(b);

		life[b]++;
	}
}

void init() {
	for (int i = 1; i <= N; i++) {
		if (life[i] == 0) {
			q.push({ i, 1 }); 
			result[i] = 1;
		}
	}
}

void bfs() {

	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		for (int next : alist[now.n]) {
			life[next]--;

			if (life[next] == 0) {
				result[next] = now.lev + 1;
				q.push({ next, now.lev + 1 });
			}
		}
	}
}

int main() {
	input();

	init();
	bfs();

	for (int i = 1; i <= N; i++) {
		cout << result[i] << " ";
	}
}
