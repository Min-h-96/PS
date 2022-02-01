/* **************************************************************
    경주로 건설
************************************************************** */

#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

class Car {
    public:
        int x, y, dir, price;
};

int solution(vector<vector<int>> board) {
    int answer = 2e9;
    int N = board.size();
    int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
    vector<vector<int>> price(N, vector<int>(N, 2e9));
    queue<Car> q;
    Car c;
    c.x = 0, c.y = 0, c.dir = -1, c.price = 0;
    price[0][0] = 0;
    q.push(c);
    
    while (!q.empty()) {
        Car a = q.front();
        q.pop();
        
        //도착점에 도착하면 최소 비용을 선택
        if (a.x == N-1 && a.y == N-1) {
            answer = min(answer, a.price);
            continue;
        }
        
        for (auto i=0; i<4; i++) {
            int nx = a.x + dx[i];
            int ny = a.y + dy[i];
            
            //board 범위 밖이거나 벽이면 continue
            if (nx < 0 || ny < 0 || nx >= N || ny >= N || board[ny][nx] == 1)
                continue;
            
            int nprice = 0;
            //차량이 출발점이거나 방향이 이전과 같으면 +100
            if (a.dir == -1 || a.dir == i)
                nprice = a.price + 100;
            else //방향이 다르면 (코너 + 도로비용) 이므로 +600
                nprice = a.price + 600;
            
            //현재 위치에 이전에 측정된 비용과 비교후 최신화
            //>= 으로 하는 이유는 가격은 같지만 방향이 다르게 해서 도착한 경우가 생기므로
            if (price[nx][ny] + 200 >= nprice) {
                price[nx][ny] = nprice;
                Car b;
                b.x = nx, b.y = ny, b.dir = i, b.price = nprice;
                q.push(b);
            }
        }
    }
    
    return answer;
}