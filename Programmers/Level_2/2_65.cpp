/* **************************************************************
    JadenCase 문자열 만들기
************************************************************** */

#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";
    
    for (auto i=0; i<s.length(); i++) {
        if (s[i] == ' ')
            answer += " ";
        else {
            if (s[i-1] == ' ' || i == 0)
                answer.push_back(toupper(s[i]));
            else
                answer.push_back(tolower(s[i]));
        }
    }
    
    return answer;
}