/* **************************************************************
    올바른 괄호
************************************************************** */

#include <string>
#include <iostream>

using namespace std;

bool solution(string s) {
    bool answer = true;
    int Rcount = 0;
    int Lcount = 0;
    
    for (const auto& c : s) {
        if (c == '(')
            Lcount++;
        else if (c == ')')
            Rcount++;
        
        if (Rcount > Lcount) {
            answer = false;
            break;
        }
    }
    
    if (Rcount != Lcount)
        answer = false;

    return answer;
}