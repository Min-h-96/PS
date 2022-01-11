/* **************************************************************
    체육복
************************************************************** */

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int final_lost = lost.size();
    int reserve_num = reserve.size();
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    for (int i=0; i<lost.size(); i++) {
        for (int j=0; j<reserve.size(); j++) {
            if (lost[i] == reserve[j]) {
                final_lost--;
                reserve_num--;
                lost[i] = -1;
                reserve[j] = -1;
            }
        }
    }
    for (int i=0; i<lost.size(); i++) {
        if (reserve_num > 0) {
            for (int j=0; j<reserve.size(); j++) {
                if ((lost[i] - 1 == reserve[j]) || (lost[i] + 1 == reserve[j])) {
                    final_lost--;
                    reserve_num--;
                    lost[i] = -1;
                    reserve[j] = -1;
                }
            }
        }
    }
    return n - final_lost;
}