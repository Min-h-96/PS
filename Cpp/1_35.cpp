/* **************************************************************
    소수 찾기
************************************************************** */

#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 0;
    bool primeNum[n];
    
    for (int i=2; i<=n; i++)
        primeNum[i] = false;
    primeNum[0] = primeNum[1] = true;
    for (int i=2; i<sqrt(n); i++){
		if (primeNum[i] == false){
			for (int j=i+i; j<=n; j+=i){
				primeNum[j] = true;
			}
		}
	}
    for (int i=2; i<=n; i++) {
        if (!primeNum[i])
            answer++;
    }
    return answer;
}