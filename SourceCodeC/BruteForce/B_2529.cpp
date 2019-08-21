#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <string>

using namespace std;

vector<int> useNum(10);
vector<int> setNum;
vector<char> inequality;
void SettingNum(int K)
{
	for (int i = 0; i < K + 1; ++i)
	{
		useNum[i] = 1;
	}

	for (int i = K + 1; i < 10; ++i)
	{
		useNum[i] = 0;
	}
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int K;
	string maxValue = "0";
	string minValue = "99999";

	cin >> K;
	inequality.resize(K);
	setNum.resize(K + 1);

	for (int i = 0; i < K; ++i)
	{
		cin >> inequality[i];
	}
	SettingNum(K);

	do
	{
		int temp = 0;
		for (int i = 0; i < 10; ++i)
		{
			if (useNum[i] == 1)
				setNum[temp++] = i;
		}
		do
		{
			string tempStr = "";
            bool check = true;
			for (int i = 0; i < K; ++i)
			{
				if (inequality[i] == '<')
				{
					if (setNum[i] > setNum[i + 1])
					{   
                        check = false;
                        break;
                    }
				}
				else
				{
					if (setNum[i] < setNum[i + 1])
					{
                        check = false;
                        break;
                    }
				}
				tempStr += to_string(setNum[i]);
			}
            if(check)
			{    
                tempStr += to_string(setNum[K]);
                if (minValue > tempStr)
			    {
			    	minValue = tempStr;
			    }
			    if (maxValue < tempStr)
			    {
			    	maxValue = tempStr;
			    }
            }
		} while (next_permutation(setNum.begin(), setNum.end()));

	} while (prev_permutation(useNum.begin(), useNum.end()));

    cout << maxValue << '\n' << minValue << '\n';
	return 0;
}