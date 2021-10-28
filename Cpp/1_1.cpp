/* **************************************************************
    로또 최고 순위와 최저 순위
************************************************************** */

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int correct;
    int zero;

    correct = 0;
    zero = 0;
    for (int i=0; i<6; i++)
    {
        for (int j=0; j<6; j++)
        {
            if (lottos[i] == win_nums[j])
                correct = correct + 1;
        }
		if (lottos[i] == 0)
            zero = zero + 1;
    }
    if ((correct + zero) < 2)
        zero = 1;
    answer.push_back(7 - (correct + zero));
    if (correct < 2)
        correct = 1;
    answer.push_back(7 - correct);
    return answer;
}