/* **************************************************************
    괄호 회전하기
************************************************************** */

#include <string>
#include <vector>
#include <deque>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = 0;
    deque<char> d;
    
    for (const auto&c : s)
        d.push_back(c);
        
    for (auto i=0; i<s.length(); i++) {
        deque<char> tmp = d;
        deque<char> check;
        
        while (!tmp.empty()) {
            if (check.empty()) {
                check.push_back(tmp.front());
                tmp.pop_front();
                continue;
            }
            
            if ((tmp.front() == ']' && check.back() == '[')
                || (tmp.front() == '}' && check.back() == '{')
                || (tmp.front() == ')' && check.back() == '(')) {
                tmp.pop_front();
                check.pop_back();
            } else {
                check.push_back(tmp.front());
                tmp.pop_front();
            }
        }
        
        if (check.empty())
            answer++;
        
        d.push_back(d.front());
        d.pop_front();
    }
    
    return answer;
}