#include <iostream>
#include <string>
using namespace std;

int main() {
	int N = 0;

	cin >> N;

	for (int tc = 0; tc < N; tc++)
	{
		int a, b;
		char tmp;
		cin >> a >> tmp >> b;

		cout << a + b << "\n";
	}
}