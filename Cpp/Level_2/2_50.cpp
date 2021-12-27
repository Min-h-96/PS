/* **************************************************************
    스킬트리
************************************************************** */

#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = skill_trees.size();
    map<char, int> order;
    
    // 스킬 순서 저장
    int orderNum = 1;
    for (const auto& s : skill)
        order.insert({s, orderNum++});
    
    // 스킬 트리 확인
    for (const auto& tree : skill_trees) {
        orderNum = 1;
        for (const auto& t : tree) {
            if (order.find(t) == order.end())
                continue;
            else {
                if (order[t] == orderNum) {
                    orderNum++;
                    continue;
                } else {
                    answer--;
                    break;
                }
            }
        }
    }
    
    return answer;
}