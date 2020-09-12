# 백준 10996번 문제. 별 찍기 - 21
# running time 80ms
N = int(input())

lst1 = [' ' for i in range(N)]
lst2 = [' ' for i in range(N)]

for i in range(N):
    if N == 0:
        print('*')
    else:
        for j in range(N):
            if j % 2 == 0:
                lst1[j] = '*'
            else:
                lst2[j] = '*'
for x in range(N):
    for y in range(N):
        print(lst1[y], end='')
    print()
    for y in range(N):
        print(lst2[y], end='')
    print()

"""
다른 분들의 코드
#1
num = input()
num = int(num)
message_1 = ''
message_2 = ''
for count_1 in range(num-int(num/2)):
	message_1 += '* '
for count_2 in range(int(num/2)):
	message_2 += ' *'
for count in range(num):
	print(message_1 + '\n' + message_2)
*과 공백을 묶어서 running time을 56ms로 줄였다.

#2
n=int(input())
print(('* '*((n+1)//2)+'\n'+' *'*(n//2)+'\n')*n,end='')

*과 공백을 묶은 것은 위와 같지만,
// 연산자를 활용해 더욱 짧은 코드와 가장 짧은 running time(52ms)으로 해결했다.
"""
