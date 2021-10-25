#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int moveMap[300][300];
int moveX[] = { -2, -1, 1, 2, -2, -1, 1, 2 };
int moveY[] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int testCase;
	cin >> testCase;

	while (testCase--) {
		int mapSize;
		int xStartPos, yStartPos;
		int xEndPos, yEndPos;
		cin >> mapSize >> xStartPos >> yStartPos >> xEndPos >> yEndPos;

		queue<pair<int, int>> tempQ;
		moveMap[xStartPos][yStartPos] = 1;
		tempQ.push({ xStartPos, yStartPos });

		while (!tempQ.empty()) {
			int x = tempQ.front().first;
			int y = tempQ.front().second;
			int moveCnt = moveMap[x][y];
			tempQ.pop();

			for (int i = 0; i < 8; ++i) {
				int tempX = x + moveX[i];
				int tempY = y + moveY[i];

				if (tempX < 0 || tempX > mapSize - 1 || tempY < 0 || tempY > mapSize - 1) {
					continue;
				}
				if (moveMap[tempX][tempY] != 0 && moveMap[tempX][tempY] <= moveCnt + 1) {
					continue;
				}
				tempQ.push({ tempX, tempY });
				moveMap[tempX][tempY] = moveCnt + 1;
			}
		}
		cout << moveMap[xEndPos][yEndPos] - 1<< "\n";
		// init;
		for (int i = 0; i < mapSize; ++i) {
			for (int j = 0; j < mapSize; ++j) {
				moveMap[i][j] = 0;
			}
		}
	}
}