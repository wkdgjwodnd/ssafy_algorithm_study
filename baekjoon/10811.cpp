#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int arr[100];
int tmp[100];
int N, M;

int main() {
	cin >> N >> M;


	for (int i = 1; i <= N; i++)
	{
		arr[i] = i;
	}
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;

		int k = 0;
		
		for (int j = a; j <= b; j++)
		{
			tmp[j] = arr[b - k];
			k++;
		}

		for (int j = a; j <= b; j++)
		{
			arr[j] = tmp[j];
		}
	}

	for (int i = 1; i <= N; i++)
	{
		cout << arr[i] << " ";
	}
}