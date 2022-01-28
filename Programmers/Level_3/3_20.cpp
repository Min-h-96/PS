/* **************************************************************
    이중우선순위 큐
************************************************************** */

#include <string>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer(2, 0);
    priority_queue<int, vector<int>, less<int>> pq1;
    priority_queue<int, vector<int>, greater<int>> pq2;
    int cnt = 0;
    
    for (const auto& oper : operations) {
        if (oper[0] == 'I') { //삽입
            pq1.push(stoi(oper.substr(2)));
            pq2.push(stoi(oper.substr(2)));
            cnt++;
        } else {
            if (cnt == 0)
                continue;
            
            if (oper[2] == '-')
                pq2.pop();
            else
                pq1.pop();
            cnt--;
            
            if (cnt == 0) {
                while (!pq2.empty())
                    pq2.pop();
								while (!pq1.empty())
                    pq1.pop();
            }
        }
    }
    
    if (cnt == 0)
        return answer;
    
    answer[0] = pq1.top();
    answer[1] = pq2.top();
    
    return answer;
}

/* 우선순위 큐 1개 사용
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer(2, 0);
    priority_queue<int> pq;
    
    for (const auto& oper : operations) {
        if (oper[0] == 'I') { //삽입
            pq.push(stoi(oper.substr(2)));
        } else { //삭제
            //큐가 비어있으면 continue
            if (pq.empty())
                continue;
            
            if (oper[2] == '-') { //최솟값 삭제
                vector<int> tmp;
                while (pq.size() != 1) {
                    tmp.push_back(pq.top());
                    pq.pop();
                }
                pq.pop();
                for (auto i=0; i<tmp.size(); i++)
                    pq.push(tmp[i]);
            } else //최댓값 삭제
                pq.pop();
        }
    }
    
    if (pq.empty())
        return answer;
    answer[0] = pq.top();
    while (pq.size() != 1)
        pq.pop();
    answer[1] = pq.top();
    
    return answer;
}
*/