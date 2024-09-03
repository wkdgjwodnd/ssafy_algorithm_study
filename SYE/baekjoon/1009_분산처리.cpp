#include<iostream>

using namespace std;

int a, b;
// 컴퓨터 10대
// 마지막 데이터가 처리될 컴퓨터 번호를 출력
void solve()
{
	int mod = 1;
	for (int i = 0; i < b; i++)
	{
		mod *= a;
		mod %= 10;
	}

	if (mod == 0)
		mod = 10;
	cout << mod << "\n";
}

int main(int argc, char** argv)
{
	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++)
	{
		cin >> a >> b;
		solve();
	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}