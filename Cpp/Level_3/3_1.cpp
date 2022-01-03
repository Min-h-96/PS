/* **************************************************************
    [1차] 추석 트래픽
************************************************************** */

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<string> lines) {
    int answer = 0;
    vector<int> startT, endT;
    
    for (const auto& l : lines) {
        int h, m, s, ms, p_s;
        int p_ms = 0;
        h = stoi(l.substr(11, 2));
        m = stoi(l.substr(14, 2));
        s = stoi(l.substr(17, 2));
        ms = stoi(l.substr(20, 3));
        p_s = stoi(l.substr(24)) * 1000;
        if (l.length() > 26)
            p_ms = stoi(l.substr(26));
        
        int resTime = (h * 3600 + m * 60 + s) * 1000 + ms;
        endT.push_back(resTime);
        startT.push_back(resTime - p_s - p_ms + 1);
    }
    
    for (auto i=0; i<lines.size(); i++) {
        int endTime = endT[i] + 1000;
        int count = 0;
        
        for (auto j=i; j<lines.size(); j++) {
            if (startT[j] < endTime)
                count++;
        }
        answer = max(count, answer);
    }
    
    return answer;
}