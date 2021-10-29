#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int checkScore(vector<int> sheet ,vector<int> answers) {
    int ret = 0;
    int idx = 0;
    
    for (int i : answers) {
        if (i == sheet[idx])
            ret++;
        idx++;
        if (idx == sheet.size())
            idx = 0;
    }
    return ret;
}

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> score;
    int max_score = -1;

    score.push_back(checkScore({1, 2, 3, 4, 5}, answers));
    score.push_back(checkScore({2, 1, 2, 3, 2, 4, 2, 5}, answers));
    score.push_back(checkScore({3, 3, 1, 1, 2, 2, 4, 4, 5, 5}, answers));  
    for (int i=0; i<3; i++) {
        if (*max_element(score.begin(), score.end()) >= max_score) {
            max_score = *max_element(score.begin(), score.end());
            answer.push_back(max_element(score.begin(), score.end()) - score.begin() + 1);
            score[max_element(score.begin(), score.end()) - score.begin()] = -1;
        }
        else
            break;
    }
    return answer;
}