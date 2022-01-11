/* **************************************************************
    가장 먼 노드
************************************************************** */

#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> dist;
vector<pair<int, int>> v[20001];

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

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    dist.resize(n+1, 2e9);
    dist[0] = 0;
    
    // 그래프 노드와 간선 그리기
    for (const auto& e : edge) {
        v[e[0]].push_back({e[1], 1});
        v[e[1]].push_back({e[0], 1});
    }
    
    // 노드 1 은 본인이므로 거리가 0, 다익스트라 알고리즘을 통한 노드 1 에서의 각 노드 최소 거리 구하기
    dist[1] = 0;
    dijkstra(n);
    
    int maxDist = *max_element(dist.begin(), dist.end());
    for (const auto& d : dist) {
        if (d == maxDist)
            answer++;
    }
    
    return answer;
}