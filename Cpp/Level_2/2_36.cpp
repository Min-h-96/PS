/* **************************************************************
    [1차] 프렌즈4블록
************************************************************** */

#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

char Map[31][31];
int dx[4] = {0, 1, 0, 1};
int dy[4] = {0, 0, 1, 1};

int isDelete(int x, int y) {
    char curChar = Map[y][x];
    
    if (curChar == '-')
        return (0);
    
    for (int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (curChar != Map[ny][nx])
            return (0);
    }
    return (1);
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    map<pair<int, int>, int> deletedBlock;
    
    for (auto i=0; i<m; i++) {
        for (auto j=0; j<n; j++)
            Map[i][j] = board[i][j];
    }
    
    while (1) {
        // 지워져야 하는 블록 찾기
        for (auto y=0; y<m-1; y++) {
            for (auto x=0; x<n-1; x++) {
                if (isDelete(x, y)) {
                    for (int i=0; i<4; i++) {
                        int nx = x + dx[i];
                        int ny = y + dy[i];
                        if (deletedBlock.find({nx, ny}) == deletedBlock.end())
                            deletedBlock.insert({{nx, ny}, 1});
                    }
                }
            }
        }
        
        // 지워야 할 블록이 없으면 종료
        if (deletedBlock.empty())
            return answer;
        
        // 블록 지우기
        for (const auto& block : deletedBlock) {
            int x = block.first.first;
            int y = block.first.second;
            Map[y][x] = '-';
            answer++;
        }
        
        // 빈 칸 블록 내려서 채우기
        for (auto y=m-1; y>0; y--) {
            for (auto x=n-1; x>=0; x--) {
                if (Map[y][x] == '-') {
                    for (auto ny=y-1; ny>=0; ny--) {
                        if (Map[ny][x] != '-') {
                            Map[y][x] = Map[ny][x];
                            Map[ny][x] = '-';
                            break;
                        }
                    }
                }
            }
        }
        
        deletedBlock.clear();
    }
    
    return answer;
}