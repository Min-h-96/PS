/* **************************************************************
    풍선 터뜨리기
************************************************************** */

#include <string>
#include <vector>

using namespace std;

int solution(vector<int> a) {
    int answer = 0;
    int len = a.size();
    vector<int> left(len, 0);
    vector<int> right(len, 0);
    
    int Min = a[0];
    for (auto i=0; i<len; i++) {
        if (Min > a[i])
            Min = a[i];
        left[i] = Min;
    }
    
    Min = a[len-1];
    for (int i=len-1; i>=0; i--) {
        if (Min > a[i])
            Min = a[i];
        right[i] = Min;
    }
    
    for (int i=0; i<len; i++) {
        if (a[i] <= left[i] || a[i] <= right[i])
            answer++;
    }
    
    return answer;
}