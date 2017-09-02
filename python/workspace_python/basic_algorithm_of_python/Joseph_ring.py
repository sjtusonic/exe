__author__ = 'jc'


def show():
    print("-----------------------")
    for i in list_name:
        print(str(i)+"\t",end=" ")
    print()
    for i in list_name:
        print(str(hash_live[i])+"\t",end=" ")
    print()
    print("-----------------------")

TOTAL_NUMBER=30 ;# total number
PERIOD=9 ;# period
FROM=1 ;# from

list_name=range(1,TOTAL_NUMBER+1)
hash_live={}

for i in list_name:
    hash_live[i]=1
    #print("name:"+str(i)+" live"+str(hash_live[i]))

dead_cnt=0
counter=0
pointer=0

print ("============")
print ("START:")
print ("============")


show()

while dead_cnt<=TOTAL_NUMBER-PERIOD:
    pointer+=1
    if pointer>TOTAL_NUMBER:
        pointer=1

    if hash_live[pointer]==1:
        counter+=1
        print("pointer"+str(pointer)+" says:"+str(counter),end="")

        if counter%PERIOD==0:
            print(' DIE!')
            hash_live[pointer]=0
            dead_cnt+=1
            counter=0
            show()
        else:
            print()
    else:
        print("pointer"+str(pointer)+" is DEAD")



print ("============")
print ("END:")
print ("============")


show()