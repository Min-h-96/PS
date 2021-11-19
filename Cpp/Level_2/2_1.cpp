/* **************************************************************
    신규 아이디 추천
************************************************************** */

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string s) {
    int answer = 0;
    int count = 0;
    vector<int> totalLength;
    string beforeStr;
    string afterStr;
    string zipStr;

    for (auto i=1; i<=s.size()/2; i++) {
        for (auto j : s) {
            if (beforeStr.size() < i) {
                beforeStr += j;
                continue;
            }   
            afterStr += j;
            if (afterStr.size() == i) {
                if (afterStr == beforeStr) {
                    count++;
                } else {
                    if (count > 0)
                        zipStr += to_string(count + 1);
                    zipStr += beforeStr;
                    count = 0;
                }
                beforeStr.clear();
                beforeStr += afterStr;
                afterStr.clear();
            }
        }
        if (!beforeStr.empty()) {
            if (count > 0)
                zipStr += to_string(count + 1);
            zipStr += beforeStr;
            count = 0;
            beforeStr.clear();
        }
        if (!afterStr.empty()) {
            zipStr += afterStr;
            afterStr.clear();
        }
        totalLength.push_back(zipStr.size());
        zipStr.clear();
    }
    if (totalLength.size() == 0)
        answer = 1;
    else
        answer = *min_element(totalLength.begin(), totalLength.end());
    return answer;
}