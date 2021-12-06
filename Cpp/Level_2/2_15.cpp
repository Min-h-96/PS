/* **************************************************************
    거리두기 확인하기
************************************************************** */

#include <string>
#include <vector>
#include <queue>

using namespace std;

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

bool BFS(int a, int b, vector<string> map) {
    vector<vector<bool>> visited(5, vector<bool>(5, false));
    queue<pair<pair<int, int>, int>> Q;
    Q.push(make_pair(make_pair(a, b), 0));
    visited[a][b] = true;
    
    while (!Q.empty()) {
        int x = Q.front().first.first;
        int y = Q.front().first.second;
        int cnt = Q.front().second;
        
        Q.pop();
        
        if (cnt == 2)
            continue;
        
        for (auto i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < 5 && ny < 5) {
                if (visited[nx][ny] == false) {
                    if (map[nx][ny] == 'O') {
                        visited[nx][ny] = true;
                        Q.push(make_pair(make_pair(nx, ny), cnt + 1));
                    } else if (map[nx][ny] == 'P')
                        return false;
                }
            }
        }
    }
    return true;
}

int check_map(vector<string> map) {
    for (auto i=0; i<map.size(); i++) {
        for (auto j=0; j<map.size(); j++) {
            if (map[i][j] == 'P' && BFS(i, j, map) == false)
                return 0;
        }
    }
    return 1;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for (auto p : places)
        answer.push_back(check_map(p));
    
    return answer;
}