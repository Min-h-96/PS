/* **************************************************************
    보석 쇼핑
************************************************************** */

#include <string>
#include <vector>
#include <set>
#include <unordered_map>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer(2);
    set<string> kinds(gems.begin(), gems.end());
    unordered_map<string, int> um;
    int min, start = 0, end = 0;
    
    for (const auto& g : gems) {
        um[g]++;
        if (um.size() == kinds.size())
            break;
        end++;
    }
    
    min = end - start;
    answer[0] = start + 1;
    answer[1] = end + 1;
    
    while (end < gems.size()) {
        string gem = gems[start];
        um[gem]--;
        start++;
        
        if(um[gem] == 0){
            end++;
            for(; end < gems.size(); end++){
                um[gems[end]]++;
                if(gem == gems[end])
                    break;
            }
            if(end == gems.size())
                break;
        }
        if(min > end - start){
            answer[0] = start + 1;
            answer[1] = end + 1;
            min = end - start;
        }
    }
        
    return answer;
}