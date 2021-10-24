#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// numbers_len은 배열 numbers의 길이입니다.
int solution(int numbers[], size_t numbers_len) {
    int answer = 45;
    int num = 0;
    
    for (int i=0; i<numbers_len; i++) {
        num += numbers[i];
    }
    answer -= num;
    return answer;
}