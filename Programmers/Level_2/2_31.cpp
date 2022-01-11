/* **************************************************************
    다리를 지나는 트럭
************************************************************** */

#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<int> bridge;
    
    for (auto i=0; i<bridge_length; i++)
        bridge.push(0);
    
    int bridge_weight = 0;
    int idx = 0;
    int time = 0;
    while (!bridge.empty()) {
        bridge_weight -= bridge.front();
        bridge.pop();
        if (idx < truck_weights.size()) {
            if (bridge_weight + truck_weights[idx] > weight)
                bridge.push(0);
            else {
                bridge.push(truck_weights[idx]);
                bridge_weight += truck_weights[idx];
                idx++;
            }
        }
        time++;
    }
    
    answer = time;
    
    return answer;
}