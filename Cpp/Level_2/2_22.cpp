/* **************************************************************
    소수 찾기
************************************************************** */

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <map>

using namespace std;

bool checkPrime(int num) {
	if (num < 2) return false;
	int a = (int) sqrt(num);
	for (int i=2; i<=a; i++) {
        if (num % i == 0)
            return false;
    }
	return true;
}

int solution(string numbers) {
    int answer = 0;
    map<int, int> m;
    
    sort(numbers.begin(), numbers.end());
    
    for (auto i=1; i<=numbers.length(); i++) {
        vector<bool> checked(numbers.length() - i, false);
        for (auto j=0; j<i; j++)
            checked.push_back(true);
        
        do {
            string num;
            for (auto j=0; j<checked.size(); j++) {
                if (checked[j] == true)
                    num += numbers[j];
            }
            
            if (checkPrime(stoi(num))) {
                if (m.find(stoi(num)) == m.end()) {
                    m.insert({stoi(num), 1});
                    answer++;
                }
            }
        } while (next_permutation(numbers.begin(), numbers.end()));
    }
    
    return answer;
}