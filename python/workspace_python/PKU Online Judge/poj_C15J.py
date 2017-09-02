__author__ = 'jc'

import math
import random
import numpy as np
#import pygame,sys
#from pygame.locals import *

def four_axis_aligned(p1,p2,p3,p4):
    lx=[p1[0],p2[0],p3[0],p4[0]]
    ly=[p1[1],p2[1],p3[1],p4[1]]
    lx_uniq=np.unique(lx)
    ly_uniq=np.unique(ly)
    if len(lx_uniq)==2 and len(ly_uniq)==2:
        return True
    else:
        return False

def three_maybe_axis_aligned(p1,p2,p3):
    lx=[p1[0],p2[0],p3[0]]
    ly=[p1[1],p2[1],p3[1]]
    lx_uniq=np.unique(lx)
    ly_uniq=np.unique(ly)
    if len(lx_uniq)>2 or len(ly_uniq)>2:
        return False
    else:
        return True

star=[]

WIDTH=10
HEIGHT=100

N=10
for i in range(N):
    flag_match=1
    while flag_match:
        flag_match=0
        rx=random.randint(1,WIDTH)
        ry=random.randint(1,HEIGHT)
        for u in star:
            if u[0]==rx and u[1]==ry:
                flag_match=1

    cord=[rx,ry]
    star.append(cord)

ans_list=[]
for i in range(N):
    print("ITER: %d"%(i))
    for j in range(i+1,N):
        if i==j:
            continue
        for k in range(j+1,N):
            if k==i or k==j:
                continue
            if not three_maybe_axis_aligned(star[i],star[j],star[k]):
                continue
            for l in range(k+1,N):
                if l==i or l==j or l==k:
                    continue
                pass
                if four_axis_aligned(star[i],star[j],star[k],star[l]):

                    new_clct={i,j,k,l}
                    if not new_clct in ans_list:
                        ans_list.append({i,j,k,l})
                        print("AXIS_ALIGNED:")
                        print(str(star[i]))
                        print(str(star[j]))
                        print(str(star[k]))
                        print(str(star[l]))
                        #plt.plot(star[i],star[j],star[k],star[l])


print('================END')

