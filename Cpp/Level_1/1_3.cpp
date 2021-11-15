/* **************************************************************
    숫자 문자열과 영단어
************************************************************** */

#include <string>
#include <vector>
#include <regex>

/*
regex_replace 를 활용한 문자열 치환 방법
*/

using namespace std;

int solution(string s) {
    int answer = 0;
    s = regex_replace(s, regex("zero"), "0");
    s = regex_replace(s, regex("one"), "1");
    s = regex_replace(s, regex("two"), "2");
    s = regex_replace(s, regex("three"), "3");
    s = regex_replace(s, regex("four"), "4");
    s = regex_replace(s, regex("five"), "5");
    s = regex_replace(s, regex("six"), "6");
    s = regex_replace(s, regex("seven"), "7");
    s = regex_replace(s, regex("eight"), "8");
    s = regex_replace(s, regex("nine"), "9");
    answer = stoi(s);
    return answer;
}

/*
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    string num = "";

    for (int i=0; i<s.length(); i++) {
        if (isdigit(s[i])) num.push_back(s[i]);
        else if (s[i] == 'z') {
            num.push_back('0');
            i += 3;
        } else if (s[i] == 'o') {
            num.push_back('1');
            i += 2;
        } else if (s[i] == 't') {
            if (s[i + 2] == 'r') {
                num.push_back('3');
                i += 2;
            } else num.push_back('2');
            i += 2;
        } else if (s[i] == 'f') {
            if (s[i + 1] == 'o') num.push_back('4');
            else num.push_back('5');
            i += 3;
        } else if (s[i] == 's') {
            if (s[i + 2] == 'v') {
                num.push_back('7');
                i += 2;
            } else num.push_back('6');
            i += 2;
        } else if (s[i] == 'e') {
            num.push_back('8');
            i += 4;
        } else if (s[i] == 'n') {
            num.push_back('9');
            i += 3;
        }
    }
    answer = stoi(num);
    return answer;
}
*/