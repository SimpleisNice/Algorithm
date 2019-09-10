#include <string>
#include <vector>
#include <regex>
using namespace std;

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    for(int i = 0; i < queries.size(); ++i)
    {
        string tempQuery = "(" + queries[i].substr(0, queries[i].find("?")) + ")(.*)";
        regex e (tempQuery);
        
        int tempCount = 0;
        for(int j = 0; j < words.size(); ++j)
        {
            if(regex_match(words[i], e))
                ++tempCount;
        }
        answer.push_back(tempCount);
    }
    return answer;
}


int main(void)
{
    vector<string> 
}