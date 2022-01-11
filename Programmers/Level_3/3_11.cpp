/* **************************************************************
    다단계 칫솔 판매
************************************************************** */

#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    unordered_map<string, pair<string, int>> result;
    
    for (auto i=0; i<enroll.size(); i++)
        result.insert({enroll[i], {referral[i], 0}});
    
    for (auto i=0; i<seller.size(); i++) {
        string curSeller = seller[i];
        int curPrice = amount[i] * 100;
        
        // 추천없이 들어온 사람이 referral 일 때까지 이익 분배
        while (result[curSeller].first != "-") {
            result[curSeller].second += curPrice - (curPrice / 10);
            curSeller = result[curSeller].first;
            curPrice /= 10;
			// 더 이상 추천인에게 분배할 금액이 없을 때
            if (curPrice == 0)
                break;
        }
        
        // 추천없이 들어온 사람이 벌어들인 이익 center 와 분배
        result[curSeller].second += curPrice - (curPrice / 10);
    }
    
    for (const auto& e : enroll)
        answer.push_back(result[e].second);
    
    
    return answer;
}