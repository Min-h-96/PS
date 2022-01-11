/* **************************************************************
    수식 최대화
************************************************************** */

#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

bool isOperand(char c) {
    if (c == '*' || c == '+' || c == '-')
        return true;
    return false;
}

long long calculate(long long a, long long b, char op) {
    if (op == '*')
        return a * b;
    else if (op == '+')
        return a + b;
    else if (op == '-')
        return a - b;
}

long long solution(string expression) {
    long long answer = 0;
    string op = "*+-";
    vector<long long> answers;
    
    do {
        //expression 파싱
        vector<string> v;
        int numFirst = 0;
        for (auto i=0; i<expression.length(); i++) {
            if (i == expression.length()-1)
                v.push_back(expression.substr(numFirst));
            if (isOperand(expression[i])) {
                v.push_back(expression.substr(numFirst, i - numFirst));
                v.push_back(expression.substr(i, 1));
                numFirst = i + 1;
            }
        }
        
        //우선 순위 첫 번째 연산자 계산
        for (auto i=0; i<v.size()-1; i++) {
            if (v[i][0] == op[0]) {
                long long num = calculate(stoll(v[i-1]), stoll(v[i+1]), op[0]);
                v[i] = to_string(num);
                v.erase(v.begin() + i - 1);
                v.erase(v.begin() + i);
                i--;
            }
        }
        
        //우선 순위 두 번째 연산자 계산
        for (auto i=0; i<v.size()-1; i++) {
            if (v[i][0] == op[1]) {
                long long num = calculate(stoll(v[i-1]), stoll(v[i+1]), op[1]);
                v[i] = to_string(num);
                v.erase(v.begin() + i - 1);
                v.erase(v.begin() + i);
                i--;
            }
        }
        
        //우선 순위 세 번째 연산자 계산
        for (auto i=0; i<v.size()-1; i++) {
            if (v[i][0] == op[2]) {
                long long num = calculate(stoll(v[i-1]), stoll(v[i+1]), op[2]);
                v[i] = to_string(num);
                v.erase(v.begin() + i - 1);
                v.erase(v.begin() + i);
                i--;
            }
        }
        
        //결과 저장
        answers.push_back(abs(stoll(v[0])));
    } while (next_permutation(op.begin(), op.end()));
    
    answer = *max_element(answers.begin(), answers.end());
    
    return answer;
}