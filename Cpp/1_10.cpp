#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    int completion_size = completion.size();
    
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    
    for (int i=0; i<completion_size; i++) {
        if (completion.back() == participant.back()) {
            completion.pop_back();
            participant.pop_back();
        } else {
            break;
        }
    }
    answer = participant.back();
    
    return answer;
}