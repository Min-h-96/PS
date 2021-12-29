/* **************************************************************
    [3차] n진수 게임
************************************************************** */

#include <string>
#include <vector>
#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

// next_permutation 을 이용한 풀이
int solution(int n) {
    int answer = 0;
    deque<int> dq;
    
    while (n > 0) {
        dq.push_front(n % 2);
        n /= 2;
    }
    dq.push_front(0);
    
    next_permutation(dq.begin(), dq.end());
    
    while (!dq.empty()) {
        answer *= 2;
        answer += dq.front();
        dq.pop_front();
    }
    
    return answer;
}

/*
비트 마스크를 이용한 풀이
#include <string>
#include <vector>

using namespace std;

int countOne(int n){
    int ret=0;
    // n의 이진수에서 1의 개수 세기
    for(int i=0 ; i < 31 ; i++){
        if(n & 0x01<<i)
            ret++;
    }
    return ret;
}

int solution(int n) {
    int standard = countOne(n);
    
    while(1){
        n++;
        if(standard == countOne(n))
            return n;
    }
}
*/