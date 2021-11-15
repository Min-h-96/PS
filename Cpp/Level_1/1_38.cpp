/* **************************************************************
    시저 암호
************************************************************** */

#include <string>
#include <vector>
#include <stdio.h>

using namespace std;

char pushChar(char c, int n) {
    if (c == ' ')
        return (c);
    if (c >= 'a' && c + n > 'z') {
        n = n + c - 'z' - 1;
        c = 'a';
    }
    if (c >= 'A' && c + n > 'Z' && c < 'a') {
        n = n + c - 'Z' - 1;
        c = 'A';
    }
    c = c + n;
    return (c);
}

string solution(string s, int n) {
    string answer = "";
    
    for (auto c : s) {
        answer += pushChar(c, n);
    }

    return answer;
}