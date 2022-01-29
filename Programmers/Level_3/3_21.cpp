/* **************************************************************
    등굣길
************************************************************** */

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int MOD = 1000000007;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    vector<vector<int>> board(n+1, vector<int>(m+1, 0));
    
    for (const auto& p : puddles)
        board[p[1]][p[0]] = -1;
    
    board[1][1] = 1;
    for (auto i=1; i<=n; i++) {
        for (auto j=1; j<=m; j++) {
            if (board[i][j] == -1) //물에 잠긴 지역 건너뜀
                continue;
            if (i == 1 && j == 1) //출발지는 건너뜀
                continue;
            
            int up = 0, left = 0;
            //물에 잠긴 지역인 경우는 갈 수 없음을 조건에 표시
            if (board[i-1][j] != -1)
                up = board[i-1][j];
            if (board[i][j-1] != -1)
                left = board[i][j-1];
            
            board[i][j] = ((up % MOD) + (left % MOD)) % MOD;
        }
    }
    
    answer = board[n][m];
    
    return answer;
}