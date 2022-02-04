/* **************************************************************
    여행경로
************************************************************** */

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool dfs(string start, vector<vector<string>> &tickets, vector<string> &answer, vector<string> &tmp, vector<bool> &visit){
    if(tmp.size() == tickets.size() + 1) {
        answer = tmp;
        return true;
    }
    
    for(int i = 0; i<tickets.size(); i++) {
        if(!visit[i] && tickets[i][0] == start) {
            visit[i] = true;
            tmp.push_back(tickets[i][1]); 
            bool success = dfs(tickets[i][1], tickets, answer, tmp, visit);
            
            //알파벳 순서가 앞서는 경로를 return 해야하므로
            if(success)
                return true;
            
            visit[i] = false;
            tmp.pop_back();
        }
        
    }
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    vector<string> tmp;
    vector<bool> visit(tickets.size(), false);
    
    sort(tickets.begin(), tickets.end());
    tmp.push_back("ICN");
    dfs("ICN", tickets, answer, tmp, visit);
    
    return answer;
}