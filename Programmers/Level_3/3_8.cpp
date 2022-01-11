/* **************************************************************
    정수 삼각형
************************************************************** */

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    
    vector<vector<int>> dpTriangle = triangle;
    
    for (auto i=0; i<dpTriangle.size()-1; i++) {
        for (auto j=0; j<dpTriangle[i].size(); j++) {
            dpTriangle[i+1][j] = max(dpTriangle[i+1][j], dpTriangle[i][j] + triangle[i+1][j]);
            dpTriangle[i+1][j+1] = max(dpTriangle[i+1][j+1], dpTriangle[i][j] + triangle[i+1][j+1]);
        }
    }
    answer = *max_element(dpTriangle[dpTriangle.size()-1].begin(), dpTriangle[dpTriangle.size()-1].end());
    
    return answer;
}