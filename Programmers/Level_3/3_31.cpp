/* **************************************************************
    기둥과 보 설치
************************************************************** */

#include <string>
#include <vector>

using namespace std;

bool totalStatus(vector<vector<pair<int, int>>>& wall, int n) {
    for (auto i=0; i<n+1; i++) {
        for (auto j=0; j<n+1; j++) {
            if (wall[i][j].first == 1) { //현재 좌표에 기둥이 있는 경우
                if (!(i == 0 || wall[i-1][j].first == 1 ||
                    (j > 0 && wall[i][j-1].second == 1) || wall[i][j].second == 1))
                    return false;
            }
            
            if (wall[i][j].second == 1) { //현재 좌표에 보가 있는 경우
                if (!(wall[i-1][j].first == 1 || wall[i-1][j+1].first == 1 ||
                   (wall[i][j-1].second == 1 && wall[i][j+1].second == 1)))
                    return false;
            }
        }
    }
    return true;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    vector<vector<pair<int, int>>> wall(n+1, vector<pair<int, int>>(n+1, {0, 0}));
    
    for (const auto& build : build_frame) {
        int x = build[0], y = build[1]; //설치 좌표
        int frame = build[2]; //기둥(0) or 보(1)
        int action = build[3]; //설치(1) or 삭제(0)
        
        //설치
        if (action == 1) {
            if (frame == 0) { //기둥 설치
                //바닥이거나 해당 x좌표 또는 (해당 x좌표 - 1) 에 보가 깔려있을 때 설치 가능
                if (y == 0 || wall[y-1][x].first == 1 ||
                    wall[y][x].second == 1 || (x > 0 && wall[y][x-1].second == 1))
                    wall[y][x].first = 1;
            } else { //보 설치
                //한 쪽에 기둥이 있는지 확인
                if (wall[y-1][x].first == 1 || (x < n && wall[y-1][x+1].first == 1))
                    wall[y][x].second = 1;
                //양 쪽 모두에 보가 있는 지 확인, 이 조건은 1 <= x <= n-1 인 곳에서만 확인 가능
                else if ((x > 0 && x < n) &&
                         (wall[y][x-1].second == 1 && wall[y][x+1].second == 1 )) { 
                    wall[y][x].second = 1;
                }
            }
        }
        //삭제
        else {
            //일단 지우고 모든 부분이 괜찮은 지 확인 후 괜찮지 않다면 원래대로 돌리기
            if (frame == 0) //기둥 삭제
                wall[y][x].first = 0;
            else//보 삭제
                wall[y][x].second = 0;
            
            if (!totalStatus(wall, n)) {
                if (frame == 0)
                    wall[y][x].first = 1;
                else
                    wall[y][x].second = 1;
            }
        }
    }
    
    //기둥이나 보가 있는 좌표를 답에 추가
    for (auto i=0; i<n+1; i++) {
        for (auto j=0; j<n+1; j++) {
            vector<int> a;
            if (wall[j][i].first == 1) {
                a.push_back(i);
                a.push_back(j);
                a.push_back(0);
            }
            vector<int> b;
            if (wall[j][i].second == 1) {
                b.push_back(i);
                b.push_back(j);
                b.push_back(1);
            }
            
            if (!a.empty())
                answer.push_back(a);
            if (!b.empty())
                answer.push_back(b);
        }
    }
    
    return answer;
}