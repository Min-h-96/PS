/* **************************************************************
    행렬의 덧셈
************************************************************** */

#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    
    for (auto i=0; i<arr1.size(); i++) {
        answer.push_back(vector<int>());
        for (auto j=0; j<arr1[i].size(); j++) {
            answer[i].push_back(arr1[i][j] + arr2[i][j]);
        }
    }
    return answer;
}