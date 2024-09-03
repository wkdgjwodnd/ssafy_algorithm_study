#include <iostream>

using namespace std;

// ���ӵ� �� ���ڿ� ������ 1�� �̻� �ִٸ� => ������ ���ӵǾ��ٰ� ǥ��
// ���ӵ� ��� ������ �ϳ��� ���簡���� ���ԵǾ�� ��
// ���ӵ� ������ ��� ���δ� ���� ���� ���簢���� ũ�⸸ŭ ������ ����

// ������ ���۳�¥�� ���ᳯ¥ ����
// �������� ���� ���, ���� �Ⱓ�� �� ���� ���� ä����
// ������ ������ �� ��ܿ� ��ġ
// ���� �ϳ��� ���� ���̴� 1
// �Ϸ��� ���� 1

// ������ �־��� ��, �����̰� �ڸ��� �������� ������ ���ϱ�
int N;	// ������ ����
int schedules[366];

int main(int argc, char** argv)
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int s, e;
		cin >> s >> e;
		for (int j = s; j <= e; j++)
		{
			schedules[j]++;
		}
	}

	// ������ ���� ���ϱ�
	int area = 0;
	int maxHeight = 0;
	int st = 1;
	for (int i = 1; i <= 365; i++)
	{
		if (schedules[i] == 0)
		{
			area += ((i - 1 - st + 1) * maxHeight);
			st = i + 1;
			maxHeight = 0;
		}

		if (schedules[i] > maxHeight)
			maxHeight = schedules[i];
	}

	if (schedules[365] > 0)
		area += ((365 - st + 1) * maxHeight);

	cout << area;

	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}