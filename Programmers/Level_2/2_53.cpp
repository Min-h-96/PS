/* **************************************************************
    가장 큰 정사각형 찾기
************************************************************** */

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int dx[3] = {-1, 0, -1};
int dy[3] = {0, -1, -1};

int solution(vector<vector<int>> board) {
    int answer = 0;
    vector<vector<int>> checked(board.size(), vector<int>(board[0].size(), 0));
    int maxVal = 0;
    
    for (int y=0; y<board.size(); y++) {
        for (int x=0; x<board[0].size(); x++) {
            if (x == 0 || y == 0 || board[y][x] == 0) {
                checked[y][x] = board[y][x];
                maxVal = max(maxVal, checked[y][x]);
                continue;
            }
            
            int minVal = 1001;
            for (auto i=0; i<3; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                minVal = min(minVal, checked[ny][nx]);
            }
            checked[y][x] = minVal + 1;
            maxVal = max(maxVal, checked[y][x]);
        }
    }
    
    answer = pow(maxVal, 2);
    
    return answer;
}