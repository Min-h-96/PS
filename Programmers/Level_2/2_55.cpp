/* **************************************************************
    [3차] 파일명 정렬
************************************************************** */

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(const string& a, const string& b) {
    // HEAD 정렬
    string a_HEAD = "", b_HEAD = "";
    int a_idx = -1, b_idx = -1;;
    while (++a_idx < a.length()) {
        if (isdigit(a[a_idx]))
            break;
        else {
            a_HEAD += tolower(a[a_idx]);
        }
    }
    
    while (++b_idx < b.length()) {
        if (isdigit(b[b_idx]))
            break;
        else
            b_HEAD += tolower(b[b_idx]);
    }
    
    if (a_HEAD != b_HEAD)
        return a_HEAD < b_HEAD;
    
    // NUMBER 정렬
    string a_NUM = "", b_NUM = "";
    for (int i=a_idx; i<a_idx+5; i++) {
        if (!isdigit(a[i]))
            break;
        a_NUM += a[i];
    }
    
    for (int i=b_idx; i<b_idx+5; i++) {
        if (!isdigit(b[i]))
            break;
        b_NUM += b[i];
    }
    
    int numA = stoi(a_NUM), numB = stoi(b_NUM);
    if (numA != numB)
        return numA < numB;
}

vector<string> solution(vector<string> files) {
    vector<string> answer = files;
    
    stable_sort(answer.begin(), answer.end(), cmp);
    
    return answer;
}