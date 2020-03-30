#include <iostream>
#include <deque>
using namespace std;

int kData[10];
bool angles[361];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	deque<int> nData;
	cin >> n >> k;

	nData.resize(n);

	for (int i = 0; i < n; ++i)
	{
		cin >> nData[i];
		angles[nData[i]] = true;
	}
	for (int i = 0; i < k; ++i)
	{
		cin >> kData[i];
	}

	while(!nData.empty()) 
	{
		int num = nData.front();
		int len = nData.size();
		bool pushCheck = false;
		for(int i=0; i < len; ++i) 
		{
			if(!angles[(num + nData[i]) % 360])
			{
				angles[(num + nData[i]) % 360] = true;
				nData.push_back((num + nData[i]) % 360);
				pushCheck = true;
			}
			if(!angles[(360 + num - nData[i]) % 360])
			{
				angles[(360 + num - nData[i]) % 360] = true;
				nData.push_back((360 + num - nData[i]) % 360);
				pushCheck = true;
			}
		}
		if(!pushCheck)
			nData.pop_front();
	}
	for (int i = 0; i < k; ++i)
	{
		if (angles[kData[i]])
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}