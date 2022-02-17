/* **************************************************************
    단속카메라
************************************************************** */

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 1;
    
    sort(routes.begin(), routes.end());
    
    int camera = routes[0][1];
    for (const auto& route : routes) {
        if (camera < route[0]) {
            answer++;
            camera = route[1];
        }
        if (camera >= route[1])
            camera = route[1];
    }
    
    return answer;
}