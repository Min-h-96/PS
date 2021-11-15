/* **************************************************************
    최대공약수와 최소공배수
************************************************************** */

#include <string>
#include <vector>

using namespace std;

int gcd(int n, int m) {
    int mod = n % m;
    
    while (mod > 0) {
        n = m;
        m = mod;
        mod = n % m;
    }
    return m;
}

int lcd(int n, int m) {
    return n * m / gcd(n, m);
}

vector<int> solution(int n, int m) {
    vector<int> answer;
    
    answer.push_back(gcd(n, m));
    answer.push_back(lcd(n, m));
    return answer;
}