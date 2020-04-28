#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
#include <string>
#include <sstream>
using namespace std;

int triangle[401][801][3]; 
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int index = 0;
	while (true)
	{
		string tempStr;
		getline(cin, tempStr);

		istringstream iss(tempStr);
		string tempNum;
		getline(iss, tempNum, ' ');
		
		int n = stoi(tempNum);

		if (n == 0)
			break;

		int maxValue = INT_MIN;
		for (int i = 0; i < n; ++i)
		{
			int cnt = 2 * i + 1;
			for (int j = 0; j < cnt; ++j)
			{
				getline(iss, tempNum, ' ');
				triangle[i][j][0] = stoi(tempNum);
				if (i == n - 1)
				{
					triangle[i][j][2] = triangle[i][j][0];
				}
				maxValue = max(maxValue, triangle[i][j][0]);
			}
		}

		for (int i = n - 2; i >= 0; --i)
		{
			int cnt = 2 * i + 1;
			for (int j = 0; j < cnt; j+=2)
			{
				triangle[i][j][1] 
					= triangle[i][j][0] + triangle[i+1][j][0] + triangle[i+1][j+1][0] + triangle[i+1][j+2][0];
				triangle[i][j][2] 
					= triangle[i][j][1] + triangle[i + 1][j][2] + triangle[i + 1][j + 2][2]	
					- (triangle[i + 1][j][0] + triangle[i + 1][j + 2][0] + triangle[i+2][j+2][2]);
				maxValue = max(max(maxValue, triangle[i][j][1]), triangle[i][j][2]);
			}
		}
		cout << ++index << ". " << maxValue << "\n";
		memset(triangle, 0, sizeof(triangle));
	}
}