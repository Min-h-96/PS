/* **************************************************************
    후보키
************************************************************** */

#include <string>
#include <vector>
#include <map>
#include <deque>
#include <algorithm>
#include <iostream>

using namespace std;

bool comp(const string& a, const string& b) {
    return a.length() < b.length();
}

int solution(vector<vector<string>> relation) {
    int answer = 0;
    vector<int> checkIndex;
    
    // 본인만으로 후보키가 되는 속성 제외
    for (auto j=0; j<relation[0].size(); j++) {
        map<string, int> m;
        for (auto i=0; i<relation.size(); i++) {
            if (m.find(relation[i][j]) == m.end())
                m.insert({relation[i][j], 1});
        }
        
        if (m.size() != relation.size())
            checkIndex.push_back(j);
        else
            answer++;
    }
    
    deque<string> candidates;
    for (auto i=2; i<=checkIndex.size(); i++) {
        vector<bool> checked(checkIndex.size() - i, false);
        for (auto j=0; j<i; j++)
            checked.push_back(true);
        
        do {
            // 속성을 합쳐서 새로운 속성 만들기
            vector<string> newRelation(relation.size());
            string newIndex;
            for (auto j=0; j<checked.size(); j++) {
                if (checked[j] == true) {
                    for (auto k=0; k<relation.size(); k++)
                        newRelation[k] += relation[k][checkIndex[j]] + "|";
                    newIndex += to_string(checkIndex[j]);
                }
            }
            
            //후보키가 될 수 있는 속성인지 map 컨테이너로 확인
            map<string, int> m;
            for (auto j=0; j<newRelation.size(); j++) {
                if (m.find(newRelation[j]) == m.end())
                    m.insert({newRelation[j], 1});
            }
            if (m.size() == newRelation.size())
                candidates.push_back(newIndex);
        } while (next_permutation(checked.begin(), checked.end()));
    }
    
    if (candidates.empty())
        return answer;
    
    sort(candidates.begin(), candidates.end(), comp);
    
    while (!candidates.empty()) {
        string tmp = candidates.front();
        candidates.pop_front();
        answer++;
        
        int count = candidates.size();
        for (auto i=0; i<count; i++) {
            int idx = -1;
            while (++idx < tmp.length()) {
                size_t found = candidates.front().find(tmp[idx]);
                if (found == string::npos)
                    break;
            }
            
            if (idx != tmp.length())
                candidates.push_back(candidates.front());
            candidates.pop_front();
        }
    }
    
    
    return answer;
}