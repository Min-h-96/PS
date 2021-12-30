/* **************************************************************
    최댓값과 최솟값
************************************************************** */

#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";
    stringstream ss;
    vector<int> numSet;
    
    int num;
    ss.str(s);
    while (ss >> num)
        numSet.push_back(num);
    
	answer += to_string(*min_element(numSet.begin(), numSet.end())) + " "
            + to_string(*max_element(numSet.begin(), numSet.end()));
    
    return answer;
}