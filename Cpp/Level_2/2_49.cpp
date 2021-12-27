/* **************************************************************
    쿼드 압축 후 개수 세기
************************************************************** */

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int num[2] = {0, 0};
vector<vector<int>> MAP;

void recursive(int startX, int startY, int n) {
    int firstNum = MAP[startY][startX];
    
    bool flag = true;
    for (int y=startY; y<startY+n; y++) {
        if (!flag)
            break;
        for (int x=startX; x<startX+n; x++) {
            if (firstNum != MAP[y][x]) {
                flag = false;
                break;
            }
        }
    }
    
    if (flag == true) {
        num[firstNum]++;
        return ;
    }
    
    recursive(startX, startY, n / 2);
    recursive(startX + n / 2, startY, n / 2);
    recursive(startX, startY + n / 2, n / 2);
    recursive(startX + n / 2, startY + n / 2, n / 2);
    
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;
    MAP = arr;
    
    recursive(0, 0, arr.size());
    
    answer.assign({num[0], num[1]});
    
    return answer;
}