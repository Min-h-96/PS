/* **************************************************************
    섬 연결하기
************************************************************** */

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> parent;

bool cmp(vector<int>& a, vector<int>& b) {
    return a[2] < b[2];
}

int findParent(int A) {
    if (A == parent[A]) return A;
    return parent[A] = findParent(parent[A]);
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    for (auto i=0; i<n; i++)
        parent.push_back(i);
    
    sort(costs.begin(), costs.end(), cmp);
    
    for (const auto& c : costs) {
        int node1 = c[0];
        int node2 = c[1];
        int cost = c[2];
        if (findParent(node1) != findParent(node2)) {
            parent[findParent(node2)] = findParent(node1);
            answer += cost;
        }
    }
    
    return answer;
}