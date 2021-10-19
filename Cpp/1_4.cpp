#include <string>
#include <vector>

using namespace std;

int getDist(int num, int hand) {
    int tmp;
    tmp = abs(num - hand);
    if (tmp == 0) return (0);
    else if (tmp == 1 || tmp == 3) return (1);
    else if (tmp == 2 || tmp == 4 || tmp == 6) return (2);
    else if (tmp == 5 || tmp == 7 || tmp == 9) return (3);
    else return (4);
}

int isZero(int num) {
    if (num == 0) return (11);
    else return (num);
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int right = 12;
    int left = 10;
    int dist_l;
    int dist_r;

    for (int i=0; i<numbers.size(); i++) {
        if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7) {
            answer.push_back('L');
            left = numbers[i];
        } else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9) {
            answer.push_back('R');
            right = numbers[i];
        } else {
            numbers[i] = isZero(numbers[i]);
            dist_l = getDist(numbers[i], left);
            dist_r = getDist(numbers[i], right);
            if (dist_l == dist_r) {
                answer.push_back(toupper(hand[0]));
                if (hand == "right") right = isZero(numbers[i]);
                else left = isZero(numbers[i]);
            } else if (dist_l < dist_r) {
                answer.push_back('L');
                left = isZero(numbers[i]);
            } else {
                answer.push_back('R');
                right = isZero(numbers[i]);
            }
        }
            
    }
    return answer;
}