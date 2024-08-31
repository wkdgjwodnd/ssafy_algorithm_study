#include<iostream>
using namespace std;

int n, Max = 0, Min = 21e8;
int arr[51];

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		if (arr[i] > Max)
			Max = arr[i];
		if (arr[i] < Min)
			Min = arr[i];
	}
	cout << Max * Min;
}
