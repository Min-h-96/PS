/* **************************************************************
    3진법 뒤집기
************************************************************** */

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n) {
    int answer = 0;
    int square = 1;
    vector<int> v;

    while (n >= 3) {
        v.push_back(n % 3);
        n /= 3;
    }
    v.push_back(n);
    reverse(v.begin(), v.end());
    for (int i : v) {
        answer += i * square;
        square *= 3;
    }
    return answer;
}