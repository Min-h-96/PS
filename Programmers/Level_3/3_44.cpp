/* **************************************************************
    가장 긴 팰린드롬
************************************************************** */

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int solution(string s) {
    int answer = 0;
    s += '1';
    
    for (int i=1; i<s.size(); i++) {
        int left = i - 1, right = i + 1;
        int odd = 1, even = 0;
        bool flag1 = true, flag2 = true;
        
        while (left>=0 && right<s.size()) {
            //홀수개의 팰린드롬
            if (s[left] == s[right] && flag1)
                odd += 2;
            else
                flag1 = false;
            
            //짝수개의 팰린드롬
            if (s[left] == s[right-1] && flag2)
                even += 2;
            else
                flag2 = false;
            
            if (!flag1 && !flag2)
                break;
            left--;
            right++;
        }
        int result = max(odd, even);
        answer = max(answer, result);
    }
    
    return answer;
}