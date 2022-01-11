/* **************************************************************
    큰 수 만들기
************************************************************** */

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    
    int idx = 0;
    for (auto i=number.length()-k; i>0; i--) {
        int max_num = -1;
        int tmp;
        for (auto j=idx; j<number.length()-i+1; j++) {
            if (number[j] - '0' > max_num) {
                max_num = number[j] - '0';
                tmp = j;
            }
        }
        idx = tmp + 1;
        answer.push_back(max_num + '0');
    }
    
    return answer;
}