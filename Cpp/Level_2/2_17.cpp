/* **************************************************************
    튜플
************************************************************** */

#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    map<string, int> m;
    
    for (auto i=0; i<s.length(); i++) {
        if (isdigit(s[i])) {
            int num = stoi(s.substr(i));
            if (m.find(to_string(num)) != m.end())
                m[to_string(num)]++;
            else
                m.insert(pair<string, int>(to_string(num), 1));
            i += to_string(num).length();
        }       
    }
    
    for (auto i=0; i<m.size(); i++) {
        //가장 많이 특정 튜플로 호출된 값 찾기
        auto max = *max_element(m.begin(), m.end(),
            [](const pair<string, int>& p1, const pair<string, int>& p2) {
                return p1.second < p2.second; });
        
        answer.push_back(stoi(max.first));
        m[max.first] = -1;
    }
    
    return answer;
}