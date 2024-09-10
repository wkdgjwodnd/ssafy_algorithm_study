#include <iostream>

using namespace std;

int arr[8][8] = {
	{0,1,1,0,0,0,0,1},
	{0,0,0,0,0,0,0,0},
	{0,0,0,1,1,0,1,0},
	{0,0,0,0,0,1,0,0},
	{0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0}
};

char ch;
int idx;
int mom;
char child[8];
int k = 0;

void dfs() {
	for (int i = 0; i < 8; i++)
	{
		if (arr[i][idx] == 1) {
			mom = i;
			for (int j = 0; j < 8; j++)
			{
				if (arr[mom][j] == 1) {
					child[k] = j + 'A';
					k++;
				}
			}
			return;
		}
	}

	cout << "없음";
	return;
}

int main() {
	cin >> ch;
	if (ch == 'F') {
		cout << "없음";
		return 0;
	}

	idx = ch - 'A';

	dfs();

	for (int i = 0; i < k; i++)
	{
		if (child[i] != ch) cout << child[i] << ' ';
	}
}