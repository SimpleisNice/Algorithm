#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int d[1001][1001][1001];
int map[1001][1001];

const int posX[] = {0, 0, -1, 1};
const int posY[] = {-1. 1, 0, 0};
int main(void)
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int N, M;
    scanf("%d %d", &N, &M);

    for(int i = 1; i <= N; ++i)
    {
        for(int j = 1; j <= M; ++j)
        {
            scanf("%1d", &map[i][j]);
        }
    }

    queue<tuple<int, int, int>> tempQ;
    tempQ.push(make_tuple(1,1,0));

    

    while(!tempQ.empty())
    return 0;
}