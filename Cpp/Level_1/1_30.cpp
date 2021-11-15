/* **************************************************************
    문자열 내 맘대로 정렬하기
************************************************************** */

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    
    sort(strings.begin(), strings.end());
    for (int i='a'; i<='z'; i++) {
        for (string str : strings) {
            if (str[n] == i)
                answer.push_back(str);
        }    
    }
    
    return answer;
}