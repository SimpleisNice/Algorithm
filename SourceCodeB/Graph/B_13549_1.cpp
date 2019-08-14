#include <iostream>
#include <deque>

using namespace std;

int d[1000001];
bool check[1000001];
int MAX = 1000001;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int N, K;
    cin >> N >> K;

    deque<int> tempD;
    tempD.push_front(N);
    d[N] = 0;
    check[N] = true;

    while(!tempD.empty())
    {
        int tempN = tempD.front();
        tempD.pop_front();

        if(tempN * 2 < MAX)
        {
            if(check[tempN * 2] == false)
            {
                tempD.push_front(tempN * 2);
                check[tempN * 2] = true;
                d[tempN * 2] = d[tempN];
            }
        }
        if(tempN + 1 < MAX)
        {
            if(check[tempN + 1] == false)
            {
                tempD.push_back(tempN + 1);
                check[tempN + 1] = true;
                d[tempN + 1] = d[tempN] + 1;
            }
        }
        if(tempN - 1 >= 0)
        {
            if(check[tempN - 1] == false)
            {
                tempD.push_back(tempN - 1);
                check[tempN - 1] = true;
                d[tempN - 1] = d[tempN] + 1;
            }
        }
    }

    cout << d[K] << '\n';
}