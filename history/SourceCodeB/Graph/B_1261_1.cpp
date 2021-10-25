#include <iostream>
#include <deque>
#include <algorithm>
#include <tuple>

using namespace std;

int d[101][101];
char map[101][101];
const int posX[] = {0, 0, -1, 1};
const int posY[] = {-1, 1, 0, 0};

int main(void)
{   
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    for(int i = 0; i <= N; ++i)
    {
        cin >> map[i];
    }

    deque<pair<int, int>> tempD;    //세로, 가로
    d[N][M] = 0;
    tempD.push_front(N, M);

    while(!tempD.empty())
    {
        int tempX, tempY;
        tie(tempX, tempY) = tempD.front();

        tempD.pop_front();

        for(int i = 0; i < 4; ++i)
        {

        }
    }


    return 0;
}