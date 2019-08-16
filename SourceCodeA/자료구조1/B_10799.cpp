#include <iostream>
#include <algorithm>
#include <tuple>
#include <stack>
#include <string>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string barStr;
	char bar[100001];
	int barSize = 0;
	int sum = 0;
	int posCount = 1;


	cin >> barStr;

	for (int i = 0; i < barStr.length(); ++i)
	{
		bar[i] = barStr.at(i);
	}
	barSize = barStr.length();



	stack<pair<char, int>> tempStack;
	tempStack.push(make_pair(bar[0], posCount));

	for (int i = 1; i < barSize; ++i)
	{
		char tempBar;
		int tempNum = -1;
		++posCount;
		if(!tempStack.empty())
			tie(tempBar, tempNum) = tempStack.top();

		if (bar[i] == '(')
		{
			tempStack.push(make_pair(bar[i], posCount));
		}
		else
		{
			// raiser
			if (tempNum == posCount - 1)
			{
				tempStack.pop();
				sum += tempStack.size();
			}
			else
			{
				sum += 1;
				tempStack.pop();
			}
		}
	}
	cout << sum << '\n';
	return 0;
}