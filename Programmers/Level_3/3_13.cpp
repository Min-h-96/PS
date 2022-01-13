/* **************************************************************
    [1차] 셔틀버스
************************************************************** */

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string writeTime(int hour, int min) {
    string time;
    
    if (hour < 10)
        time += "0" + to_string(hour) + ":";
    else
        time += to_string(hour) + ":";
        
    if (min < 10)
        time += "0" + to_string(min);
    else
        time += to_string(min);
    
    return time;
}

bool cmp(const string& a, const string& b) {
    int hourA = stoi(a.substr(0,2));
    int minA = stoi(a.substr(3,2));
    int hourB = stoi(b.substr(0, 2));
    int minB = stoi(b.substr(3, 2));
    
    if (hourA == hourB)
        return minA < minB;
    return hourA < hourB;
}

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    
    vector<pair<pair<int, int>, vector<pair<int, int>>>> busTime;
    
    //timetable 먼저 타는 사람 순으로 정렬
    sort(timetable.begin(), timetable.end(), cmp);
    
    // 버스 시간표 정리
    for (auto i=0; i<n; i++) {
        int hour = 9 + (t * i)/60;
        int min = (t * i) % 60;
        
        busTime.push_back({{hour, min}, vector<pair<int, int>>()});
    }
    
    // 버스 별 타는 사람 정리
    for (const auto& time : timetable) {
        int hour = stoi(time.substr(0, 2));
        int min = stoi(time.substr(3, 2));
        
        for (auto& bus : busTime) {
            // 버스의 출발 hour가 타는 사람의 도착 hour 보다 빠르면 다음 버스 확인
            if (bus.first.first < hour)
                continue;
            else {
                // 버스의 출발 min 이 타는 사람의 도착 min 보다 빠르면 다음 버스 확인
                if (bus.first.first == hour && bus.first.second < min)
                    continue;
                // 탑승 시간은 문제 없지만, 이미 꽉찬 버스인 경우
                if (bus.second.size() < m) {
                    bus.second.push_back({hour, min});
                    break;
                }
            }
        }
    }
    
    // 마지막 버스에 자리가 여유있는 경우
    if (busTime[n-1].second.size() < m) {
        int hour = busTime[n-1].first.first;
        int min = busTime[n-1].first.second;
        
        answer = writeTime(hour, min);
    } else { // 마지막 버스가 꽉찬 경우
        int hour = busTime[n-1].second[busTime[n-1].second.size()-1].first;
        int min = busTime[n-1].second[busTime[n-1].second.size()-1].second;
        
        if (min == 0) {
            min = 59;
            hour--;
        } else
            min--;
        
        answer = writeTime(hour, min);
    }
    
    return answer;
}