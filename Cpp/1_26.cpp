/* **************************************************************
    [1차] 다트 게임
************************************************************** */

#include <string>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iostream>

using namespace std;

int bonus_dart(int score, int bonus) {
    if (bonus == 'D')
        return pow(score, 2);
    else if (bonus == 'T')
        return pow(score, 3);
    else
        return score;
}

int solution(string dartResult) {
    int answer = 0;
    int current_score = 0;
    int before_score = 0;

    for (int i=0; i<dartResult.size(); i++) {
        if (isdigit(dartResult[i])) {
            answer += current_score;
            before_score = current_score;
            current_score = atoi(&dartResult[i]);
            if (current_score == 10)
                i++;
        }
        else if (dartResult[i] == 'S' || dartResult[i] == 'D' || dartResult[i] == 'T')
            current_score = bonus_dart(current_score, dartResult[i]);
        else if (dartResult[i] == '*') {
            current_score *= 2;
            answer += before_score;
        } else if (dartResult[i] == '#')
            current_score *= -1;
    }
    answer += current_score;
    return answer;
}