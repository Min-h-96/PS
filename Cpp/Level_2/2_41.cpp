/* **************************************************************
    구명보트
************************************************************** */

#include <string>
#include <vector>
#include <algorithm>
#include <deque>
#include <iostream>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    deque<int> dq;
    
    sort(people.rbegin(), people.rend());
    for (const auto& p : people)
        dq.push_back(p);
    
    while (!dq.empty()) {
        int curPeoples = 0;
        while (curPeoples + dq.front() <= limit && !dq.empty()) {
            curPeoples += dq.front();
            dq.pop_front();
        }
        while (curPeoples + dq.back() <= limit && !dq.empty()) {
            curPeoples += dq.back();
            dq.pop_back();
        }
        answer++;
    }
    
    return answer;
}