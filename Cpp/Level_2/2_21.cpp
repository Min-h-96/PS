/* **************************************************************
    가장 큰 수
************************************************************** */

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool comp(const string& a, const string& b) {
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> strNumbers;
    
    for (const auto& n : numbers)
        strNumbers.push_back(to_string(n));
    
    sort(strNumbers.begin(), strNumbers.end(), comp);
    
    if (strNumbers.at(0) == "0")
        return "0";
    
    for (const auto& n : strNumbers)
        answer += n;
    
    return answer;
}