/* **************************************************************
    폰켓몬
************************************************************** */

#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> nums)
{
    vector<int> answer;
    int j;

    for (int i : nums) {
        if (answer.size() == 0) {
            answer.push_back(i);
            continue;
        }
        if (answer.size() == nums.size() / 2)
            break;
        j = 0;
        while (i != answer[j] && j < answer.size()) {
            j++;
        }
        if (j == answer.size())
            answer.push_back(i);
        
    }
    return answer.size();
}

/*
unique() 를 이용한 vector 의 중복 원소 제거
*/
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> nums)
{
    int num = nums.size() / 2;

    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    if (nums.size() > num)
        return num;
    else
        return nums.size();
}