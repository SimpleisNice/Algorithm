#include <iostream>

using namespace std;

long long test_case[5001];

void get_L()
{
    test_case[2] = 1;
    test_case[4] = 2;
    for(int i=6; i<=5000; i+=2)
    {
        test_case[i] = (test_case[i -2] * 2 + test_case[i - 4]) % 1000000007;
    }
}
int main(void)
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;

    get_L();
    while(t--)
    {
        int temp_num;
        cin >> temp_num;

        cout << test_case[temp_num] << '\n';
    }

    return 0;
}