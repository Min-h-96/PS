/* **************************************************************
    [1차] 캐시
************************************************************** */

#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    map<string, int> cache;
    
    for (auto& city : cities) {
        // 모든 알파벳 대문자로 변경
        for (auto i=0; i<city.length(); i++)
            city[i] = toupper(city[i]);
        
        // cacheSize 가 0 일때의 예외
        if (cacheSize == 0) {
            answer += 5;
            continue;
        }
        
        // cache 참조되지 않은 메모리 시간 1 씩 증가
        for (auto& m : cache)
            m.second++;
        
        // cache 메모리에 존재하는지 체크
        if (cache.find(city) != cache.end()) {
            answer += 1;
            cache[city] = 1;
        } else {
            // cache 메모리가 꽉 찬 경우
            if (cache.size() == cacheSize) {
                auto oldest = max_element(cache.begin(), cache.end(), 
                                          [](const auto& lhs, const auto& rhs) {
                                              return lhs.second < rhs.second; 
                                          });
                cache.erase(oldest->first);
            }
            cache.insert({city, 1});
            answer += 5;
        }
    }
    
    return answer;
}