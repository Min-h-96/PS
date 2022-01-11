/* **************************************************************
    괄호 변환
************************************************************** */

#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool check(string str) {
    int tmp = 0;

    for (const auto& c : str) {
        if (c == '(')
            tmp++;
        else {
            tmp--;
        }
        if (tmp < 0)
            return false;
    }
    return true;
}

string recursive(string p) {
    string u, v;
    int Lcount = 0, Rcount = 0;
    
    if (p == "")
        return p;
    
    for (auto i=0; i<p.length(); i++) {
        if (p[i] == '(')
            Lcount++;
        else
            Rcount++;
        if (Lcount == Rcount) {
            u = p.substr(0, i+1);
            v = p.substr(i+1);
            break;
        }
    }
    
    if (check(u))
        return u + recursive(v);
    else {
        string tmp = "(";
        tmp += recursive(v) + ")";
        u = u.substr(1, u.length() - 2);
        for (auto& i : u) {
            if (i == '(')
                i = ')';
            else
                i = '(';
        }
        tmp += u;
        return tmp;
    }
}

string solution(string p) {
    string answer = "";
    
    if (check(p))
        return p;
    
    answer = recursive(p);
    
    return answer;
}