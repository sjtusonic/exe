__author__ = 'jc'

import math


def is_prime(N):
    flag_is_prime=True
    up=math.floor(N**0.5)
    for i in  range(2,up+1):
        if N % i == 0:
            flag_is_prime=False
            break

    return flag_is_prime

def find_prime(N):
    list_prime=[]
    for i in range(2,N):
        list_prime.append(i)

    for i in list_prime:
        if is_prime(i):
            for j in range(i+i,N,i):
                if j in list_prime:
                    list_prime.remove(j)

    return list_prime

def differential(ll):
    old_i=0
    r = []
    for i in ll:
        #print(str(i))
        diff=i-old_i
        r.append(diff)
        old_i=i
    return r

total_list=[]
u=find_prime(100000)
total_list.append(u)
u=differential(u)
total_list.append(u)
u=differential(u)
total_list.append(u)
u=differential(u)
total_list.append(u)
u=differential(u)
total_list.append(u)
u=differential(u)
total_list.append(u)
u=differential(u)
total_list.append(u)
u=differential(u)
total_list.append(u)
u=differential(u)
total_list.append(u)
u=differential(u)
total_list.append(u)
#l1=differential(l0)
#l2=differential(l1)
#l3=differential(l2)
#l4=differential(l3)

l0=total_list[0]
for index in range(len(l0)):
    for i in total_list:
        #print(str(l0[i])+"\t"+str(l1[i])+"\t"+str(l2[i])+"\t"+str(l3[i])+"\t"+str(l4[i]))
        print ("%10d"%(i[index]),end="")
    print()



'''
list_prime=[]
for i in range(2,10):
    list_prime.append(i)
for i in list_prime:
    if 6 in list_prime:
        list_prime.remove(6)
    print('ITER: '+str(i))
'''