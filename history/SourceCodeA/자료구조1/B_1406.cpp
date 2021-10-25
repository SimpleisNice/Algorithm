#include <iostream>
#include <stack>
#include <string>

using namespace std;

char resultTemp[600001];
int main(void)
{
	string tempStr;
	cin >> tempStr;

	stack<char> frontStack;
	stack<char> backStack;

	for (int i = 0; i < tempStr.length(); ++i)
	{
		frontStack.push(tempStr.at(i));
	}

	int N;
	cin >> N;

	while (N--)
	{
		char tempOrder;
		cin >> tempOrder;
		int tempNum;
		switch (tempOrder)
		{
		case 'L':
			if (!frontStack.empty())
			{
				tempNum = frontStack.top();
				frontStack.pop();
				backStack.push(tempNum);
			}
			break;
		case 'D':
			if (!backStack.empty())
			{
				tempNum = backStack.top();
				backStack.pop();
				frontStack.push(tempNum);
			}
			break;
		case 'B':
			if (!frontStack.empty())
			{
				frontStack.pop();
			}
			break;
		case 'P':
			char tempChar;
			cin >> tempChar;
			frontStack.push(tempChar);
			break;
		}
	}

	int lenA = frontStack.size();
	int lenB = backStack.size();
	for (int i = 0; i < lenA; ++i)
	{
		resultTemp[lenA - i - 1] = frontStack.top();
		frontStack.pop();
	}
	for (int i = 0; i < lenB; ++i)
	{
		resultTemp[lenA + i] = backStack.top();
		backStack.pop();
	}

	for (int i = 0; i < lenA + lenB; ++i)
	{
		cout << resultTemp[i];
	}
	cout << '\n';
	return 0;
}