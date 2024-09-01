#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;
int N;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < N; i++)
	{
		cout << v[i] << "\n";
	}

}