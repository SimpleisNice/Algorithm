#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> temp_v;

bool d[101];
int max_value = 0;
int n, k;

void Go(int w, int count, int sum)
{
    if (count == n || w == k)
    {
        if (max_value < sum)
            max_value = sum;
        return;
    }

    for (int i = 0; i < n; ++i)
    {
        if (d[i])
            continue;
        else
        {
            if (w + temp_v[i].first > k)
            {
                if (max_value < sum)
                    max_value = sum;
                return;
            }
            d[i] = true;
            Go(w + temp_v[i].first, count + 1, sum + temp_v[i].second);
        }
        d[i] = false;
    }
}
int main(void)
{
    cin >> n >> k;

    temp_v.resize(n);

    for (int i = 0; i < n; ++i)
    {
        int w, v;
        cin >> w >> v;
        temp_v[i].first = w;
        temp_v[i].second = v;
    }
    sort(temp_v.begin(), temp_v.end());

    Go(0, 0, 0);

    cout << max_value << '\n';
    return 0;
}