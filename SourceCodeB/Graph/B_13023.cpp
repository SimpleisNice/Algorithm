#include <iostream>
#include <vector>

using namespace std;

vector<int> tempV[2001];
bool check[2001];
int cnt = 1;
int N, M;
bool result;
void DFS(int temp)
{
	check[temp] = true;
    for(int i = 0; i < tempV[temp].size(); ++i)
    {
		int num = tempV[temp][i];
		if(!check[num])
		{
			DFS(num);
			cnt++;
		}
    }
	
	if(cnt == N)
    {
        result = true;
        return;
    }	
}
int main(void)
{
    cin >> N >> M;

    for(int i = 0; i < M; ++i)
    {
        int tempA, tempB;
        cin >> tempA >> tempB;

        tempV[tempA].push_back(tempB);
        tempV[tempB].push_back(tempA);
    }

	DFS(0);

	cout << cnt << endl;
	int temp = result ? 1 : 0;
    cout << temp << '\n';
    return 0;
}