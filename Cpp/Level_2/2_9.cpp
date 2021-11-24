/* **************************************************************
    타겟 넘버
************************************************************** */

/* DFS */

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

/* BFS */
#include <string>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;


int solution(vector<int> numbers, int target) {
	int answer = 0;
    queue<int> q;
    
    q.push(0);
    for (int i=0; i<numbers.size(); i++) {
        for (int j=0; j<pow(2, i); j++) {
            int element = q.front();
            q.pop();
            q.push(element + numbers[i]);
            q.push(element - numbers[i]);
        }
    }

    while (!q.empty()) {
        if (q.front() == target)
            answer++;
        q.pop();
    }
    
    return answer;
}