/* **************************************************************
    삼갈 달팽이
************************************************************** */

#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    int totalNum = 0;
    vector<vector<int>> tri;
    
    for (auto i=1; i<=n; i++) {
        totalNum += i;
        vector<int> tmp(i);
        tri.push_back(tmp);
    }
    
    int count = 1;
    for (auto i=0; i<(n-1) / 3 + 1; i++) {
        // 삼각형 왼쪽 변에 값 넣기
        for (auto j=2*i; j<tri.size()-i; j++) {
            if (tri[j][i] == 0) {
                tri[j][i] = count;
                count++;
            }
        }
        
        // 삼각형 밑 변에 값 넣기
        for (auto j=i+1; j<tri[tri.size()-i-1].size()-i; j++) {
            if (tri[tri.size()-i-1][j] == 0) {
                tri[tri.size()-i-1][j] = count;
                count++;
            }
        }
        
        //삼각형 오른쪽 변에 값 넣기
        for (auto j=tri.size()-i-1; j>2*i; j--) {
            if (tri[j][tri[j].size()-1-i] == 0) {
                tri[j][tri[j].size()-1-i] = count;
                count++;
            }
        }
    }
    
    for (auto i=0; i<n; i++) {
        for (auto j=0; j<tri[i].size(); j++)
            answer.push_back(tri[i][j]);
    }
    
    return answer;
}