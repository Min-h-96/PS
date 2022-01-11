/* **************************************************************
    위장
************************************************************** */

#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int> hash;
    
    for (const auto& cloth : clothes) {
        if (hash.find(cloth[1]) != hash.end())
            hash[cloth[1]]++;
        else
            hash.insert(pair<string, int>(cloth[1], 1));
    }
    
    for (const auto& h : hash)
        answer *= h.second + 1;
    answer -= 1;
    
    return answer;
}