# -*- coding:gb2312 -*-

__author__ = 'jc'
'''
C15I:The New MindSwitcher
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
Professor Farnsworth and Amy Wong create The New MindSwitcher!
A The New MindSwitcher allows two users to switch minds with each other without any limits.
There are N people have already tried it,
and each of them may have other's mind now.
Obviously, it is a great invention, but it also leads to trouble.
People who do evil can use it to escape from punishment, or even set others up.
When this realization hit, Professor Farnsworth decides to return every mind back to its original body.
There are a lot of The New MindSwitchers, which means in each turn,
any number of pairs of people can switch minds.
However, no one can switch minds with himself/herself or with more than one people at the same time.
To avoid getting into bigger trouble, it is forbidden to introduce new people who did not have used
The New MindSwitcher.
And most importantly, to finish this work as soon as possible,
Professor Farnsworth wants to arrange this process to minimize the number of turns.

输入
The first line contains an integer N. 2 ≤ N ≤ 1000.
Then follows N lines, each line contains two strings: B, M,
separated by a single space, describe that the person B’s body has the person M’s mind at this time.
Both B and M only contain alphabetic characters. 1 ≤ |B|, |M| ≤ 15.
Note that different people have different names.

输出
The first line contains an integer T -- the minimum possible number of turns in order to
return every mind back to its original body.
Then follows T turns. For each turn:
The first line contains an integer S, describes the number of The New MindSwitchers needed in this turn.
Then follows S lines, each line contains two strings: B1, B2,
describe that one of The New Mindswitchers is serving for body of B1 and body of B2 to switch their minds.
You should also make sure that nobody is appeared multiple times in one turn,
and there is no additional person. If there are several solutions, output any one of them.

样例输入
5
Farnsworth Amy
Amy Bender
Bender Farnsworth
Zoidberg Fry
Fry Zoidberg
样例输出
2
1
Farnsworth Amy
2
Farnsworth Bender
Fry Zoidberg
'''

import math
import random


def printvar(varname):
    if varname in globals():
        print("Info: {} = {}".format(varname, globals()[varname]))


def is_permutation(ll):
    lnew=ll[:]
    lnew.sort()
    for i in range(len(lnew)):
        if i != lnew[i]:
            print("list is not permutation: {}".format(lnew))
            return False
    return True


print(is_permutation([1, 2, 6]))


def gen_a_shuffle(N):
    ll = []
    for i in range(N):
        ll.append(i)
    random.shuffle(ll)
    return ll


def find_a_ring(ll):
    print("Info: calling proc find_a_ring: {}".format(ll))
    loc=[]
    for i in range(len(ll)):
        loc.append(i)
    print("                        marker: {}".format(loc))
    if not is_permutation(ll):
        return False
    ans_list = []
    ind = 0
    while not ind in ans_list:
        print("push {} into {}".format(ind,ans_list))
        ans_list.append(ind)
        ind = ll[ind]
    '''
    # the last one iteration
    print("push {} into {}".format(ind,ans_list))
    ans_list.append(ind)
    ind = ll[ind]
    '''
    print("proc find_a_ring: return {}".format(ans_list))
    return ans_list

'''
u = find_a_ring([1, 2, 3, 4, 6,5, 7, 8, 0])
print(u)
'''

def divide_into_rings(ll):
    ans_list = []
    pass

def divide_by_index_list(ll,index_list):
    print("call divide_by_index_list: {} {}".format(ll,index_list))
    out_list=[]
    left_list=[]
    for u in ll:
        print("ITER:"+str(u))
        if u in index_list:
            out_list.append(u)
            left_list.append(-1)
        else:
            out_list.append(-1 )
            left_list.append(u)
    return [out_list,left_list]

N = 10
name_list = []

for i in range(N):
    name = "body{}".format(i)
    name_list.append(name)

print(name_list)
init_perm = gen_a_shuffle(N)
printvar('init_perm')

for i in range(len(name_list)):
    for j in range(len(init_perm)):
        if i == j:
            print("{}->HEAD{}".format(name_list[i], init_perm[j]))

ll=[1, 2, 3, 4, 6,5, 7, 8, 0]
u = find_a_ring(ll)
#find_a_ring(init_perm)

r=divide_by_index_list(ll,u)
a,b=r
printvar('a')
printvar('b')