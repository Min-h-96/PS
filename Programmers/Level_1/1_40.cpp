/* **************************************************************
    이상한 문자열 만들기
************************************************************** */

#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    int index = 0;
    
    for (string::iterator it=s.begin(); it!=s.end(); ++it) {
        if (*it == ' ') {
            index = 0;
            continue;
        }
        if (index % 2 == 0)
            *it = toupper(*it);
        else
            *it = tolower(*it);
        index++;
    }
    return s;
}