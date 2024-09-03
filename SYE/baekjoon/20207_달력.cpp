#include <iostream>

using namespace std;

// 연속된 두 일자에 일정이 1개 이상 있다면 => 일정이 연속되었다고 표현
// 연속된 모든 일정은 하나의 직사가형에 포함되어야 함
// 연속된 일정을 모두 감싸는 가장 작은 직사각형의 크기만큼 코팅지 오림

// 일정은 시작날짜와 종료날짜 포함
// 시작일이 같을 경우, 일정 기간이 긴 것이 먼저 채워짐
// 일정은 가능한 최 상단에 배치
// 일정 하나의 세로 길이는 1
// 하루의 폭은 1

// 일정이 주어질 때, 수현이가 자르는 코팅지의 면적을 구하기
int N;	// 일정의 개수
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

	// 코팅지 면적 구하기
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

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}