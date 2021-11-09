/* **************************************************************
    서울에서 김서방 찾기
************************************************************** */

#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "김서방은 ";
    
    for (int i=0; i<=1000; i++) {
        if (seoul[i] == "Kim") {
            answer += to_string(i);
            break;
        }
    }
    answer += "에 있다";
    return answer;
}