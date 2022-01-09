/* **************************************************************
    디스크 컨트롤러
************************************************************** */

#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <numeric>
#include <iostream>

using namespace std;

struct cmp{
    bool operator()(const pair<int, int>& a, const pair<int, int>& b){
        return a.second > b.second;
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq; // 현재 시간까지 요청된 job
    queue<pair<int, int>> jobList; //전체 job 리스트
    vector<int> times;
    
    sort(jobs.begin(), jobs.end());
    for (const auto& j : jobs)
        jobList.push({j[0], j[1]});
    
    pq.push(jobList.front());
    jobList.pop();
    
    int curTime = pq.top().first;
    while (!pq.empty()) {
        int reqTime = pq.top().first;
        int operTime = pq.top().second;
        
        times.push_back(operTime + curTime - reqTime);
        curTime = operTime + curTime;
        pq.pop();
        while (jobList.front().first < curTime && !jobList.empty()) {
            pq.push(jobList.front());
            jobList.pop();
        }
        
        // 현재 시간에 요청된 job 은 다 처리했는데 아직 전체 job 리스트에 job 이 남은 경우
        if (pq.empty() && !jobList.empty()) {
            curTime = jobList.front().first;
            pq.push(jobList.front());
            jobList.pop();
        }
    }
    
    answer = accumulate(times.begin(), times.end(), 0) / times.size();
    
    return answer;
}