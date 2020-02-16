#include <iostream>
#include <queue>
#include <set>
#include <tuple>

using namespace std;

int result = 0;
queue<tuple<int, int, int>> tempQ;
set<tuple<int, int, int>> tempS;

void cmpStone(int *tempStone)
{
    for (int i = 0; i < 3; ++i)
    {
        int temp = tempStone[i];
        for (int j = i + 1; j < 3; ++j)
        {
            if (temp < tempStone[j])
            {
                tempStone[i] = tempStone[j];
                tempStone[j] = temp;
                temp = tempStone[i];
            }
        }
    }
}
bool isEnd(int fStone, int sStone, int mStone)
{
    int sampleStone[3]; // big, small, middle
    if (fStone > sStone)
    {
        sampleStone[0] = fStone - sStone;
        sampleStone[1] = sStone * 2;
    }
    else if (fStone < sStone)
    {
        sampleStone[0] = sStone - fStone;
        sampleStone[1] = fStone * 2;
    }
    else
        return false;
    sampleStone[2] = mStone;
    if (sampleStone[0] == sampleStone[1] && sampleStone[1] == sampleStone[2])
    {
        result = 1;
        return true;
    }
    cmpStone(sampleStone);
    if (tempS.find(make_tuple(sampleStone[0], sampleStone[1], sampleStone[2])) == tempS.end())
    {
        tempQ.push(make_tuple(sampleStone[0], sampleStone[1], sampleStone[2]));
        tempS.insert(make_tuple(sampleStone[0], sampleStone[1], sampleStone[2]));
    }
    return false;
}
int main(void)
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int stone[3];
    for (int i = 0; i < 3; ++i)
    {
        cin >> stone[i];
    }

    cmpStone(stone);
    tempQ.push(make_tuple(stone[0], stone[1], stone[2]));
    tempS.insert(make_tuple(stone[0], stone[1], stone[2]));
    int tempStone[3];

    bool resultCheck = false;
    while (!tempQ.empty())
    {
        tempStone[0] = get<0>(tempQ.front());
        tempStone[1] = get<1>(tempQ.front());
        tempStone[2] = get<2>(tempQ.front());
        tempQ.pop();
        if(tempStone[0] == tempStone[1] && tempStone[1] == tempStone[2])
        {
            result = 1;
            break;
        }
        if (isEnd(tempStone[0], tempStone[1], tempStone[2]))
            break;
        if (isEnd(tempStone[0], tempStone[2], tempStone[1]))
            break;
        if (isEnd(tempStone[1], tempStone[2], tempStone[0]))
            break;
    }
    cout << result << '\n';
    return 0;
}