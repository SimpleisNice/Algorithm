#include <iostream>
#include <vector>
using namespace std;

vector<int> room;
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;

    long long people_count = n;
    room.resize(n);

    while(true)
    {
        if(n == 0) break;
        cin >> room[n-1];
        --n;
    }

    int b, c;
    cin >> b >> c;
    for(auto it = room.begin(); it != room.end(); ++it)
    {
        int people = 0;
        if(*it - b > 0)
        {
            int mod = (*it - b) % c;
            int div = (*it - b) / c;

            if(mod == 0)
                people = div;
            else
                people = div + 1;
        }
        people_count += people;
    }
    cout << people_count << '\n';
}