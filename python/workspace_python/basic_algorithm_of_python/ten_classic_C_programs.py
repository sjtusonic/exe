__author__ = 'jc'

import math
print('1=================')
#ll=[1,2,3,4]
ll=range(1,5,1)
cnt=0
for i in ll:
    for j in ll:
        for k in ll:
            if( i!=j and i!=k and j!=k):
                print('%d%d%d'%(i,j,k))
                cnt+=1

print('----')
print('totally '+str(cnt)+' number')


print('2=================')

input_num=35.5
list_band =[10,    20,  40, 60,  100, 999999]
list_ratio=[0.1,0.075,0.05,0.03,0.015,0.01]

length=len(list_band)
for ind in range(length):
    u=list_band[ind]
    v=list_ratio[ind]
    print("%d\t%d\t%f"%(ind,u,v))


left=input_num
avenue=0
old_u=0
for ind in range(length):
    u=list_band[ind]
    v=list_ratio[ind]

    if left<=u:
        add=left*v
        avenue+=add
        print('avenue+= %f * %f=%f'%(left,v,add))
        break
    else:
        diff=u-old_u
        add=diff*v
        avenue+=add
        print('avenue+= (%f-%f) * %f=%f'%(u,old_u,v,add ))
        left=left-diff

    old_u=u

print('avenue= %f'%(avenue))
avg_rate=avenue/input_num
print("average_rate=%f"%(avg_rate))


print('3=================')

def is_squre(n):
    up_bound=math.floor(math.sqrt(n))+1
    for i in range(1,up_bound,1):
        if n==i**2:
            print("%d = %d^2"%(n,i))
            return True
    return False

for i in range(100000):
    u=i+100
    v=i+168
    print("ITER: %d %d %d"%(i,u,v))
    if is_squre(i) and is_squre(u):
        print("GET: %d %d %d"%(i,u,v))
        break

print("======== a printvar proc:")
a = 123
b = 46
c = 'aaaa'

def printvar(varname):
    if varname in globals():
        print("Info: {} = {}".format(varname, globals()[varname]))

printvar('a')
printvar('b')
printvar('c')

print('4=================')
year=1992
month=3
day=15

if year%4==0:
    length_list=[31,29,31,30,31,30,31,31,30,31,30,31]
else:
    length_list=[31,28,31,30,31,30,31,31,30,31,30,31]

day_cnt=0
for i in range(1,month):
    printvar('i')
    day_add=length_list[i-1]
    printvar('day_add')
    day_cnt+=day_add
    printvar('day_cnt')

day_cnt+=day
printvar('day_cnt')

print('5=================')
#n0,n1,n2=input("input 3 number:").split(',')
ll=[6,5,4,2,1,11,5]
#printvar('n0')
#printvar('n1')

lls=sorted(ll,key=lambda item:int(item))
print(lls)

print('6=================')
print(" "+"*"*8+" ")
print("*"+" "*8+"*")
for i in range(4):
    print("*")
print("*"+" "*8+"*")
print(" "+"*"*8+" ")
print('7=================')
a=chr(176)
b=chr(219)
print("{}{}{}{}{}".format(b,a,a,a,b))
print("{}{}{}{}{}".format(a,b,a,b,a))
print("{}{}{}{}{}".format(a,a,b,a,a))
print("{}{}{}{}{}".format(a,b,a,b,a))
print("{}{}{}{}{}".format(b,a,a,a,b))
print('8=================')
for a in range(10):
    if a==2:
        print("-"*100)
    for b in range(10):
        if b==2:
            print("|",end="")
        print("%5d"%(a*b),end="")
        print(" ",end=" ")
    print()
print('9=================')
for a in range(9):
    for b in range(9):
        if (a+b)%2==0:
            print("  ",end="")
        else:
            print("**",end="")
    print()
print('10=================')

print("|^.^|^.^|")
for a in range(9):
    print(" "*9,end="")
    for b in range(9):
        if a==b:
            print("|_",end="")
        else:
            print("  ",end="")
    print()

