/* **************************************************************
    프린터
************************************************************** */

#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    deque<pair<int, int>> dq;
    
    for(int i=0; i<priorities.size(); i++)
        dq.push_back({priorities[i], i});
    
    sort(priorities.rbegin(), priorities.rend());
    int cur_priority = 0;
    
    while (!dq.empty()) {
        if (dq.front().first == priorities[cur_priority]) {
            int cur_loc = dq.front().second;
            dq.pop_front();
            cur_priority++;
            answer++;
            if (cur_loc == location)
                break;
        } else {
            dq.push_back(dq.front());
            dq.pop_front();
        }
    }
    
    return answer;
}