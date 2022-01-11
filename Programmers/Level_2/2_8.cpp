/* **************************************************************
    더 맵게
************************************************************** */

#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue< int, vector<int>, greater<int> > pq;
    
    for (const auto& i : scoville)
        pq.push(i);
    
    while (!pq.empty() && pq.top() < K) {
        if (pq.size() == 1)
            return -1;
        
        int element1 = pq.top();
        pq.pop();
        int element2 = pq.top();
        pq.pop();
        pq.push(element1 + element2 * 2);
        answer++;
    }
    
    return answer;
}