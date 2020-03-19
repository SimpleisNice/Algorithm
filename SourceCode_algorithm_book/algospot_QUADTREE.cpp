#include <iostream>
#include <string>

using namespace std;

string getStr(string treeStr)
{
	string resultStr[4];
	int pos = 0;

	for (int i = 0; i < 4; ++i)
	{
		string tempStr = "";
		if (treeStr[pos] == 'x')
		{
			tempStr = 'x' + getStr(treeStr.substr(pos + 1));
			resultStr[i] = tempStr;
			pos += tempStr.length();
		}
		else
		{
			resultStr[i] = treeStr[pos];
			++pos;
		}
	}
	return resultStr[2] + resultStr[3] + resultStr[0] + resultStr[1];
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int c;
	cin >> c;
	while (c--)
	{
		string tempStr = "", resultStr;
		cin >> tempStr;

		if (tempStr[0] == 'x')
		{
			resultStr = 'x' + getStr(tempStr.substr(1));
		}
		else
			resultStr = tempStr;

		cout << resultStr << "\n";
	}
	return 0;
}