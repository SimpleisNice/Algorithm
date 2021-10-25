
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
bool cmp(pair<int,int> temp_f, pair<int,int> temp_s)
{
    if(temp_f.first < temp_s.first)
        return true;
    if(temp_f.first == temp_s.first)
        if(temp_f.second <= temp_s.second)
            return true;
    return false;        
}
int main(void)
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;

    vector<pair<int,int>> temp_v(n);

    for(int i=0; i<n; ++i)
    {
        int num_a, num_b;
        cin >> num_a >> num_b;
        temp_v[i] = make_pair(num_a, num_b);
    }

    sort(temp_v.begin(), temp_v.end());

    for(auto it = temp_v.begin(); it != temp_v.end(); ++it)
    {
        cout << it->first << ' ' << it->second << '\n';
    }
    
    return 0;
}