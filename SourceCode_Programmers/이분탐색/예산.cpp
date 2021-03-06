#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> budgets, int M) {
    int answer = 0;
    int totalSum = 0;
    int budgetsSize = budgets.size();
    
    sort(budgets.begin(), budgets.end());
    
    for(int i=0; i<budgetsSize; ++i)
    {
        totalSum += budgets[i];
    }
    
    if(totalSum <= M)
        answer = budgets[budgetsSize - 1];
    else
    {
        int start = M / budgetsSize;
        int end =  totalSum / budgetsSize;
        
        if(start > end)
        {
            int tempNum = start;
            start = end;
            end = tempNum;
        }
        
        int maxBudget = 0;
        while(true)
        {
            int tempPos = (start + end) / 2;
            int tempSum = 0;
            bool checkValue = false;
            
            
            for(int i=0; i<budgetsSize; ++i)
            {
                if(tempPos > budgets[i])
                    tempSum += budgets[i];
                else
                    tempSum += tempPos;
                
                if(tempSum > M)
                {
                    checkValue = true;
                    break;
                }
            }
            
            if(checkValue)
            {
                end = tempPos - 1;
                continue;
            }
            else
            {
                start = tempPos + 1;
            }
            
            if(maxBudget >= tempPos)
                break;
            maxBudget = tempPos;
        }
        
        answer = maxBudget;        
    }
    return answer;
}
