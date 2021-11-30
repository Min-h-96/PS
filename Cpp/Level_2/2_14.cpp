/* **************************************************************
    [1차] 뉴스 클러스터링
************************************************************** */

#include <string>
#include <map>
#include <algorithm>
#include <cctype>
#include <iostream>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    map<string, int> A, B;
    
    //대소문자 구분 없애기
    for (auto &s : str1)
        s = toupper(s);
    for (auto &s : str2)
        s = toupper(s);
    
    //두 글자씩 끊어서 다중 집합 만들기
    for (auto i=0; i<str1.size()-1; i++) {
        string s = str1.substr(i, 2);
        if (isalpha(s[0]) && isalpha(s[1])) {
            if (A.find(s) != A.end())
                A[s]++;
            else
                A.insert(pair<string, int>(s, 1));
        }
    }
    for (auto i=0; i<str2.size()-1; i++) {
        string s = str2.substr(i, 2);
        if (isalpha(s[0]) && isalpha(s[1])) {
            if (B.find(s) != B.end())
                B[s]++;
            else
                B.insert(pair<string, int>(s, 1));
        }
    }
    
    //집합 A와 B 가 모두 공집합일 때 유사도는 1
    if (A.empty() && B.empty())
        return 1 * 65536;
    
    //집합 A 와 B 의 원소 개수 구하기
    int num1 = 0;
    for (const auto &m : A)
        num1 += m.second;
    int num2 = 0;
    for (const auto &m : B)
        num2 += m.second;
    
    //교집합 원소 개수 구하기
    int similar = 0;
    for (const auto &m : A) {
        if (B.find(m.first) != B.end()) {
            if (B[m.first] > m.second)
                similar += m.second;
            else
                similar += B[m.first];
        }
    }
    
    //자카드 유사도 구하기
    answer = similar * 65536 / (num1 + num2 - similar);
    
    return answer;
}