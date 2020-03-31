#include <vector>
#include <algorithm>

using namespace std;

bool cmpSecond(pair<int,int> tempA, pair<int,int> tempB) {
    if(tempA.second < tempB.second)
        return true;
    return false;
}


int solution(vector<int> food_times, long long k) {
    int answer = -1;
    int len = food_times.size();
    vector<pair<int,int>> tempV(len);
    
    for(int i=0; i<len; ++i)
    {
        tempV[i].first = i;
        tempV[i].second = food_times[i];
    }
    
    sort(tempV.begin(), tempV.end(), cmpSecond);
    
    int pos = 0;
    int tempFood = 0;
    long long tempK = 0;
    for(pos = 0; pos < len; ++pos)
    {
        long long num = tempV[pos].second - tempFood;
        if(tempK + num * (len - pos) <= k)
        {
            tempFood = tempV[pos].second;
            tempK += num * (len - pos);
            food_times[tempV[pos].first] = 0;
        }
        else
            break;
    }
       
    
    tempK = (k - tempK);
    
    if(len != pos)
        tempK %= (len - pos);
    int count = 0;
    for(int i=0; i<len; ++i)
    {
        if(food_times[i] == 0)
            continue;
        
        ++count;
        if(count == (tempK + 1))
        {
            answer = i + 1;
            break;
        }
    }

    return answer;
}