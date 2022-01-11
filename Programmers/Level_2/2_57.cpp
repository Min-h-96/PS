/* **************************************************************
    [3차] n진수 게임
************************************************************** */

#include <string>
#include <vector>
#include <deque>
#include <iostream>

using namespace std;

char scale[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

string solution(int n, int t, int m, int p) {
    string answer = "";
    deque<char> dq;
    int turn = 1;
    
    dq.push_back('0');
    int curNum = 1;
    while (answer.size() < t) {
        // 덱 비어있으면 다음 숫자 채워넣기
        if (dq.empty()) {
            int tmp = curNum;
            while (tmp > 0) {
                dq.push_front(scale[tmp % n]);
                tmp /= n;
            }
            curNum++;
        }
        
        // 튜브의 순서면 answer 에 현재 말해야 하는 문자 추가
        if (turn == p)
            answer += dq.front();
        
        // 말한 문자 덱에서 제거
        dq.pop_front();
        turn++;
        
        // 현재 차례가 게임에 참가한 인원보다 많아지면 다시 첫 번째 순서부터
        if (turn > m)
            turn = 1;
        
    }
    
    return answer;
}