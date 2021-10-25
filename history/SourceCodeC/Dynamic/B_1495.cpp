// n개의 곡

// 매번 곡이 시작하기 전에 볼륨을 바꾸고 연주함

// 공연이 시작하기 전에 각각의 곡이 시작하기 전에 바꿀 수 있는 볼륨의 리스트를 만듬

// 리스트를 v라고 했을 때, v[i]는 i번째 곡을 연주하기 전에 바꿀 수 있는 볼륨을 의미

// 항상 리스트에 적힌 차이로만 볼륨을 바꿀 수 있다.

// 즉, 현재 볼륨이 p이고 지금 i번째 곡을 연주하기 전이라면, i번 곡은 p + v[i] 또는 p - v[i]로 연주 해야 한다.

// 하지만, 0보다 작은 값으로 볼륨을 바꾸거나, m보다 큰 값으로 볼륨을 바꿀 수 없다.

// n개의 곡, s 시작 볼륨, m이 주어졌을 때, 마지막 곡을 연주할 수 있는 볼륨 중 최댓값을 구하는 프로그램

// 만약 마지막 곡을 연주할 수 없다면(중간에 볼륨을 조절을 할 수 없다면) -1을 출력

#include <iostream>

using namespace std;

int v[101];
int guitarList[101][1001];
int maxVolume = -1;
int n,m;

int main(void)
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int s;
    cin >> n >> s >> m;

    guitarList[0][s] = 1;
    for(int i=1; i<=n; ++i)
    {
        cin >> v[i];
    }


    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<=m; ++j)
        {
            if(guitarList[i][j] == 1)
            {
                if(j + v[i + 1] <= m )
                    guitarList[i+1][j + v[i+1]] = 1;
                if(j - v[i + 1] >= 0)
                    guitarList[i+1][j - v[i+1]] = 1;
            }
        }
    }
    for(int i=0; i<= m; ++i)
    {
        if(guitarList[n][i] == 1)
            maxVolume = i;
    }
    cout << maxVolume << '\n';

    return 0;
}