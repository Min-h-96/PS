/* **************************************************************
    게임 맵 최단거리
************************************************************** */

#include <vector>
#include <queue>

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int solution(vector<vector<int>> maps) {
    vector<vector<int>> dist(101, vector<int>(101, 0));
    vector<vector<int>> board(101, vector<int>(101, 0));
    queue<pair<int, int>> q;
    
    for (int i=0; i<maps.size(); i++) {
        for (int j=0; j<maps[i].size(); j++)
            board[i][j] = maps[i][j];
    }
    
    int vertical = maps.size();
    int horizontal = maps[0].size();
    
    q.push({0, 0});
    dist[0][0] = 1;
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        for (int i=0; i<4; i++) {
            int nx = dx[i] + cur.first;
            int ny = dy[i] + cur.second;
            if (nx < 0 || ny < 0 || nx >= vertical || ny >= horizontal)
                continue;
            if (board[nx][ny] != 1 || dist[nx][ny] > 0)
                continue;
            q.push({nx, ny});
            dist[nx][ny] = dist[cur.first][cur.second] + 1;
        }
    }
    
    if (dist[vertical-1][horizontal-1] == 0)
        return -1;
    else
        return dist[vertical-1][horizontal-1];
}