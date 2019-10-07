#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;
bool cmp(tuple<int, int, string> tempA, tuple<int, int, string> tempB)
{
    int time[2], age[2];
    string name[2];

    tie(time[0], age[0], name[0]) = tempA;
    tie(time[1], age[1], name[1]) = tempB;
    
    if(age[0] > age[1])
        return false;
    else if(age[0] == age[1])
    {
        if(time[0] > time[1])
            return false;
    }
    return true;
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int num;
    cin >> num;
    vector<tuple<int, int, string>> tempVector(num);

    for(int i = 0; i < num; ++i)
    {
        int age;
        string name;
        cin >> age >> name;
        tempVector[i] = make_tuple(i, age, name);
    }

    sort(tempVector.begin(), tempVector.end(), cmp);
    int time, age; string name;

    for(auto it = tempVector.begin(); it != tempVector.end(); ++it)
    {
        tie(time, age, name) = *it;
        cout << age << " " << name << '\n';
    }
    

    return 0;
}