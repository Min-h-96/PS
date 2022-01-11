/* **************************************************************
    실패율
************************************************************** */

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <stdio.h>

using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<double> failure_rate(N);
    int player;

    for (int i=1; i<N+1; i++) {
        player = 0;
        for (int j : stages)
            if (j == i)
                player++;
        if (stages.size() == 0 || player == 0)
            failure_rate[i-1] = 0;
        else
            failure_rate[i-1] = (double)player / (double)stages.size();
        stages.erase(remove(stages.begin(), stages.end(), i), stages.end());
    }
    for (int i=0; i<N; i++) {
        answer.push_back(max_element(failure_rate.begin(), failure_rate.end()) - failure_rate.begin() + 1);
        failure_rate[max_element(failure_rate.begin(), failure_rate.end()) - failure_rate.begin()] = -1;
    }
    return answer;
}