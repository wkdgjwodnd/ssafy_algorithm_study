#include<iostream>

using namespace std;

int ans;

int main(int argc, char** argv)
{
    int T;
    cin >> T;
    for(int tc = 1; tc <= T ; tc++){
        int a, b;
        cin >> a>> b;
        ans = a+b;
        cout << "Case #"<<tc<<": " << ans << "\n";
    }
    return 0;
}