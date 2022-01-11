/* **************************************************************
    최소직사각형
************************************************************** */

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int max_wh(vector<vector<int>> sizes, int i) {
    int ret = 0;

    for (vector size : sizes) {
        if (size[i] > ret)
            ret = size[i];
    }
    return ret;
}

int solution(vector<vector<int>> sizes) {
    int answer = 0;

    for (int i=0; i<sizes.size(); i++) {
        if (sizes[i][0] < sizes[i][1]) {
            swap(sizes[i][0], sizes[i][1]);
        }
    }
    answer = max_wh(sizes, 0) * max_wh(sizes, 1);
    return answer;
}