/* **************************************************************
    [3차] 방금그곡
************************************************************** */

#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool visited[11][11][4];

int solution(string dirs) {
    int answer = 0;
    vector<int> user(2, 5);
    
    for (const auto& dir : dirs) {
        int curLoc[2], nextLoc[2];
        int direct = -1;
        curLoc[0] = user[0];
        curLoc[1] = user[1];
        
        if (dir == 'U') {
            if (user[0] == 0)
                continue;
            direct = 0;
            user[0]--;
        }
        else if (dir == 'D') {
            if (user[0] == 10)
                continue;
            direct = 3;
            user[0]++;
        }
        else if (dir == 'R') {
            if (user[1] == 10)
                continue;
            direct = 1;
            user[1]++;
        }
        else if (dir == 'L') {
            if (user[1] == 0)
                continue;
            direct = 2;
            user[1]--;
        }
        
        nextLoc[0] = user[0];
        nextLoc[1] = user[1];
        
        if (visited[curLoc[0]][curLoc[1]][direct] == false) {
            visited[curLoc[0]][curLoc[1]][direct] = true;
            visited[nextLoc[0]][nextLoc[1]][3-direct] = true;
            answer++;
        }
    }
    
    return answer;
}