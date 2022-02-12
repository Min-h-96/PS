#include <string>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = 10;
    
    sort(dist.begin(), dist.end());
    deque<int> dq(weak.begin(), weak.end());
    
    for (auto i=0; i<dist.size(); i++) {
        //처음에는 친구 1명에서부터 안될 경우 1명씩 늘려감
        vector<bool> checked(dist.size()-i-1, false);
        for (auto j=0; j<i+1; j++)
            checked.push_back(true);
        
        do {
            //취약 지점에 투입할 친구들 선택
            vector<int> friends;
            for (auto k=0; k<checked.size(); k++) {
                if (checked[k] == true)
                    friends.push_back(dist[k]);
            }
            
            //시작점 기준 시계 방향
            for (auto k=0; k<weak.size(); k++) {
                deque<int> tmp = dq;
                //기준만큼 회전 ex) [5, 6, 10, 13]
                for (auto l=0; l<k; l++) {
                    tmp.push_back(tmp.front() + n);
                    tmp.pop_front();
                }
                
                for (const auto& f : friends) {
                    int start;
                    if (!tmp.empty()) {
                        start = tmp.front();
                        tmp.pop_front();
                    }
                    
                    while (!tmp.empty()) {
                        int end = tmp.front();
                        tmp.pop_front();
                        
                        if (f < end - start) {
                            tmp.push_front(end);
                            break;
                        }
                    }
                }
                if (tmp.empty())
                    answer = min(answer, static_cast<int>(friends.size()));
            }
            
            //시작점 기준 반시계 방향
            for (auto k=0; k<weak.size(); k++) {
                deque<int> tmp = dq;
                //기준만큼 회전 ex) [5, 6, 10, 13]
                for (auto l=0; l<k; l++) {
                    tmp.push_back(tmp.front() + n);
                    tmp.pop_front();
                }
                sort(tmp.rbegin(), tmp.rend());
                
                for (const auto& f : friends) {
                    int start;
                    if (!tmp.empty()) {
                        start = tmp.front();
                        tmp.pop_front();
                    }
                    
                    while (!tmp.empty()) {
                        int end = tmp.front();
                        tmp.pop_front();
                        
                        if (f < start - end) {
                            tmp.push_front(end);
                            break;
                        }
                    }
                }
                if (tmp.empty())
                    answer = min(answer, static_cast<int>(friends.size()));
            }
        } while (next_permutation(checked.begin(), checked.end()));
    }
    
    if (answer == 10)
        return -1;
    
    return answer;
}