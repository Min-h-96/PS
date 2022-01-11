/* **************************************************************
    숫자의 표현
************************************************************** */

#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    for (int i=1; i<=n; i++) {
        int start = i;
        int ans = 0;
        while (ans < n)
            ans += start++;
        if (ans == n)
            answer++;
    }
    
    return answer;
}