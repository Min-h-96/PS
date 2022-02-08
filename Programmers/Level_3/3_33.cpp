/* **************************************************************
    길 찾기 게임
************************************************************** */

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> stones, int k) {
    int answer = 2e9;
    int start = 0, end = *max_element(stones.begin(), stones.end());
    
    while (start <= end) {
        int mid = (start + end) / 2; //mid = 건넌 사람의 수
        vector<int> tmp = stones;
        
        //건넌 사람 수 만큼 stone 에서 빼기
        int cnt = 0; //stone 에 수가 0 이하가 연속으로 몇 개인지 세는 카운트
        for (auto i=0; i<tmp.size(); i++) {
            tmp[i] -= mid;
            if (tmp[i] <= 0)
                cnt++;
            else
                cnt = 0;
            
            if (cnt >= k) {
                answer = min(answer, mid);
                end = mid - 1;
                break;
            }
        }
        
        if (cnt < k)
            start = mid + 1;
    }
    
    return answer;
}