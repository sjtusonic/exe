
def f():
    pass

def check_group(subset,f):
    for i in subset:
        for j in subset:
            for k in subset:
                if f(f(i,j),k)!=f(i,f(j,k)):
                    print ("combination rule is not match to: %d %d %d",i,j,k)
                    print ("f(i,j) is %d",f(i,j))
                    print ("f(j,k) is %d",f(j,k))
                    print ("f(i,j) is %d",f(i,j))
                    print ("f(i,j) is %d",f(i,j))
                    return False
    return True



#   MAIN:
subset=[0,1]
def f1(a,b):
    u=[
       [0,0],
       [0,0],
       ]
    u[0][0]=1
    u[0][1]=1
    u[1][0]=0
    u[1][1]=1
    return u[a][b]

#print f1(*subset)
print check_group(subset,f1)