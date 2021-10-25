// 매익 매일 약 반알을 먹음
// 약이 N개 담긴 병을 선물로 줌
// 약 하나를 꺼낸다. 그 다음, 그 약을 반으로 쪼개서 한조각은 먹고, 다른 조각은 다시 병에 넣는다.
// 다음 날부터 병에서 약을 하나 꺼낸다. 반조각이면 그 약을 먹고, 아니라면 반들 쪼개서 한 조각을 먹고, 다른 조각은 병에 넣는다.
// 한 조각을 꺼낸 날에는 W, 반조각을 꺼낸 날에는 H보낸다.
// 받은 문자를 종이에 기록. 총 2N일이 지나면 길이가 2N인 문자열이 만들어지게 된다.
// 이때, 가능한 서로 다른 문자열의 개수는 총 몇 개인가?
// h,w로 구성되어있는것
#include <iostream>
#include <vector>

using namespace std;

long long messageInfo[31][31];

long long setMessageInfo(int h, int w)
{
    if (messageInfo[h][w] != 0)
        return messageInfo[h][w];
    if (w - 1 < 0)
        messageInfo[h][w] = setMessageInfo(h - 1, w + 1);
    else
        messageInfo[h][w] = setMessageInfo(h - 1, w + 1) + setMessageInfo(h, w - 1);
    return messageInfo[h][w];
}

int main(void)
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    messageInfo[1][0] = 1;
    messageInfo[2][0] = 2;
    messageInfo[3][0] = 5;

    for (int i = 1; i <= 30; ++i)
    {
        messageInfo[1][i] = 1 + i;
        messageInfo[0][i] = 1;
    }
    long long num = setMessageInfo(30, 0);

    vector<int> tempVector;
    while(true)
    {
        int tempNum;
        cin >> tempNum;

        if(tempNum == 0) 
            break;
        tempVector.push_back(tempNum);
    }

    for(int i=0, vectorLen = tempVector.size(); i < vectorLen; ++i) {
        cout << messageInfo[tempVector[i]][0] << '\n';
    }
    return 0;
}