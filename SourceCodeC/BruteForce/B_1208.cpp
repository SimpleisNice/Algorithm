#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int n,s;
    cin >> n >> s;

    vector<int> temp_v(n);

    for(int i=0; i<n; ++i)
    {
        cin >> temp_v[i];
    }

    int match_count = 0;
    for(int i=0; i<n; ++i)
    {
        int temp_sum = 0;

        for(int j=i; j>=0; --j)
        {
            temp_sum += temp_v[j];

            if(temp_sum == s)   ++match_count;
        }
    }
    cout << match_count;
    return 0;
}