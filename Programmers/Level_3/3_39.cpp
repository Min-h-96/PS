/* **************************************************************
    110 옮기기
************************************************************** */

#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<string> solution(vector<string> s) {
    vector<string> answer;
    
    for (const auto& x : s) {
        stack<char> st;
        int count = 0; //x 에서 만들어지는 110 의 개수
        
        for (const auto& c : x) {
            st.push(c);
            if (st.size() >= 3) {
                char three = st.top(); st.pop();
                char two = st.top(); st.pop();
                char one = st.top(); st.pop();
                
                if (one == '1' && two == '1' && three == '0')
                    count++;
                else {
                    st.push(one);
                    st.push(two);
                    st.push(three);
                }
            }
        }
        
        if (count == 0) { //110 이 하나도 없으면 x 자체가 답
            answer.push_back(x);
            continue;
        }
        
        int idx = st.size();
        string str = "";
        
        while (!st.empty() && st.top() == 1) {
            idx--;
            str = st.top() + str;
            st.pop();
        }
        
        while (!st.empty()) {
            str = st.top() + str;
            st.pop();
        }
        
        while (count-- > 0)
            str.insert(idx, "110");
        
        answer.push_back(str);
    }
    
    return answer;
}