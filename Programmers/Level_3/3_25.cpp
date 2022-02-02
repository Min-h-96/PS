/* **************************************************************
    보행자 천국
************************************************************** */

#include <vector>
#include <iostream>

using namespace std;

int MOD = 20170805;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
    int answer = 0;
    vector<vector<int>> cities(m, vector<int>(n, -1));
    
    for (auto i=0; i<m; i++) {
        for (auto j=0; j<n; j++) {
            //출발점은 1로 초기화
            if (i == 0 && j == 0) {
                cities[i][j] = 1;
                continue;
            }
            
            //city_map[i][j] 이 1 인 경우 cities[i][j] 는 0
            if (city_map[i][j] == 1)
                cities[i][j] = 0;
            //city_map[i][j] 이 2 인 경우 cities[i][j] 는 그대로 -1
            else if (city_map[i][j] == 2)
                continue;
            //city_map[i][j] 가 0 인 경우 cities[i][j] 는 cities[i-1][j] + cities[i][j-1]
            else {
                int up = 0, left = 0;
                int tmp = 0;
                while (i - ++tmp >= 0) {
                    if (cities[i-tmp][j] != -1) {
                        up = cities[i-tmp][j];
                        break;
                    }
                }
                tmp = 0;
                while (j - ++tmp >= 0) {
                    if (cities[i][j-tmp] != -1) {
                        left = cities[i][j-tmp];
                        break;
                    }
                }
                
                cities[i][j] = ((up % MOD) + (left % MOD)) % MOD;
            }
        }
    }
    
    answer = cities[m-1][n-1];
    
    return answer;
}