/* **************************************************************
    광고 삽입
************************************************************** */

#include <string>
#include <vector>
#include <algorithm>

#define MAX 360000

using namespace std;

int convertTimeToInt(string time) {
    int hr = stoi(time) * 3600;
    int m = stoi(time.substr(3)) * 60;
    int s = stoi(time.substr(6));
    
    return hr + m + s;
}

string convertIntToTime(int i) {
    string time;
    
    //시간
    if (i / 3600 < 10)
        time += "0";
    time += to_string(i/3600) + ":";
    i %= 3600;
    
    //분
    if (i / 60 < 10)
        time += "0";
    time += to_string(i/60) + ":";
    i %= 60;
    
    //초
    if (i < 10)
        time += "0";
    time += to_string(i);
    
    return time;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    
    int p_time = convertTimeToInt(play_time);
    int a_time = convertTimeToInt(adv_time);
    
    vector<int> viewers(MAX, 0);
    for (const auto& log : logs) {
        int s_l_time = convertTimeToInt(log);
        int e_l_time = convertTimeToInt(log.substr(9));
        
        for (auto i=s_l_time; i<e_l_time; i++)
            viewers[i]++;
    }
    
    long long curTime = 0, maxTime = 0;
    int time = 0;
    //00:00:00 부터 광고를 시작했을 때의 누적 재생 시간(시작 기준)
    for (int i=0; i<a_time; i++) {
        curTime += viewers[i];
        maxTime += viewers[i];
    }
    
    //00:00:00 부터 1초씩 늘려가며 최대 누적 재생 시간인 시작 시각을 찾기
    //범위 : 00:00:01 ~ play_time - adv_time
    for (int i=1; i<=p_time-a_time; i++) {
        //1초씩 옮기는 과정 -> 0초일 때의 재생 시간은 빼고 다음 1초의 재생 시간은 더함.
        curTime += static_cast<long long>(viewers[i + a_time - 1] - viewers[i -1]);
        if (curTime > maxTime) {
            maxTime = curTime;
            time = i;
        }
    }
    
    answer = convertIntToTime(time);
    
    return answer;
}