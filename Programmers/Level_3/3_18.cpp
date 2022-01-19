/* **************************************************************
    금과 은 운반하기
************************************************************** */

#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

long long solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t) {
    long long answer = 1e9 * 2 * 1e5 * 2;
    long long start = 0, end = 1e9 * 2 * 1e5 * 2;
    
    while (start <= end) {
        long long mid = (start + end) / 2;
        
        // mid 시간 동안 각 도시가 옮길 수 있는 최대 양을 구하기
        long long carryG = 0, carryS = 0, carryTotal = 0;
        for (auto i=0; i<g.size(); i++) {
            long long nowG = g[i] * 1LL;
            long long nowS = s[i] * 1LL;
            long long nowW = w[i] * 1LL;
            
            long long cnt = mid / (2 * t[i]);
            if (mid % (2 * t[i]) >= t[i] * 1LL)
                cnt += 1;
            
            carryG += (nowG < cnt * w[i]) ? nowG : cnt * w[i];
            carryS += (nowS < cnt * w[i]) ? nowS : cnt * w[i];
            carryTotal += (nowG + nowS < cnt * w[i]) ? nowG + nowS : cnt * w[i];
        }
        
        if (carryG >= a && carryS >= b && carryTotal >= a + b) {
            end = mid - 1;
            answer = min(mid, answer);
        } else
            start = mid + 1;
    }
    
    return answer;
}