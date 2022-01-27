/* **************************************************************
    2 x n 타일링
************************************************************** */

#include <string>
#include <vector>

#define MOD 1000000007

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> pibo;
    
    pibo.push_back(1);
    pibo.push_back(2);
    
    for (auto i=2; i<n; i++)
        pibo.push_back(((pibo[i-1] % MOD) + (pibo[i-2] % MOD)) % MOD);
    
    answer = pibo[n-1];
    
    return answer;
}