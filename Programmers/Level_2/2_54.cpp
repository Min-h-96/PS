/* **************************************************************
    [3차] 압축
************************************************************** */

#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    unordered_map<string, int> dict;
    int index = 1;
    
    for (int i=0; i<26; i++) {
        char c = 'A' + i;
        string s(1, c);
        dict.insert({s, index++});
    }
    
    string curStr;
    for (auto i=0; i<msg.size(); i++) {
        string beforeStr = curStr;
        curStr.push_back(msg[i]);
        
        if (dict.find(curStr) != dict.end()) {
            if (i == msg.size() - 1)
                answer.push_back(dict[curStr]);
            continue;
        } else {
            dict.insert({curStr, index++});
            answer.push_back(dict[beforeStr]);
            i--;
            curStr.clear();
            beforeStr.clear();
        }
    }
    
    return answer;
}