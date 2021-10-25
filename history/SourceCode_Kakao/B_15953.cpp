#include <iostream>

using namespace std;

int rank2017[101];
int reward2017[7]= {0, 500, 300, 200, 50, 30, 10};

int rank2018[65];
void SetRank()
{
    // 2017
    int tempNum = 1;
    for(int i = 1; i <= 21;)
    {
        for(int j = 0; j < tempNum; ++i, ++j)
        {
            rank2017[i] = reward2017[tempNum];
        }
        ++tempNum;
    }

    // 2018
    int reward2018 = 512;
    int people2018 = 1;
    for(int i = 1; i <= 31;)
    {
        for(int j = 0; j < people2018; ++j, ++i)
        {
            rank2018[i] = reward2018;
        }
        reward2018 /= 2;
        people2018 *= 2;
    }
}

int main(void)
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;
    SetRank();
    while(T--)
    {
        int rankA,rankB;
        int result = 0;
        cin >> rankA >> rankB;

        result = (rank2017[rankA] + rank2018[rankB]) * 10000;
        cout << result << '\n';
    }
}