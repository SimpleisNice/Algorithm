#include <iostream>
#include <string>
#include <map>
#include <queue>

using namespace std;

int moveX[] = { 0,0,-1,1 };
int moveY[] = { -1,1,0,0 };
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int startPos = 0;
	int num = 0;

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			int tempNum;
			cin >> tempNum;

			if (tempNum == 0) {
				tempNum = 9;
				startPos = i * 3 + j;
			}
			num = num * 10 + tempNum;
		}
	}

	map<int, int> puzzleInfo;
	puzzleInfo[num] = 0;

	queue<pair<int, int>> tempQ;
	tempQ.push(make_pair(num, startPos));

	while (!tempQ.empty()) {
		int puzzle = tempQ.front().first;
		int x = tempQ.front().second / 3;
		int y = tempQ.front().second % 3;
		string strNum = to_string(puzzle);
		tempQ.pop();

		for (int i = 0; i < 4; ++i) {
			int tempX = x + moveX[i];
			int tempY = y + moveY[i];

			if (tempX < 0 || tempX > 2 || tempY < 0 || tempY > 2)
				continue;

			string tempNum = strNum;
			swap(tempNum[x * 3 + y], tempNum[tempX * 3 + tempY]);
			int tempPuzzle = stoi(tempNum);
			if (puzzleInfo.count(tempPuzzle) == 0) {
				puzzleInfo[tempPuzzle] = puzzleInfo[puzzle] + 1;
				tempQ.push(make_pair(tempPuzzle, tempX * 3 + tempY));
			}
		}
	}

	if (puzzleInfo.find(123456789) != puzzleInfo.end()) {
		cout << puzzleInfo[123456789] << "\n";
	}
	else {
		cout << -1 << "\n";
	}
	return 0;
}