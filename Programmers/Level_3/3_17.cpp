/* **************************************************************
    GPS
************************************************************** */

#include <vector>
#include <algorithm>

using namespace std;

#define INF 987654321

int solution(int n, int m, vector<vector<int>> edge_list, int k, vector<int> gps_log){
    int answer = 0;
    // road 는 인접 리스트
    // 인덱스는 각 지점에 대응. 지점마다 자신과 인접한 지점들을 추가 
    // ex) road[2] = [3, 4]  2 지점은 3, 4 지점과 연결된 상태임을 의미함.
    vector<vector<int>> road(n + 1); 
    for (int i = 0; i < edge_list.size(); ++i) {
        road[edge_list[i][0]].push_back(edge_list[i][1]);
        road[edge_list[i][1]].push_back(edge_list[i][0]);
    }

    // dp의 모든 원소를 INF 로 초기화 해야함
    vector<vector<int>> dp(k, vector<int>(n + 1, INF)); 
    dp[0][gps_log[0]] = 0; // 시작점 고정 (0 초의 시작점의 최소 수정횟수는 0)
    for (int t = 1; t < k; ++t) { // t = 0 은 위에서 구했으니 제외 (t = 0 땐 무조건 시작점에서 시작해야 함. 이 경우만 고려 되야 함)
        for (int pos = 1; pos <= n; ++pos) {
            
            /* 아래 경우들에서 가장 최소 수정 횟수를 가지는 경우를 그대로 물려 받는다. */
            // 1초전에도 pos에 있었던 경우(그대로 머무른 경우) 
            int minValue = dp[t - 1][pos]; 
            // pos 와 인접한 지점들에서 온 경우 
            for (int i = 0; i < road[pos].size(); ++i)
                minValue = min(dp[t - 1][road[pos][i]], minValue);
            
            if (gps_log[t] != pos) 
                dp[t][pos] = minValue + 1; // 수정이 필요하다면 +1 
            else 
                dp[t][pos] = minValue; // 아니라면 냅둠
        }
    }

    answer = dp[k - 1][gps_log[k - 1]]; // gps_log[k-1] 즉, 마지막 시간대인 k-1 초에 목적지까지 필요한 최소 수정 횟수
    if (answer >= INF) answer = -1;  // dp[k - 1][gps_log[k - 1]] 가 INF 보다 크다는 것은 수정이 불가능한 경우
    return answer;
}