/* **************************************************************
    모음사전
************************************************************** */

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<char> vowels = { 'A', 'E', 'I', 'O', 'U' };
vector<string> dictionary;

void func(string word, int wordLength) {
    if (wordLength == word.length()) {
        dictionary.push_back(word);
        return; 
    }
    
    for (char vowel : vowels)
        func(word + vowel, wordLength);
}

int solution(string word) {
    int answer = 0;
    
    for (auto i=1; i<=5; i++) {
        string s = "";
        func(s, i);
    }
    
    sort(dictionary.begin(), dictionary.end());
    while (word != dictionary[answer])
        answer++;
    
    return answer + 1;
}