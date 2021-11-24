/* **************************************************************
    메뉴 리뉴얼
************************************************************** */

#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>

using namespace std;

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    map<string, int> menu;
    
    for (const auto& o : orders) {
        for (const auto & c : course) {
            if (o.size() < c)
                break;
            vector<bool> checked(o.size() - c, false);
            for (auto i=0; i<c; i++)
                checked.push_back(true);
            
            do {
                // 각 손님 별 주문한 단품메뉴 종류 -> course 길이 별 메뉴 조합
                string m;
                for (auto i=0; i<checked.size(); i++) {
                    if (checked[i] == true)
                        m.push_back(o[i]);
                }
                sort(m.begin(), m.end());
                
                // 각 코스요리 메뉴 주문 횟수 세기
                if (menu.find(m) != menu.end())
                    menu[m]++;
                else
                    menu.insert(pair<string, int>(m, 1));
                
            } while (next_permutation(checked.begin(), checked.end()));
        }
    }
    
    for (const auto& c : course) {
        // 각 코스요리 길이 별 주문 횟수 최댓값 찾기
        int max_order = 2;  // 최소 2명의 손님에게 주문을 받은 메뉴여야 한다.
        for (const auto& m : menu) {
            if (m.first.size() == c) {
                if (m.second > max_order)
                    max_order = m.second;
            }
        }
        
        // 주문 횟수가 가장 많은 메뉴를 answer 에 추가하기
        for (const auto& m : menu) {
            if (max_order == m.second && c == m.first.size())
                answer.push_back(m.first);
        }
    }
        
    sort(answer.begin(), answer.end());
    
    return answer;
}