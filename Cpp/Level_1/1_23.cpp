/* **************************************************************
    부족한 금액 계산하기
************************************************************** */

using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = 0;
    
    for (int i=1; i<=count; i++) {
        answer += (long long)price * (long long)i;
    }
    if ((long long)money >= answer)
        return 0;
    return answer - (long long)money;
}