/* **************************************************************
    카펫
************************************************************** */

#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <iostream>

using namespace std;

deque<int> divisors(int n) {
    deque<int> dq;

    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            dq.push_back(i);
            if (i * i != n)
                dq.push_back(n / i);
        }
    }
    return dq;
}

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    deque<int> dq = divisors(yellow);
    sort(dq.begin(), dq.end());
    while (!empty(dq)) {
        int width = dq.back();
        int height = dq.front();
        if (dq.size() == 1)
            dq.pop_front();
        else {
            dq.pop_front();
            dq.pop_back();
        }
        
        if ((width + 2) * 2 + (height * 2) == brown) {
            answer.push_back(width + 2);
            answer.push_back(height + 2);
            break;
        }
    }
    
    return answer;
}