/* **************************************************************
    순위
************************************************************** */

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    vector<vector<bool>> graph(n+1, vector<bool>(n+1, false));
    
    // results 의 승패 결과 적용
    for (const auto& r : results) {
        int winner = r[0];
        int loser = r[1];
        graph[winner][loser] = true;
    }
    
    // 플로이드 와샬 알고리즘 적용
    for (auto k=1; k<=n; k++) {
        for (auto i=1; i<=n; i++) {
            for (auto j=1; j<=n; j++) {
                if (graph[i][k] && graph[k][j])
                    graph[i][j] = true;
            }
        }
    }
    
    for (auto i=1; i<=n; i++) {
        int winCnt = 0;
        for (auto j=1; j<=n; j++) {
            if (graph[i][j] || graph[j][i])
                winCnt++;
        }
        if (winCnt == n-1)
            answer++;
    }
    
    return answer;
}