/* **************************************************************
    약수의 합
************************************************************** */

#include <string>
#include <vector>

using namespace std;

int sumOfDivisors(int n) {
    int sum = 0;

    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            sum += i;
            if (i * i != n)
                sum += n / i;
        }
    }
    return sum;
}

int solution(int n) {
    int answer = 0;
    
    answer = sumOfDivisors(n);
    return answer;
}