/* **************************************************************
    H-Index
************************************************************** */

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    
    sort(citations.rbegin(), citations.rend());
    int h = 0;
    for (const auto& c : citations) {
        if (c == 0)
            continue;
        if (h >= c)
            break;
        h++;
    }
    answer = h;
    
    return answer;
}