/* **************************************************************
    2016년
************************************************************** */

#include <string>
#include <vector>

using namespace std;
string date[] = {"THU", "FRI", "SAT", "SUN", "MON", "TUE", "WED"};
vector<int> month_day = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

string solution(int a, int b) {
    int answer = 0;
    int total_day = 0;

    for (int i=0; i<a-1; i++) {
        total_day += month_day[i];
    }
    total_day += b;
    answer = total_day % 7;
    
    return date[answer];
}