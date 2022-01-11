/* **************************************************************
    오픈 채팅방
************************************************************** */

#include <string>
#include <vector>
#include <queue>
#include <map>
#include <iostream>

using namespace std;

vector<string> solution(vector<string> record) {
    map<string, string> userInfo;
    queue<pair<string, string>> order;
    vector<string> answer;
    vector<string> recordWords;
    
    for (auto str : record) {
        // record 의 command split
        size_t pos = 0;
        if (!recordWords.empty())
            recordWords.clear();
        while ((pos = str.find(" ")) != string::npos) {
            recordWords.push_back(str.substr(0, pos));
            str.erase(0, pos + 1);
        }
        recordWords.push_back(str);
        
        // command 종류에 따른 mapping
        if (recordWords[0].compare("Enter") == 0) {
            order.push(pair<string, string>(recordWords[0], recordWords[1]));
            if (userInfo.find(recordWords[1]) == userInfo.end())
                userInfo.insert(pair<string, string>(recordWords[1], recordWords[2]));
            else
                userInfo[recordWords[1]] = recordWords[2];
        } else if (recordWords[0].compare("Leave") == 0) {
            order.push(pair<string, string>(recordWords[0], recordWords[1]));
        } else if (recordWords[0].compare("Change") == 0) {
            userInfo[recordWords[1]] = recordWords[2];
        }
    }
    
    int index = 0;
    while (!order.empty()) {
        if (order.front().first.compare("Enter") == 0) {
            answer.push_back(userInfo[order.front().second]);
            answer[index] += "님이 들어왔습니다.";
        } else if (order.front().first.compare("Leave") == 0) {
            answer.push_back(userInfo[order.front().second]);
            answer[index] += "님이 나갔습니다.";
        }
        order.pop();
        index++;
    }
    
    return answer;
}