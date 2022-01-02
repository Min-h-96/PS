/* **************************************************************
    최솟값 만들기
************************************************************** */

#include <string>
#include <vector>
#include <iostream>

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

// 벡터를 이용한 풀이
int solution(vector<int> arr) {
    int answer = 0;
    
    int size = arr.size();
    for (int i=0; i<size-1; i++) {
        arr[0] = lcd(arr[0], arr[1]);
        arr.erase(arr.begin()+1, arr.begin()+2);
    }
    
    answer = arr[0];
    
    return answer;
}

/* 스택을 이용한 풀이
#include <string>
#include <vector>
#include <stack>
#include <iostream>

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

int solution(vector<int> arr) {
    int answer = 0;
    stack<int> s;
    
    for (const auto& a : arr)
        s.push(a);
    
    while (!s.empty()) {
        if (s.size() == 1)
            break;
        int num1 = s.top();
        s.pop();
        int num2 = s.top();
        s.pop();
        s.push(lcd(num1, num2));
    }
    
    answer = s.top();
    
    return answer;
}
*/