__author__ = 'jc'

def p(n,total):
    if n==1:
        print(" "*(total-1)+"*",end="")
    else:
        p(n-1,total)
        print()
        u=2*n-1
        print(" "*(total-n)+"*"*u,end="")

def p_top(u):
    p(u,u)

p_top(60)