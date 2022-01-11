/* **************************************************************
    영어 끝말이기
************************************************************** */

#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    map<string, int> saidWord;
    vector<int> player(n);
    int loser = 0;
    
    saidWord.insert({words[0], 1});
    player[0]++;
    for (auto i=1; i<words.size(); i++) {
        player[i % n]++;
        if (saidWord.find(words[i]) != saidWord.end()
           || words[i][0] != words[i-1][words[i-1].length()-1]) {
            loser = i % n + 1;
            break;
        } else
            saidWord.insert({words[i], 1});
    }
    
    if (loser == 0) {
        answer.push_back(0);
        answer.push_back(0);
    } else {
        answer.push_back(loser);
        answer.push_back(player[loser - 1]);
    }

    return answer;
}