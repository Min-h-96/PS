/* **************************************************************
    주식가격
************************************************************** */

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    
    for (auto i=0; i<prices.size()-1; i++) {
        int cnt = 0;
        for (auto j=i+1; j<prices.size(); j++) {
            cnt++;
            if (prices[j] < prices[i])
                break;
        }
        answer.push_back(cnt);
    }
    answer.push_back(0);
    
    return answer;
}