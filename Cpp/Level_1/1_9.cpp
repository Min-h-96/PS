/* **************************************************************
    소수 만들기
************************************************************** */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

bool checkPrime(int num) {
	if (num < 2) return false;
	int a = (int) sqrt(num);
	for (int i=2; i<=a; i++) {
        if (num % i == 0)
            return false;
    }
	return true;
}

// nums_len은 배열 nums의 길이입니다.
int solution(int nums[], size_t nums_len) {
    int answer = 0;
    int num = 0;

    for (int i=0; i<nums_len; i++) {
        for (int j=i+1; j<nums_len; j++) {
            for (int k=j+1; k<nums_len; k++) {
                num = nums[i] + nums[j] + nums[k];
                if (checkPrime(num))
                    answer++;
            }
        }
    }
    return answer;
}