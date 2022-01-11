/* **************************************************************
    이진 변환 반복하기
************************************************************** */

#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int zeroCnt = 0;
    int conversionCnt = 0;
    
    deque<char> dq;
    for (const auto& c : s)
        dq.push_back(c);
    
    while (dq.size() > 1) {
		// 0을 지우기 쉽도록 정렬
        sort(dq.begin(), dq.end());

		// 0 제거
        while (dq.front() == '0') {
            dq.pop_front();
            zeroCnt++;
        }

	    // 0 이 지워진 새로운 수의 길이 이진 변환 시키기
        int newLen = dq.size();
        dq.clear();
        while (newLen > 0) {
            if (newLen % 2 == 1)
                dq.push_front('1');
            else
                dq.push_front('0');
            newLen /= 2;
        }

		// 변환 횟수 체크
        conversionCnt++;
    }
    
    answer.push_back(conversionCnt);
    answer.push_back(zeroCnt);
    
    return answer;
}