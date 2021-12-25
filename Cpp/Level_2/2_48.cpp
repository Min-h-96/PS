/* **************************************************************
    n^2 배열 자르기
************************************************************** */

#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    
    for (auto i=left; i<=right; i++) {
        auto div = i / n;
        auto mod = i % n;
        answer.push_back(max(div, mod) + 1);
    }
    
    return answer;
}