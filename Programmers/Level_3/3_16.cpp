/* **************************************************************
    보석 쇼핑
************************************************************** */

#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>

using namespace std;

set<map<string, int>> answers;

void findAnswer(vector<vector<string>>& suspects, int cnt, map<string, int> tmp) {
		// 각 b_id 별 용의자를 1명씩 넣었으면 재귀 탈출
    if (cnt == suspects.size()) {
				// 용의자를 1명씩 다 넣었을 때 그 수가 실제 banned_id.size() 랑 같으면 정답
        if (tmp.size() == suspects.size())
            answers.insert(tmp);
        return ;
    }

		// map 으로 한 이유는 1명의 user 가 2개의 용의자 집합에 포함될 수 있고, 그럴 때
		// set 으로 하면 용의자 집합 2번에 넣은 용의자를 지우고 싶은데 집합 1에서 지운 것도 같이 사라집니다.
    for (const auto& s : suspects[cnt]) {
        if (tmp.find(s) == tmp.end())
            tmp.insert({s, 1});
        else
            tmp[s]++;
        findAnswer(suspects, cnt + 1, tmp);
        tmp[s]--;
        if (tmp[s] == 0)
            tmp.erase(tmp.find(s));
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    vector<vector<string>> suspect_id;
    
    //banned_id 를 user_id 와 일일이 비교해서 가능성 있는 user_id 를 찾습니다.
    for (const auto& b_id : banned_id) {
        vector<string> s_ids;
        for (const auto& u_id : user_id) {
            //아이디 글자 수가 다르면 바로 넘어갑니다.
            if (b_id.size() != u_id.size())
                continue;
            //아이디 글자 수가 같다면 아이디 각 문자를 일일이 비교하여 일치할 가능성이 있는지 찾습니다.
            int i=-1;
            while (++i < b_id.length()) {
                if (b_id[i] == '*')
                    continue;
                if (b_id[i] != u_id[i])
                    break;
            }
            if (i == b_id.length())
                s_ids.push_back(u_id);
        }
        suspect_id.push_back(s_ids);
    }
    
    //조합 구하기
    map<string, int> tmp;
    findAnswer(suspect_id, 0, tmp);
    
    answer = answers.size();
    
    return answer;
}