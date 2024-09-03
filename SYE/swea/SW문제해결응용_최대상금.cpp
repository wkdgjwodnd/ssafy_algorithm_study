#include <iostream>
#include <string>
#include <cstring>

using namespace std;

// 숫자판 중 두 개를 선택해서 정해진 횟수만큼 서로 위치를 바꿀 수 있음
// 정해진 횟수만큼 교환끝나면, 숫자판 위치에 부여된 가중치에 의해 상금 계산
// 오른쪽 끝부터 1, 왼쪽으로 갈수록 *10 됨
// 그러니까 오른쪽 끝부터 1의자리라고 보면 됨
// 동일한 위치의 교환이 중복되어도 됨
// 가장 큰 금액 알아내서 출력

// 최대 6자리
// 최대 10번 교환
int N;
int maxTradeCnt;
int maxNum;

// n번 교환했을 때 나왔던 숫자들 저장
// 만일 이미 나왔던 숫자라면 더 dfs 하지 않고 돌아가게 하기
// 숫자와 교환 횟수를 기반으로 중복 체크
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
    return 0; // 정상종료시 반드시 0을 리턴해야합니다.
}