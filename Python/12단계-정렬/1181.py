# 백준 1181번 문제. 단어 정렬
import sys

N = int(sys.stdin.readline())

words = []

for n in range(N):
    word = sys.stdin.readline()
    words.append(word[:-1])

words = list(set(words))
new_words = []

for n in range(len(min(words, key=len)), len(max(words, key=len))+1):
    lst = []
    for w in words:
        if len(w) == n:
            lst.append(w)

    for w in sorted(lst):
        new_words.append(w)

for word in new_words:
    print(word)

# 224ms 33144KB : words = list(set(words)) 을 사용하여 중복을 제거한 경우

# 3900ms 31080KB
# if word[:-1] not in words:
#    words.append(word[:-1])
# 을 사용하여 중복을 제거한 경우
