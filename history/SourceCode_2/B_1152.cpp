#include <iostream>
#include <sstream>
#include <string>
#include <map>
using namespace std;

int main(void)
{
    map<string, int> tempMap;

    stringstream strStream;
    string tempStr, tempStr2;
    getline(cin, tempStr);

    strStream.str(tempStr);

    while(strStream >> tempStr2)
    {
        if(tempMap.find(tempStr2) == tempMap.end())
            tempMap.insert(make_pair(tempStr2, 1));
        else
            tempMap[tempStr2] += 1;
    }
    int totalSum = 0;
    for(auto it = tempMap.begin(); it != tempMap.end(); ++it)
    {
        totalSum += (*it).second;
    }
    cout << totalSum;
    return 0;
}