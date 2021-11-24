/* **************************************************************
    행렬 테두리 회전하기
************************************************************** */

#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    vector<vector<int>> matrix;
    
    // 행렬 초기화
    for (auto i=0; i<rows; i++) {
        matrix.push_back(vector<int>());
        for (auto j=0; j<columns; j++) {
            matrix[i].push_back((i * columns) + j + 1);
        }
    }
    
    // 전체 회전 과정
    for (auto i=0; i<queries.size(); i++) {
        //회전하는 원소들만 추출해서 deque 에 push
        deque<int> dq, dq1, dq2, dq3, dq4;
        int x1 = queries[i][0];
        int y1 = queries[i][1];
        int x2 = queries[i][2];
        int y2 = queries[i][3];
        for (auto j=x1-1; j<x2; j++) {
            for (auto k=y1-1; k<y2; k++) {
                if (j > x1-1 && j < x2-1 && k > y1-1 && k < y2-1)
                    continue;
                else if (j == x1-1)
                    dq1.push_back(matrix[j][k]);
                else if (k == y2-1)
                    dq2.push_back(matrix[j][k]);
                else if (j == x2-1)
                    dq3.push_back(matrix[j][k]);
                else if (k == y1-1)
                    dq4.push_back(matrix[j][k]);
                dq.push_back(matrix[j][k]);
            }
        }
        
        // 회전 동작
        // (x1 - x2) 의 차이가 1 이면 dq4 에 아무것도 안 들어감.
        if (x2 - x1 > 1)
            dq1.push_front(dq4.front());
        else
            dq1.push_front(dq3.front());
        dq2.push_front(dq1.back());
        dq3.push_back(dq2.back());
        dq4.push_back(dq3.front());
        dq1.pop_back();
        dq2.pop_back();
        dq3.pop_front();
        dq4.pop_front();
        
        //matrix 에 다시 입력
        for (auto j=x1-1; j<x2; j++) {
            for (auto k=y1-1; k<y2; k++) {
                if (j > x1-1 && j < x2-1
                    && k > y1-1 && k < y2-1)
                    continue;
                else if (j == x1-1) {
                    matrix[j][k] = dq1.front();
                    dq1.pop_front();
                } else if (k == y2-1) {
                    matrix[j][k] = dq2.front();
                    dq2.pop_front();
                } else if (j == x2-1) {
                    matrix[j][k] = dq3.front();
                    dq3.pop_front();
                } else if (k == y1-1) {
                    matrix[j][k] = dq4.front();
                    dq4.pop_front();
                }
            }
        }

        //min value 찾기
        answer.push_back(*min_element(dq.begin(), dq.end()));
    }
    
    return answer;
}