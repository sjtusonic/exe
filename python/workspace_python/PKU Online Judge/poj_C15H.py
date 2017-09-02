# -*- coding:gb2312 -*-
__author__ = 'jc'

'''
C15H:Lucky Draw
查看 提交 统计 提问
总时间限制: 4000ms 内存限制: 65536kB
描述
In the Lucky village, people are crazy on a game called Lucky Draw. In this game,
N players stand in a line,
and each one is assigned an integer number.
Then, the village master would randomly choose
K continuous players.
Among these K players, the one who has the largest number will win the first prize of A dollars.
Also, the one with the second smallest number will win the second prize of B dollars.
Different players may have same numbers.
As an agreement, only the rightmost player who has the largest number owns the first prize,
and the leftmost player who has the second smallest number owns the second prize.
Note that the second smallest number should be greater than the smallest number.
Therefore, if all of these K players have the same number, no one will win the second prize.

A big problem in this game is about fairness.
Some players may have much more chance to win prizes than others.
So, the village master wants to know how fair the game is.
You should tell the village master how many players have the opportunity to win the prize.
In addition, you need to calculate the variance of the expected prize moneys of these potential prize winners.

输入
The first line contains four integers,
N, K, A, B, as described before. (1 ≤ K ≤ N ≤ 1000000, 1 ≤ A, B ≤ 1000).
{
N players stand in a line
K continuous players
first prize of A dollars
second prize of B dollars
}

The second line contains N integers, indicate the numbers assigned to those players,
listed from left to right. The numbers are guaranteed to fit in 32-bit signed integers.
输出
Output only one line containing an integer M and a real number V, separated by a single space.
M is the number of players who have any chance to win the prize money.
V is the variance of the expected prize money of these M players, rounded to four digits after the decimal point.

样例输入
6 3 1 2
1 2 1 3 3 3

样例输出
4 0.1719

提示
In the sample case, assuming players are represented by P1, P2, ..., P6 from left to right.
If players P1, P2, P3 are chosen, whose assigned numbers are 1 2 1, P2 wins 3 dollars.
If players P2, P3, P4 are chosen, whose assigned numbers are 2 1 3, P4 wins 1 dollar and P2 wins 2 dollars.
If players P3, P4, P5 are chosen, whose assigned numbers are 1 3 3, P5 wins 1 dollar and P4 wins 2 dollars.
If players P4, P5, P6 are chosen, whose assigned numbers are 3 3 3, only P6 wins 1 dollar.
P2, P4, P5 and P6 have a chance to win, and the expected prize moneys are 1.25, 0.75, 0.25 and 0.25 respectively.
The average expected prize money of these four players is 0.625 and the variance is 0.1719.
'''

def find_right_largest(ll):
    max=-999
    for ind in range(len(ll)):
        if ll[ind]>=max:
            maxInd=ind
            max=ll[ind]
    print("the right largest of {} is ll[{}]={}".format(ll,maxInd,ll[maxInd]))
    return maxInd

find_right_largest([1,2,3,2,3,1])

def find_left_2nd_smallest(ll):
    min=999
    min_2nd=999
    minInd=-1
    min_2ndInd=-1
    for ind in range(len(ll)):
        if ll[ind]<min:
            min_2ndInd=minInd
            min_2nd=min

            minInd=ind
            min=ll[ind]

        elif ll[ind]==min:
            pass
        elif ll[ind]<min_2nd:
            min_2ndInd=ind
            min_2nd=ll[ind]

    v=ll[min_2ndInd]
    if min_2ndInd==-1:
        v='NA'
    print("the left 2nd smallest of {} is ll[{}]={}".format(ll,min_2ndInd,v))
    return min_2ndInd

find_left_2nd_smallest([2,3,2,3,1])
find_left_2nd_smallest([1,2,3,2,3,1])
find_left_2nd_smallest([3,3,2,3,1])
find_left_2nd_smallest([1,2,3,2,3,1])
find_left_2nd_smallest([2,2,2,2,2])

N=6
K=3
A=1
B=2
plist=[1,2,1,3,3,3]

money=[]
for i in plist:
    money.append(0)

den=N-K+1
for i in range(N-K+1):
    choosen=plist[i:i+3]
    print("        {}".format(plist))
    print("CHOOSEN:{}{}{}".format(" X "*i,choosen," X "*(N-K-i)))
    max=-999
    min=999
    min_2nd=999

    prize_1_winner=find_right_largest(choosen)
    trueInd1=prize_1_winner+i
    print("UP the right largest is plist[{}]={}".format(trueInd1,plist[trueInd1]))
    prize_2_winner=find_left_2nd_smallest(choosen)
    money[prize_1_winner+i]+=A

    if prize_2_winner!=-1:
        trueInd2=prize_2_winner+i
        print("UP the left 2nd smallest is plist[{}]={}".format(trueInd2,plist[trueInd2]))
        money[prize_2_winner+i]+=B

for i in range(len(money)):
    money[i]=money[i]/den
print(money)