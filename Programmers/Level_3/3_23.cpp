/* **************************************************************
    합승 택시 요금
************************************************************** */

#include <string>
#include <vector>

using namespace std;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 2e9;
    vector<vector<int>> graph(n+1, vector<int>(n+1, 2e9));
    
    //graph 초기화 및 fares 정보 입력
    for (auto i=1; i<=n; i++)
        graph[i][i] = 0;
    for (const auto& f : fares) {
        graph[f[0]][f[1]] = f[2];
        graph[f[1]][f[0]] = f[2];
    }
    
    //플로이드와샬 알고리즘 적용
    for (auto k=1; k<=n; k++) { //중간 지점
        for (auto i=1; i<=n; i++) { //시작 지점
            for (auto j=1; j<=n; j++) { //도착 지점
                //(시작 지점 -> 중간 지점) 과 (중간 지점 -> 도착 지점) 이 INF 면 불가능하므로
                if (graph[i][k] != 2e9 && graph[k][j] != 2e9)
                    //바로 가는 것과 중간 지점을 거쳐 가는 것 중 최소값
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }
    
    //출발지에서 A지점과 B지점으로 바로 가는게 최소 비용일 수 있으므로 이 값이 초기값
    answer = graph[s][a] + graph[s][b];
    //i가 1~n 까지 다 하므로 사실 출발지에서 바로 a, b 로 가는 비용도 체크하기 때문에 꼭 할 필요는 없다.
    //대신 안 할거면 answer 의 값을 처음에 INF 로 초기화
    
    for (auto i=1; i<=n; i++) {
        //출발지에서 i지점을 거쳐서 각자 A, B로 간다고 할 때, 그 경로는 전부 INF 가 아닌 값이어야 한다.
        if (graph[s][i] != 2e9 && graph[i][a] != 2e9 && graph[i][b] != 2e9)
            answer = min(answer, graph[s][i] + graph[i][a] + graph[i][b]);
    }
    
    return answer;
}