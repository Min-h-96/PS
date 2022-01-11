/* **************************************************************
    [3차] 방금그곡
************************************************************** */

#include <string>
#include <vector>
#include <sstream>
#include <deque>
#include <iostream>

using namespace std;

string solution(string m, vector<string> musicinfos) {
    string answer = "";
    vector<vector<string>> infos;
    
    for (const auto& music : musicinfos) {
        vector<string> info;
        string tmp;
        stringstream ss(music);
        while (getline(ss, tmp, ','))
            info.push_back(tmp);
        
        //재생시간 구하기
        auto i = info[0].find(':');
        int startHour = stoi(info[0].substr(0, i));
        int startMin = stoi(info[0].substr(i+1, 2));
        i = info[1].find(':');
        int endHour = stoi(info[1].substr(0, i));
        int endMin = stoi(info[1].substr(i+1, 2));
        info.push_back(to_string((endHour-startHour)*60 + (endMin-startMin)));
        
        //재생시간 동안 나온 멜로디 deque 에 넣기
        deque<char> melody;
        int idx = 0;
        for (auto i=0; i<(endHour-startHour)*60 + (endMin-startMin); i++) {
            if (idx == info[3].size())
                idx = 0;
            melody.push_back(info[3][idx++]);
            if (info[3][idx] == '#')
                melody.push_back(info[3][idx++]);
        }
        
        // 기억한 멜로디 확인
        idx = 0;
        while (!melody.empty()) {
            if (idx == m.length())
                infos.push_back(info);
            
            string rMelody, mMelody;
            rMelody.push_back(m[idx++]);
            if (m[idx] == '#')
                rMelody.push_back(m[idx++]);
            mMelody.push_back(melody.front());
            melody.pop_front();
            if (!melody.empty()) {
                if (melody.front() == '#') {
                    mMelody.push_back(melody.front());
                    melody.pop_front();
                }    
            }  
                
            if (rMelody != mMelody && idx != 0) {
                idx = 0;
                rMelody.clear();
                rMelody.push_back(m[idx++]);
                if (m[idx] == '#')
                    rMelody.push_back(m[idx++]);
                
                if (mMelody != rMelody)
                    idx = 0;
            }
                
        }
        if (idx == m.length())
            infos.push_back(info);
    }
    
    int maxPlay = 0;
    for (const auto& info : infos) {
        if (stoi(info[4]) > maxPlay) {
            maxPlay = stoi(info[4]);
            answer = info[2];
        }
    }
    
    if (answer.length() == 0)
        return "(None)";
    
    return answer;
}