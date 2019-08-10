#include <iostream>
#include <algorithm>
using namespace std;


long GetYear(int N, int M, int X, int Y)
{
    int tempN = 0;
    if(N == 1 && M == 1 && X == 1 && Y == 1)
        return 1;
    while(true)
    {
        if((tempN * M + X) % M == X && (tempN * M + X) % N == Y)
        {
            return tempN * M + X;
        }
        ++tempN;
        if(M * tempN >= 40000 * N *M)
            break;
    }
    return -1;
}
int main(void)
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int T;
    int M, N, X, Y;
    cin >> T;

    for(int i = 0; i < T; ++i)
    {
        cin >> M >> N >> X >> Y;

        long year = GetYear(N, M, X, Y);
        cout << year << '\n';
    }
}