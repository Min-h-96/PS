/* **************************************************************
    신규 아이디 추천
************************************************************** */

#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    string answer = "";
    
    //1단계
    for (int i=0; i<new_id.length(); i++) {
        if ('A' <= new_id[i] && new_id[i] <= 'Z')
            new_id[i] = tolower(new_id[i]);
    }
    //2단계
    for (int i=0; i<new_id.length(); i++) {
        if (('a' <= new_id[i] && new_id[i] <= 'z') || ('0' <= new_id[i] && new_id[i] <= '9') || 
            new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.')
            continue;
        new_id.erase(i--, 1);
    }
    //3단계
    for (int i=0; i<new_id.length(); i++) {
        if (new_id[i + 1] != 0 && new_id[i] == '.' && new_id[i + 1] == '.') {
            new_id.erase(i--, 1);
        }
    }
    //4단계
    if (new_id[0] == '.')
        new_id.erase(0, 1);
    if (new_id[new_id.length() - 1] == '.')
        new_id.erase(new_id.length() - 1, 1);
    //5단계
    if (new_id == "")
        new_id.push_back('a');
    //6단계
    if (new_id.length() > 15)
        new_id.erase(15, new_id.length() - 15);
    if (new_id[new_id.length() - 1] == '.')
        new_id.erase(new_id.length() - 1, 1);
    //7단계
    while (new_id.length() <= 2)
        new_id.push_back(new_id[new_id.length() - 1]);
    answer.append(new_id);
    return answer;
}