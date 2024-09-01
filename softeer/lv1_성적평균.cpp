#include<iostream>
#include<stdio.h>

using namespace std;

int N, L;
double S[101];

int main(int argc, char** argv)
{
    cin >> N >> L;
    double avg = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> S[i];
    }
    for (int tc = 0; tc < L; tc++) {
        int a = 0, b = 0;
        avg = 0;
        cin >> a >> b;
        a -= 1;
        b -= 1;
        for (int i = a; i <= b; i++) {
            avg += S[i];
        }
        avg = avg / (float(b - a + 1));
        printf("%.2f", avg);
        cout << "\n";
    }
    return 0;
}