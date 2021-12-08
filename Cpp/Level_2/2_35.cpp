/* **************************************************************
    피로도
************************************************************** */

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    vector<int> answers;
    
    sort(dungeons.begin(), dungeons.end());
    do {
        int fatigue = k;
        int entered = 0;
        for (auto d : dungeons) {
            if (fatigue < d[0])
                break;
            else {
                fatigue -= d[1];
                entered++;
            }
        }
        answers.push_back(entered);
        
    } while (next_permutation(dungeons.begin(), dungeons.end()));
    
    answer = *max_element(answers.begin(), answers.end());
    
    return answer;
}