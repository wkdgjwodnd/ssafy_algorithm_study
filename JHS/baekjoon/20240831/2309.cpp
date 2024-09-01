#include<iostream>
#include<algorithm>
using namespace std;

int arr[9], sum, flag;
int visited[9];

void search(int cnt)
{
	if (sum > 100)
		return;
	if (cnt == 7)
	{
		if (sum < 100)
			return;
		else if(sum == 100)
		{
			for (int i = 0; i < 9; i++)
			{
				if (visited[i])
					cout << arr[i] << '\n';
			}
			flag = 1;
		}
	}
	for (int i = 0; i < 9; i++)
	{
		if (visited[i])
			continue;
		visited[i] = 1;
		sum += arr[i];
		search(cnt + 1);
		visited[i] = 0;
		sum -= arr[i];
		if (flag)
			return;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	for (int i = 0; i < 9; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + 9);
	search(0);
}
