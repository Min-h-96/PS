/* **************************************************************
    정수 삼각형
************************************************************** */

#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool> checked(n, false);
    
    for (auto i=0; i<n; i++) {
        if (checked[i] == true)
            continue;
        
        queue<int> q;
        q.push(i);
        answer++;
        
        while (!q.empty()) {
            int curComputer = q.front();
            q.pop();
            
            for (auto j=0; j<n; j++) {
                if (computers[curComputer][j] == 1) {
                    if (checked[j] == false) {
                        checked[j] = true;
                        q.push(j);
                    }
                }
            }
        }
    }
    
    return answer;
}