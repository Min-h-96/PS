/* **************************************************************
    베스트 앨범
************************************************************** */

#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(const pair<string, int>& a, const pair<string, int>& b) {
    if (a.second > b.second)
        return a > b;
    return b > a;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    map<string, int> bestGenres;
    //pair.first 는 고유 번호, pair.second 는 해당 노래가 재생된 횟수
    map<string, vector<pair<int, int>>> best;
    
    for (auto i=0; i<plays.size(); i++) {
        
        //장르별 재생된 수의 합 구하기
        if (bestGenres.find(genres[i]) != bestGenres.end())
            bestGenres[genres[i]] += plays[i];
        else {
            bestGenres.insert({genres[i], plays[i]});
            best.insert({genres[i], vector<pair<int, int>>()});
        }    
        
        //장르별 가장 많이 재생된 곡 찾기(최대 2개)
        if (best[genres[i]].size() == 0)
            best[genres[i]].push_back({i, plays[i]});
        else if (best[genres[i]].size() == 1) {
            if (plays[i] > best[genres[i]][0].second) {
                pair<int, int> tmp = best[genres[i]].back();
                best[genres[i]][0].first = i;
                best[genres[i]][0].second = plays[i];
                best[genres[i]].push_back(tmp);
            } else
                best[genres[i]].push_back({i, plays[i]});
        } else {
            //현 2위랑 재생 수 비교
            if (plays[i] > best[genres[i]][1].second) {
                //현 1위랑 재생 수 비교
                if (plays[i] > best[genres[i]][0].second) {
                    //1위보다 크면 1위를 2위로 내리고 1위 교체
                    best[genres[i]][1].first = best[genres[i]][0].first;
                    best[genres[i]][1].second = best[genres[i]][0].second;
                    
                    best[genres[i]][0].first = i;
                    best[genres[i]][0].second = plays[i];
                } else {
                    //2위보다는 크지만, 1위보다는 작다면 2위만 교체
                    best[genres[i]][1].first = i;
                    best[genres[i]][1].second = plays[i];
                }
            }
        }
    }
    
    //map 의 value 를 기준으로 내림차순으로 정렬
    vector<pair<string, int>> tmp(bestGenres.begin(), bestGenres.end());
    sort(tmp.begin(), tmp.end(), cmp);
    
    for (const auto& t : tmp) {
        for (const auto& b : best[t.first])
            answer.push_back(b.first);
    }
    
    return answer;
}