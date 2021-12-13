/* **************************************************************
    조이스틱
************************************************************** */

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int UpDown(char c) {
    if ('A' <= c && c <= 'N')
        return c - 'A';
    else
        return 'Z' - c + 1;
}

int moveToLast(int i, const string& name) {
    if (i == 0)
        return name.length() - 1;
    else
        return i - 1;
}

int solution(string name) {
    int answer = 0;
    vector<bool> checked(name.length(), true);
    string nameTmp;
    
    for (int i=0; i<name.length(); i++) {
        nameTmp += "A";
        if (name[i] != 'A')
            checked[i] = false;
    }
    int idx = 0;
    while (true) {
        // 현재 인덱스 위치의 알파벳 이름 완성
        if (checked[idx] == false) {
            answer += UpDown(name[idx]);
            nameTmp[idx] = name[idx];
            checked[idx] = true;
        }
        
        // 모든 알파벳이 name 과 동일하면 답을 반환
        int check = -1;
        while (++check < checked.size()) {
            if (checked[check] == false)
                break;
        }
        if (check == checked.size())
            break;
        
        // 좌우 중 더 가까운 곳으로 이동
        int right = idx + 1;
        int rightMove = 1;
        int left = moveToLast(idx, name);
        int leftMove = 1;
        while (checked[right] == true) {
            right++;
            rightMove++;
        }
        while (checked[left] == true) {
            left = moveToLast(left, name);
            leftMove++;
        }
        
        if (rightMove <= leftMove) {
            answer += rightMove;
            idx = right;
        } else {
            answer += leftMove;
            idx = left;
        }
    }
    
    return answer;
}