#include <vector>
#include <queue>
using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
bool checkMap[100][100];
int moveX[] = {0, 0, -1, 1};
int moveY[] = {-1, 1, 0, 0};
vector<int> solution(int m, int n, vector<vector<int>> picture)
{
    int number_of_area = 0;
    int max_size_of_one_area = 0;

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;

    // init
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            checkMap[i][j] = false;
        }
    }

    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (checkMap[i][j] || picture[i][j] == 0)
                continue;
            int tempCnt = 1;
            int color = picture[i][j];

            number_of_area++;
            checkMap[i][j] = true;

            queue<pair<int, int>> tempQ;
            tempQ.push(make_pair(i, j));

            while (!tempQ.empty())
            {
                int x = tempQ.front().first;
                int y = tempQ.front().second;
                tempQ.pop();

                for (int k = 0; k < 4; ++k)
                {
                    int tempX = x + moveX[k];
                    int tempY = y + moveY[k];

                    if (tempX < 0 || tempX > m - 1 || tempY < 0 || tempY > n - 1)
                    {
                        continue;
                    }

                    if (color != picture[tempX][tempY])
                        continue;
                    if (checkMap[tempX][tempY])
                        continue;

                    tempQ.push(make_pair(tempX, tempY));
                    checkMap[tempX][tempY] = true;
                    tempCnt++;
                }
            }
            if (tempCnt > answer[1])
            {
                answer[1] = tempCnt;
            }
        }
    }
    answer[0] = number_of_area;
    return answer;
}