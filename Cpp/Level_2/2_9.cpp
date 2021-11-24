/* **************************************************************
    타겟 넘버
************************************************************** */

#include <string>
#include <vector>

using namespace std;

void dfs(vector<int> numbers, int target, int& answer, int sum, int depth){
    if (depth == numbers.size()){
        if (sum == target) 
						answer++;
        return;
    }
    dfs(numbers, target, answer, sum + numbers[depth], depth + 1);
    dfs(numbers, target, answer, sum - numbers[depth], depth + 1);
}

int solution(vector<int> numbers, int target) {
		int answer = 0;
    dfs(numbers, target, answer, 0, 0);
    return answer;
}