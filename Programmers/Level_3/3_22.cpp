/* **************************************************************
    단어 변환
************************************************************** */

#include <string>
#include <vector>
#include <set>
#include <queue>
#include <iostream>

using namespace std;

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    set<string> s(words.begin(), words.end());
    queue<pair<string, int>> q; //int 는 변환된 횟수
    vector<set<char>> charset(begin.length(), set<char>()); //string 각 문자의 집합 -> 모든 알파벳을 비교하면 너무 오래걸리기 때문
    
    //target 이 words 에 없으면 0 을 return
    if (s.find(target) == s.end())
        return answer;
    
    //charset 세팅
    for (auto i=0; i<begin.length(); i++) {
        for (const auto& word : words)
            charset[i].insert(word[i]);
    }
    
    //큐에 begin 단어 push
    q.push({begin, 0});
    while (!q.empty()) {
        string curWord = q.front().first;
        int curCnt = q.front().second;
        q.pop();
        
        if (curWord == target) {
            answer = curCnt;
            break;
        }
        
        for (auto i=0; i<curWord.length(); i++) {
            string tmp = curWord;
            for (const auto& c : charset[i]) {
                tmp[i] = c;
                auto iter = s.find(tmp);
                if (iter != s.end()) {
                    q.push({tmp, curCnt + 1});
                    //변환되면서 이미 거쳐간 단어는 반복해서 체크하지 않도록 삭제
                    s.erase(iter);
                }
            }
        }
    }
    
    return answer;
}