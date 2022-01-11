/* **************************************************************
    피보나치 수
************************************************************** */

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> fibo;
    
    fibo.push_back(0);
    fibo.push_back(1);
    for (int i=2; i<=n; i++)
        fibo.push_back((fibo[i-1] + fibo[i-2]) % 1234567);
    answer = fibo[n];
    
    return answer;
}