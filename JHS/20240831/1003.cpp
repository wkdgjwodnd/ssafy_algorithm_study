#include<iostream>
using namespace std;

int t, n;
int arr[41];

void solve(int n) {
    if (n == 1)
        cout << "0 " << "1" << '\n';
    else if (n == 0)
        cout << "1 " << "0" << '\n';
    else
    {
        arr[0] = 1, arr[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            arr[i] = arr[i - 1] + arr[i - 2];
        }
        cout << arr[n - 2] << " " << arr[n - 1] << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        solve(n);
    }
}
