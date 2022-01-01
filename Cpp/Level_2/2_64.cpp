/* **************************************************************
    행렬의 곱셈
************************************************************** */

#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> mulMatrix(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    int A = arr1[0].size(), B = arr1.size(), C = arr2[0].size();
    vector<vector<int>> answer(B, vector<int>());
    
    for (int k=0; k<C; k++) {
        for (int i=0; i<B; i++) {
            int sum = 0;
            for (int j=0; j<A; j++)
                sum += arr1[i][j] * arr2[j][k];
            answer[i].push_back(sum);
        }
    }
    
    return answer;
}

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    
    if (arr1[0].size() == arr2.size())
        answer = mulMatrix(arr1, arr2);
    else if (arr1.size() == arr2[0].size())
        answer = mulMatrix(arr2, arr1);
    
    return answer;
}