/* **************************************************************
    [1차] 비밀지도
************************************************************** */

#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer(n);
    vector<int> map;
    
    for (int i=0; i<n; i++) {
        map.push_back(arr1[i] | arr2[i]);
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (map[i] >= pow(2, n - j - 1)) {
                answer[i].push_back('#');
                map[i] -= pow(2, n - j - 1);
            } else
                answer[i].push_back(' ');
        }
    }
    
    return answer;
}