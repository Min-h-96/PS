/* **************************************************************
    배달
************************************************************** */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int, int>> v[51];
vector<int> dist;

void dijkstra(int K) {
    int pos, dis, next, ndis;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    pq.push({1, 0});
    while (!pq.empty()) {
        pos = pq.top().first;
        dis = pq.top().second;
        pq.pop();
        for (const auto& i : v[pos]) {
            next = i.first;
            ndis = i.second;
            if (dist[next] > dist[pos] + ndis) {
                dist[next] = dist[pos] + ndis;
                pq.push({next, ndis});
            }
        }
    }
}

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;

    dist.resize(N+1, 2e9);
    for (const auto& r : road) {
        int a = r[0], b = r[1], c = r[2];
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
    
    dist[1] = 0;
    dijkstra(K);
    
    for (const auto& d : dist) {
        if (d <= K)
            answer++;
    }

    return answer;
}