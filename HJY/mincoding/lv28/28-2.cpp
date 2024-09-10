#include <iostream>

using namespace std;

int N;
int arr[100][100];
int path[100];

int boss;
int under[100];
int k = 0;

void func() {
	for (int i = 0; i < N; i++)
	{
		if (arr[0][i] == 1) {
			under[k] = i;
			k++;
		}
	}
}

void dfs(int now) {
	// now == 3일때
	for (int i = 0; i < N; i++)
	{
		if (arr[i][0] == 1) {
			boss = i;
			func();
			return;
		}
	}
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
		}
	}

	dfs(0);

	cout << "boss:" << boss << '\n';
	cout << "under:";
	for (int i = 0; i < k; i++)
	{
		cout << under[i] << ' ';
	}
}
