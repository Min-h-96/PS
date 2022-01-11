/* **************************************************************
    입국심사
************************************************************** */

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    sort(times.begin(), times.end());
    long long answer = times[times.size() - 1] * n;
    unsigned long long low = 1;
    unsigned long long high = times[times.size() - 1] * n;
    
    while (low <= high) {
        long long mid = (low + high) / 2;
        long long cnt = 0;
        
        for (const auto& t : times)
            cnt += mid / t;
        
        if (cnt >= n) {
            answer = min(answer, mid);
            high = mid - 1;
        } else
            low = mid + 1;
    }
    
    return answer;
}