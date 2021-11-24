/* **************************************************************
    짝지어 제거하기
************************************************************** */

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int solution(string s) {
    int answer = 0;
    stack<char> stk;

    for (int i=0; i<s.size(); i++) {
        if (stk.empty()) {
            stk.push(s[i]);
            continue;
        }
        if (stk.top() == s[i])
            stk.pop();
        else
            stk.push(s[i]);
    }
    if (stk.empty())
        answer = 1;
    
    return answer;
}