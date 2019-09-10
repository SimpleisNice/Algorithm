#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    int strLen = s.length();
    int minSize = 10000;
    for(int i = 1; i <= strLen / 2; ++i)
    {
        string strPattern = s.substr(0, i);
        string tempResult = "";
        int patternCount = 0;
        for(int j = 0; j < strLen; j += i)
        {
            string tempPattern = s.substr(j, i);
            if(tempPattern == strPattern)
            {
                ++patternCount;
            }
            else
            {
                if(patternCount != 1)
                    tempResult += to_string(patternCount);
                tempResult += strPattern;
                
                patternCount = 1;
                strPattern = tempPattern;
            }    
        }
        if(tempResult.length() * 2 != strLen);
        {
            if(patternCount != 1)
                tempResult += to_string(patternCount);
            tempResult += strPattern;
        }
        
        if(minSize > tempResult.length())
            minSize = tempResult.length();
        
        tempResult = "";
    }
    answer = minSize;
    
    return answer;
}