#include <iostream>
#include <string>
#include <cstring>

using namespace std;

// ������ �� �� ���� �����ؼ� ������ Ƚ����ŭ ���� ��ġ�� �ٲ� �� ����
// ������ Ƚ����ŭ ��ȯ������, ������ ��ġ�� �ο��� ����ġ�� ���� ��� ���
// ������ ������ 1, �������� ������ *10 ��
// �׷��ϱ� ������ ������ 1���ڸ���� ���� ��
// ������ ��ġ�� ��ȯ�� �ߺ��Ǿ ��
// ���� ū �ݾ� �˾Ƴ��� ���

// �ִ� 6�ڸ�
// �ִ� 10�� ��ȯ
int N;
int maxTradeCnt;
int maxNum;

// n�� ��ȯ���� �� ���Դ� ���ڵ� ����
// ���� �̹� ���Դ� ���ڶ�� �� dfs ���� �ʰ� ���ư��� �ϱ�
// ���ڿ� ��ȯ Ƚ���� ������� �ߺ� üũ
bool check[11][999999];

void init()
{
    maxNum = 0;
    memset(check, false, sizeof(check));
}

void DFS(string curNum, int cnt)
{
    if (cnt == maxTradeCnt)
    {
        int cur = stoi(curNum);
        if (maxNum < cur)
            maxNum = cur;
        return;
    }

    for (int i = 0; i < N - 1; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            string nextNum = curNum;
            char temp = nextNum[i];
            nextNum[i] = nextNum[j];
            nextNum[j] = temp;
            int inextNum = stoi(nextNum);

            if (check[cnt + 1][inextNum]) continue;

            check[cnt + 1][inextNum] = true;
            DFS(nextNum, cnt + 1);
        }
    }
}

int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        init();
        string curNum;
        cin >> curNum >> maxTradeCnt;
        N = curNum.length();

        DFS(curNum, 0);

        if (maxNum == 0)
            maxNum = stoi(curNum);
        cout << "#" << test_case << " " << maxNum << "\n";
    }
    return 0; // ��������� �ݵ�� 0�� �����ؾ��մϴ�.
}