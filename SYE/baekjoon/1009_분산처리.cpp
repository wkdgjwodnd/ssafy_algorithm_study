#include<iostream>

using namespace std;

int a, b;
// ��ǻ�� 10��
// ������ �����Ͱ� ó���� ��ǻ�� ��ȣ�� ���
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

	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}