/* **************************************************************
    모두 0으로 만들기
************************************************************** */

#include <string>
#include <vector>

using namespace std;

long long answer = 0;

void DFS(vector<vector<int>>& trees, vector<long long>& sum, int now, int parent) {
    //leaf 노드가 나올 때까지 자식 노드 재귀 호출
    for (auto i=0; i<trees[now].size(); i++) {
        if (trees[now][i] != parent)
            DFS(trees, sum, trees[now][i], now);
    }
    
    //DFS 가 끝나고 현재 방문 중인 노드의 값을 부모 노드의 추가해줌
    sum[parent] += sum[now];
    answer += abs(sum[now]);
}

long long solution(vector<int> a, vector<vector<int>> edges) {
    vector<long long> sum(a.begin(), a.end());
    vector<vector<int>> trees(a.size(), vector<int>());
    
    for (const auto& e : edges) {
        trees[e[0]].push_back(e[1]);
        trees[e[1]].push_back(e[0]);
    }
    
    DFS(trees, sum, 0, 0);
    
    if (sum[0] != 0)
        return -1;
    
    return answer;
}