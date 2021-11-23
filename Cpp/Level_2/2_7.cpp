/* **************************************************************
    기능 개발
************************************************************** */

#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;
    int val = 0;
    int count = 1;
    
    for (int i=0; i<progresses.size(); i++) {
        if ((100 - progresses[i]) % speeds[i] != 0)
            q.push((100 - progresses[i]) / speeds[i] + 1);
        else
            q.push((100 - progresses[i]) / speeds[i]);
    }
    
    while (!q.empty()) {
        if (count == 1)
            val = q.front();
        q.pop();
        if (val < q.front() || q.empty()) {
            answer.push_back(count);
            count = 1;
        } else
            count++;
    }
    
    return answer;
}