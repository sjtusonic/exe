#coding:utf-8
#!/usr/bin/env python

# http://www.iwr.uni-heidelberg.de/groups/comopt/software/TSPLIB95/tsp/
'''
this is a simulator of scan chain reorder
'''
    

#    MODULE IMPORTS:
import matplotlib.pyplot as plt   
import random
import re
import os
import time
import copy

#    GLOBAL VAR:
W=1000
H=1000


LENGTH=3
GEN_PLOT=0
'''
set DUMP_FILE to 1 to re-gen cfg file by random, when you change 'LENGTH', cfg file should re-gen
'''
DUMP_FILE=1

#    PROC:
def calc_dist_hamiton(x1,y1,x2,y2,domain1=999,domain2=999):
    derate_value=0.2
    v=abs(x1-x2)+abs(y1-y2)
    PUNISH=v*derate_value*1.5*100 # length of clock net w/o crpr may be 1.5 of data path distance
    if domain1==domain2:
        return v
    else:
        return v+PUNISH
    
    
def calc_dist_hamiton_exp(x1,y1,x2,y2,domain1=999,domain2=999):
    derate_value=0.2
    v_linear=abs(x1-x2)+abs(y1-y2)
    
    if v_linear<10:
        v=v_linear
    elif v_linear <100:
        v=v_linear*10
    elif v_linear <1000:
        v=v_linear*100
    else :
        v=v_linear*1000
        
    PUNISH=v*derate_value*1.5*100 # length of clock net w/o crpr may be 1.5 of data path distance
    if domain1==domain2:
        return v
    else:
        return v+PUNISH

def calc_dist(x1,y1,x2,y2):
    return ((x1-x2)**2 + (y1-y2)**2)**0.5

#print calc_dist(3,4,5,6)

def find_nearest(node_name,left,mode=0):
    #    MODE=0:linear; MODE=1:exp
    debug=0
    if debug:   print '---------------------------------------------'
    if debug:   print 'calling find_nearest: %d'%(node_name)
    if debug:   print left
    smallest_dist=9999999
    ans_name=-1
    for i in left:
        if i==-1:
            continue
        if mode==0:
            dist=calc_dist_hamiton(rx[node_name],ry[node_name],rx[i],ry[i],r_cg_domain[node_name],r_cg_domain[i])
            dist_pure=calc_dist_hamiton(rx[node_name],ry[node_name],rx[i],ry[i])
        else:
            dist=calc_dist_hamiton_exp(rx[node_name],ry[node_name],rx[i],ry[i],r_cg_domain[node_name],r_cg_domain[i])
            dist_pure=calc_dist_hamiton_exp(rx[node_name],ry[node_name],rx[i],ry[i])
            
        if debug:   print '%d is %d (%d)'%(i, dist,dist_pure)
        if dist<smallest_dist:
            if i!=node_name:
                smallest_dist=dist
                ans_name=i
    
    if debug:   print '=smallest is node %d: %d'%(ans_name, smallest_dist)
    if debug:   print '---------------------------------------------'
    return ans_name,smallest_dist

def calc_total_dist (ans_list,rname,rx,ry,r_cg_domain,mode=0):
    '''
    calc total cost of NET LENGTH of a config 'ans_list'
    '''
    debug=0
    if debug:   print 'Info: proc calc_total_dist'
    total_dist=0
    for i in range(len(ans_list)):
        if i==len(ans_list)-1:
            break
        last=ans_list[i]
        curr=ans_list[i+1]
        if mode==0:
            dist=calc_dist_hamiton(rx[curr],ry[curr],rx[last],ry[last],r_cg_domain[curr],r_cg_domain[last])
            dist_pure=calc_dist_hamiton(rx[curr],ry[curr],rx[last],ry[last])
        else:
            dist=calc_dist_hamiton_exp(rx[curr],ry[curr],rx[last],ry[last],r_cg_domain[curr],r_cg_domain[last])
            dist_pure=calc_dist_hamiton_exp(rx[curr],ry[curr],rx[last],ry[last])
        if debug:   print 'reg: %d (%d, %d) \tlast is (%d,%d), \tdist: %d (%d)' %(curr,rx[curr],ry[curr],rx[last],ry[last],dist,dist_pure)
        #print 'from %d to %d, incr %d, dist %d'%(last,curr,dist,0)
        total_dist=total_dist+dist
    if debug:   print 'TOTAL DIST of'
    if debug:   print ans_list
    if debug:   print 'IS: %d'%(total_dist)
    return total_dist

def cal_dist_ac(r_name1,r_name2):
    curr=r_name1
    last=r_name2
    return calc_dist_hamiton(rx[curr],ry[curr],rx[last],ry[last],r_cg_domain[curr],r_cg_domain[last])
    

def swap (ll,i,j):
    llout=range(LENGTH)
    for iter in range(LENGTH):
        llout[iter]=0
    for iter in range(LENGTH):
        llout[iter]=ll[iter]
    
    temp=llout[i]
    llout[i]=llout[j]
    llout[j]=temp

    return llout
    
def dump_file(scan_def='scan.def',cfg_file='scan.cfg.txt'):
    print 'Info: dump file: %s %s'%(scan_def, cfg_file)
    out_file=open(scan_def,'w')
    cfg_file=open(cfg_file,'w')
    out_file.write('name\t\tX\tY\trcg\n')
        
    for i in range(LENGTH):
        out_file.write('reg'+str(rname[i]))
        out_file.write(': \t(')
        out_file.write(str(rx[rname[i]]))
        out_file.write(', \t')
        out_file.write(str(ry[rname[i]]))
        out_file.write(') \t')
        out_file.write(str(r_cg_domain[rname[i]]))
        out_file.write('\n')
        #print 'reg: %s is located in %s, %s' %(rname[i], rx[i], ry[i])
        cfg_file.write(str(rname[i]))
        cfg_file.write('\t')
        cfg_file.write(str(rx[rname[i]]))
        cfg_file.write('\t')
        cfg_file.write(str(ry[rname[i]]))
        cfg_file.write('\t')
        cfg_file.write(str(r_cg_domain[rname[i]]))
        cfg_file.write('\n')
    
    out_file.close()
    cfg_file.close()
    
def read_cfg_file(cfg_file='scan.cfg.txt'):
    cfg_file=open(cfg_file,'r')
    print 'Info: read in %s'%(cfg_file)
        
    i=0
    for line in cfg_file:
        words=line.split()
        rname[i]=int(words[0])
        rx[rname[i]]=int(words[1])
        ry[rname[i]]=int(words[2])
        r_cg_domain[rname[i]]=int(words[3])
        print 'GET rname: %d rx %d ry %d rcg %d'%(rname[i],rx[rname[i]],ry[rname[i]],r_cg_domain[rname[i]])
        i+=1
        
    cfg_file.close()

def gen_c (ll,ptr=0,force_start=-1):
    print 'Info: calling gen_c with ptr: '+str(ptr)
    global best_dist
    global best_ll_yet
    
    if len(ll)>7:
        print "Warning: length of ll is too large, full_mode is turned off."
        full_iter_mode=0
    else:
        full_iter_mode=1
    
    if force_start!=-1:
        ll[0],ll[force_start]=ll[force_start],ll[0]
    
    #print ll
    
    
    if ptr==len(ll):
        print '---------------'+str(ll)
        ########################
        #
        #calc_distance
        total_dist=calc_total_dist (ll,rname,rx,ry,r_cg_domain)
        if total_dist<best_dist:
            best_dist=total_dist
            best_ll_yet=copy.deepcopy(ll)
        print 'total dist: %d'%(total_dist)
        ########################
        return ll
    
    for i in range(ptr,len(ll)):
        ll[ptr],ll[i]=ll[i],ll[ptr]
        
        #ll[1:]=copy.deepcopy(gen_c(ll[1:]))
        if full_iter_mode==1:
            step=1
        else:
            #step=len(ll)/3
            return ll
        gen_c(ll,ptr+step)
        
        ll[ptr],ll[i]=ll[i],ll[ptr]
         
    return ll
        
def plot_a_cfg(ans,plot_code='141',clr_str='bs-',label_v='ans',title_v='solve by algor: NA'):
    global rx
    global ry
    
    print 'ans: '+str(ans)
    ans_x=[]
    ans_y=[]
    for i in ans:
        ans_x.append(rx[i])
        ans_y.append(ry[i])
    
    plt.subplot(plot_code)
    plt.axis([0,W,0,H],aspect='equal')
    #plt.legend()
    '''
    print 'x: '+str(ans_x)
    print 'y: '+str(ans_y)
    '''
    plt.plot(ans_x,ans_y,clr_str,label=label_v)
    
    xp=range(0,LENGTH)
    yp=range(0,LENGTH)
    
    SHOW_NUM_ANNOTATE=1
    if SHOW_NUM_ANNOTATE==1:
        for i in range(len(ans_x)):
            if i%5==0:
                ss='%s(%s)'%(str(i),str(ans[i]))
                plt.annotate(ss,xy=(ans_x[i],ans_y[i]))
    
    for i in range(len(ans_x)-1):
            xp[i]=ans_x[i+1]-ans_x[i]
            yp[i]=ans_y[i+1]-ans_y[i]
    
    #print "xp:"+str(xp)
    SHOW_ARROW=1
    if SHOW_ARROW: plt.quiver(ans_x[:-1], ans_y[:-1],xp[:-1], yp[:-1],pivot='tail',minlength=1,minshaft=10,width=0.001)
    plt.title(title_v)

def ratio(num,ll):
    rat_str='%.2f%%'%(100*float(num)/total_dist0)
    return " rat:"+str(rat_str)+"\nstr: "+str(ll)
def get_smallest(list):
    small=999999
    for i in list:
        if i<small:
            small=i
    return small

def get_largest(list):
    large=-999999
    for i in list:
        if i>large:
            large=i
    return large

'''
    STRUCTURE DEFINITION:
#
line=[p1,p2]
p1=[x1,y1]
p2=[x2,y2]

#
box=[llx,lly,urx,ury]

#
rect=[p1,p2,p3,p4]
p1=[x1,y1]
......

'''
def gen_box(line1):
    p1,p2=line1
    x1,y1=p1
    x2,y2=p2
    
    llx=get_smallest([x1,x2])
    lly=get_smallest([y1,y2])
    urx=get_largest([x1,x2])
    ury=get_largest([y1,y2])
    
    return [llx,lly,urx,ury]
    
def point_is_in_box(p,b):
    x,y=p
    llx,lly,urx,ury=b 
    if x>=llx and x<=urx:
        if y>=lly and y<=ury:
            return True
    
    return False

def points_exclude_wrong(line1,line2):
    
    l1p1,l1p2=line1

    l2p1,l2p2=line2
    
    b1=gen_box(line1)
    b2=gen_box(line2)
    
    if not point_is_in_box(l1p1,b2):
        if not point_is_in_box(l1p2,b2):
            if not point_is_in_box(l2p1,b1):
                if not point_is_in_box(l2p2,b1):
                    return True
    
    return False

def points_exclude(line1,line2):
    l1p1,l1p2=line1
    l2p1,l2p2=line2
    
    l1p1x,l1p1y=l1p1
    l1p2x,l1p2y=l1p2
    l2p1x,l2p1y=l2p1
    l2p2x,l2p2y=l2p2
    
    if max(l1p1x,l1p2x)<min(l2p1x,l2p2x):return True
    if max(l1p1y,l1p2y)<min(l2p1y,l2p2y):return True
    
    if max(l2p1x,l2p2x)<min(l1p1x,l1p2x):return True
    if max(l2p1y,l2p2y)<min(l1p1y,l1p2y):return True
    
    return False
    
def v_add(v1,v2):
    x1,y1=v1
    x2,y2=v2
    return [x1+x2,y1+y2]

def v_sub (v1,v2):
    return v_add(v1,v_minus(v2))

def v_minus(v1):
    x1,y1=v1
    return [-x1,-y1]

def inner_product(v1,v2):
    x1,y1=v1
    x2,y2=v2
    return x1*x2+y1*y2
    
def outer_product_algebra(v1,v2):
    x1,y1=v1
    x2,y2=v2
    return x1*y2-x2*y1

def vector_cross(line1,line2):  # 'KuaLi' in Chinese
    '''
    l2p1------------------->l1p2
        |                  |
        |                  |
        |                  |
    l1p1------------------->l2p2
    '''
    l1p1,l1p2=line1
    l2p1,l2p2=line2

    vL=v_sub(l2p1,l1p1) # Left
    vB=v_sub(l2p2,l1p1) # Bottom
    vT=v_sub(l1p2,l2p1) # Top
    
    vLine1=v_sub(l1p2,l1p1)
    vLine2=v_sub(l2p2,l2p1)
    
    if outer_product_algebra(vL,vLine1) * outer_product_algebra(vB,vLine1) <0:
        if outer_product_algebra(v_minus(vL),vLine2) * outer_product_algebra(vT,vLine2) <0:
            return True
        
    return False
        
def cross(line1,line2):
    if not points_exclude(line1,line2):
        if vector_cross(line1,line2):
            return True
    return False

def reg_pair2line(r1,r2):
    x1=rx[r1]
    y1=ry[r1]
    x2=rx[r2]
    y2=ry[r2]
    return [[x1,y1],[x2,y2]]

def reverse(series,from_ind,to_ind): 
    print 'Info: calling reverse to swap ind: %d and %d'%(from_ind,to_ind)
    #print '%d(%d)->%d(%d),%d(%d)->%d(%d)'%(from_ind-1,series[from_ind-1],from_ind,series[from_ind],\
    #                                       to_ind,series[to_ind],to_ind+1,series[to_ind+1])
    t=from_ind-1
    print '%d(%d)[%d,%d]'%(t,series[t],rx[series[t]],ry[series[t]]),
    print '->',
    t=from_ind
    print '%d(%d)[%d,%d]'%(t,series[t],rx[series[t]],ry[series[t]]),
    print '|',
    t=to_ind
    print '%d(%d)[%d,%d]'%(t,series[t],rx[series[t]],ry[series[t]]),
    print '->',
    t=to_ind+1
    print '%d(%d)[%d,%d]'%(t,series[t],rx[series[t]],ry[series[t]])
    
    u=series[from_ind:to_ind+1]
    u.reverse()
    series[from_ind:to_ind+1]=u
    
    
    t=from_ind-1
    print '%d(%d)[%d,%d]'%(t,series[t],rx[series[t]],ry[series[t]]),
    print '->',
    t=from_ind
    print '%d(%d)[%d,%d]'%(t,series[t],rx[series[t]],ry[series[t]]),
    print '|',
    t=to_ind
    print '%d(%d)[%d,%d]'%(t,series[t],rx[series[t]],ry[series[t]]),
    print '->',
    t=to_ind+1
    print '%d(%d)[%d,%d]'%(t,series[t],rx[series[t]],ry[series[t]])
    
    return series


def rand_choose_by_weight (ll,weight_ll):
    debug=1
    if debug:   
        print 'calling rand_choose_by_weight'
        print ll
        print weight_ll
    L=len(ll)
    if L!=len(weight_ll):
        print "Error in rand_choose_by_weight!"
        return False
    
    weight_norm=copy.deepcopy(weight_ll)
    sum=sum_of_ll(weight_ll)
    for i in range(len(weight_norm)):  #    normalize weight
        weight_norm[i]=float(weight_ll[i])/sum
    
    rand=random.uniform(0,1)
    index=0
    bound=weight_norm[0]
    while(bound<rand):
        bound+=weight_norm[index]
        index+=1
        
    return ll[index-1]
    #zjc
'''
print '---------'        
for i in range(100):
    print rand_choose_by_weight([0,1,2],[0,1,20]),
''' 
def sum_of_ll (ll):
    sum=0
    for i in ll:
        sum+=i
    return sum
    
#===============================================================================
# #    INPUT:
#===============================================================================
#series=[9,8,7,6,5,4,3,2,1,0]
series=range(LENGTH)
start_point=series[0]
#    choose Lower-left reg as start point:

rname=range(LENGTH)
        
rx=range(LENGTH)
ry=range(LENGTH)

#===============================================================================
# #    INIT:
#===============================================================================
away_from_zero=W+H
last_away_from_zero=W+H
for i in range(LENGTH):
    x=random.randint(0,W)
    y=random.randint(0,H)
    rname[i]=i
    rx[rname[i]]=x
    ry[rname[i]]=y
    #print 'reg: %s is located in %s, %s' %(rname[i], rx[i], ry[i])
    
#===============================================================================
# # RCG CONFIG:
#===============================================================================
r_cg_domain=range(LENGTH)
USE_SAME_CG=1

if USE_SAME_CG==1:
    for i in range(LENGTH): r_cg_domain[i]=1
    r_cg_domain[1]=1
else:
    for i in range(LENGTH): 
        if rx[rname[i]]<400 and  ry[rname[i]]<400:
            r_cg_domain[rname[i]]=2
        else:
            r_cg_domain[i]=1
        
#===============================================================================
# #    DUMP TO FILE:
#===============================================================================
if DUMP_FILE:
    dump_file()
#===============================================================================
# #    READ IN CFG FILE:
#===============================================================================
read_cfg_file()

#===============================================================================
# #    START POINT:
#===============================================================================
for i in range(LENGTH):
    away_from_zero=rx[rname[i]]+ry[rname[i]]
    if away_from_zero<last_away_from_zero:
        start_point=i
        last_away_from_zero=away_from_zero
    
print 'Start point is %d, at %d, %d'%(start_point,rx[start_point],ry[start_point])

    
#===============================================================================
# #    MAIN:
#===============================================================================
total_dist=calc_total_dist (series,rname,rx,ry,r_cg_domain,mode=0)
print 'total dist is %d'%(total_dist)
print 'average dist: %d'%(total_dist/LENGTH)
total_dist0=total_dist
#(ans,dist)=find_nearest(0,left)

#===============================================================================
# #    exhaustion
#===============================================================================
print "Info: Start step0"
best_ll_yet=range(LENGTH)
best_dist=(H+W)*LENGTH*10
gen_c(range(LENGTH),1,start_point)

print 'the best solution(dist=%d) is:'%(best_dist)
print best_ll_yet

#===============================================================================
# #    nearest
#===============================================================================
print "Info: Start step1"
ans_list=[]
left=copy.deepcopy(rname)
curr_node=start_point
ans_total_dist=0
while left.count(-1)<len(left):
    ans_list.append(curr_node)
    #print len(ans_list)
    ans,dist=find_nearest(curr_node,left)
    if ans==-1:
        break
    left[left.index(curr_node)]=-1
    ans_total_dist=ans_total_dist+dist
    if 1:   print 'from %d to %d, incr %d,total dist %d'%(curr_node,ans,dist,ans_total_dist)
    curr_node=ans

print 'answer list:'
print ans_list
print 'total dist: %d'%(ans_total_dist)
print 'average dist: %d'%(ans_total_dist/LENGTH)

print calc_total_dist (ans_list,rname,rx,ry,r_cg_domain)
total_dist_nearest=ans_total_dist

#===============================================================================
# #    INCR OPT:
#===============================================================================
print "Info: Start random opt"
out_file=open('random_reorder.record.txt','w')
out_file.write('random_reorder.record\n')
        
ans_list2=range(LENGTH)
for iter in range(LENGTH):
    ans_list2[iter]=ans_list[iter]

#for i in range(LENGTH*100):
STEP_U=10
STEP_V=10
if LENGTH>100:
    STEP_U=LENGTH/100
    STEP_V=LENGTH/100
    
START_REG_IN_RANDOM_REORDER=1 #because reg0 is the start reg, dont reorder
for u in range(START_REG_IN_RANDOM_REORDER,LENGTH,STEP_U):
    break # DISABLE THE INCR OPT STEP
    #print '%d, %d,'%(u,0)
    print u,
    for v in range(START_REG_IN_RANDOM_REORDER,u,STEP_V):
        #u=random.randint(0,LENGTH-1)
        #v=random.randint(0,LENGTH-1)
        ll=swap(ans_list2,u,v)
        out_str='try to swap:%d(%d,%d), %d(%d,%d) \n'%(u,rx[u],ry[u],v,rx[v],ry[v])
        out_file.write(out_str)
        dist_low_bound=calc_total_dist (ans_list2,rname,rx,ry,r_cg_domain)
        new_dist=calc_total_dist (ll      ,rname,rx,ry,r_cg_domain)
        
        if dist_low_bound>new_dist:
            #swap 
            #print '\nSWAP in iter:%d, %d'%(u,v)
            out_str='SWAP in iter:%d, %d\n'%(u,v)
            out_file.write(out_str)
            for iter in range(LENGTH):
                ans_list2[iter]=ll[iter]
                pass
        
print 'answer list2:'
print ans_list2
dist=calc_total_dist(ans_list2,rname,rx,ry,r_cg_domain)
print 'total dist2: %d'%(dist)
print 'average dist: %d'%(dist/LENGTH)
total_dist_random=dist

out_file.close()

'''
l1p1=[0,0]
l1p2=[1,1]
l2p1=[0,1]
l2p2=[1,0]
l1=[l1p1,l1p2]
l2=[l2p1,l2p2]
print 'exclude:'
print points_exclude(l1,l2)
print 'v_cross:'
print vector_cross(l1,l2)
print 'cross:'
print cross(l1,l2)
'''
print 'Info: begin of check cross----------------'
t=copy.deepcopy(ans_list2)
t2=copy.deepcopy(t)

dist=calc_total_dist(t2,rname,rx,ry,r_cg_domain)
dist_low_bound=dist

cross_flag=1
cntr=0
while (cross_flag and cntr<30):
    #t=copy.deepcopy(t2) # refresh t
    cross_flag=0
    cntr+=1
    print '========this is iter:'+str(cntr)
    for i in range(len(t2)-1):
        for j in range(i+1,len(t2)-1):
            l1=reg_pair2line(t2[i],t2[i+1])
            l2=reg_pair2line(t2[j],t2[j+1])
            if cross(l1,l2):
                print 'cross: 4regs [ind:%d,%d] (%d,%d)-(%d,%d)'%(i,j,t2[i],t2[i+1],t2[j],t2[j+1])
                #cross_reg=[t2[i],t2[i+1],t2[j],t2[j+1]]
                rn=t2[i];                print rn,rx[rn],ry[rn]
                rn=t2[i+1];                print rn,rx[rn],ry[rn]
                rn=t2[j];                print rn,rx[rn],ry[rn]
                rn=t2[j+1];                print rn,rx[rn],ry[rn]
                reverse(t2,i+1,j)
                dist=calc_total_dist(t2,rname,rx,ry,r_cg_domain)
                if dist>dist_low_bound:
                    print 'de-cross fail: %d > %d'%(dist,dist_low_bound)
                    reverse(t2,i+1,j)
                else:
                    cross_flag=1
                    print 'de-cross succ: %d < %d'%(dist,dist_low_bound)
                    dist_low_bound=dist
print 'Info: iteration finished when cntr='+str(cntr)         
total_dist_decross=       calc_total_dist(t2,rname,rx,ry,r_cg_domain)
print 'Info: end of check cross-----------------'


#===============================================================================
# #    AC algor:
#===============================================================================
'''
                                初始值
alpha    信息量影响因子
beta    路径长度影响因子
ac_in 城市名序列        
ant_per_city 每城市ant数
ant    蚂蚁所在地序列            每ant_per_city个一组，升序分布于每个城市
S    ant总数   S=LENGTH*ant_per_city
b[0:LENGTH] ant分布                    S/LENGTH
inf_t[i][j](t)信息量                    C=100
d_t[i][j][k]（t）当前t第k个ant对i->j路径留下的信息量    0
p_t[i][j][k]下一t第k个ant从i->j的概率
finished[k]第k个ant已走过的集合
allowed[k]第k个ant未走的集合

Q=100; #信息素增加强度系数 (对结果影响小)

'''
alpha=1
beta=1

ac_in=copy.deepcopy(series)
ant_per_city=1
S=LENGTH*ant_per_city
# init ant[]
ant=[-1 for i in range(S)]
loc=-1
for i in range(S):
    if i%ant_per_city==0:
        loc+=1
    print loc
    ant[i]=loc

b=[ant_per_city for i in range(LENGTH)]

C=100 #每条路信息量 初始值
inf_t=[[C for col in range(LENGTH)]for row in range(LENGTH)]

d_t=[[0 for col in range(LENGTH)]for row in range(LENGTH)]

p_t=[[0 for col in range(LENGTH)]for row in range(LENGTH)]
finished=[[-1 for n in range(LENGTH)]for k in range(S)]
allowed=[series for k in range(S)]

Q=100; #信息素增加强度系数 (对结果影响小)
#    BEGIN

t=-1
while t<1000:   # time iter
    t+=1
    
    #TODO:    add last d_t into inf_t
    #TODO:    clean d_t ready for this time-iter
    
    for one_ant in ant:     # ant iter
        #for i in series:    # start city iter
        start_city=one_ant
        allowed[one_ant].remove(start_city)
        for to_city in allowed[one_ant]:    #to city iter
            yita=1/(cal_dist_ac(start_city,to_city))
            p_t[start_city][to_city]=(inf_t[start_city][to_city]**alpha) * (yita**beta)
            #    zjc here
        goto_next_city=rand_choose_by_weight(allowed,p_t[start_city])
        
        allowed[one_ant].remove(goto_next_city)
        finished[one_ant].append(goto_next_city)
        
        d_t[start_city][goto_next_city]+=Q/(cal_dist_ac(start_city,goto_next_city))

#    END OF time iter

#    DUMP BEST SOLVE
ans_ac=[]
ans_ac.append(start_point)

left=copy.deepcopy(ac_in)
while (len(left)>0):
    ans_tail=ans_ac[-1]
    best_to=-1
    highest_info=-1
    for to in left:
        if inf_t[ans_tail][to]>highest_info:
            highest_info=inf_t[ans_tail][to]
            best_to=to
    
    print 'find best_to:%d,info:%d'%(best_to,highest_info)
    ans_ac.append(best_to)
    left.remove(best_to)#zjc
    

total_dist_ac=       calc_total_dist(ans_ac,rname,rx,ry,r_cg_domain)
#cal_dist_ac

#===============================================================================
# #    PLOT:
#===============================================================================

if GEN_PLOT:
    
    #plot_a_cfg(series,'141','gx-',title_v='base order in scandef\n'+str(total_dist0)+ratio(total_dist0,series))
    plot_a_cfg(ans_list,'142','rx-',title_v='nearest algthm\n'+str(total_dist_nearest)+ratio(total_dist_nearest,ans_list))
    #plot_a_cfg(ans_list2,'143','bx-',title_v='random incr opt\n'+str(total_dist_random)+ratio(total_dist_random,ans_list2))
    plot_a_cfg(ans_ac,'143','bx-',title_v='AC algthm\n'+str(total_dist_ac)+ratio(total_dist_ac,ans_ac))
    if LENGTH<=7:   
        plot_a_cfg(best_ll_yet,'144','cx-',title_v='enhaus\n'+str(best_dist)+ratio(best_dist,best_ll_yet))
    else:
        plot_a_cfg(t2,'144','cx-',title_v='decross\n'+str(total_dist_decross)+ratio(total_dist_decross,t2))
      
    '''
    plot_a_cfg(t2,'111','cx-',title_v='decross\n'+str(total_dist_decross)+ratio(total_dist_decross,t2))
    '''
        #plt.quiver()
    
    plt.show()
    
    '''
    print t2[37],t2[38],t2[39],t2[40]
    u=t2[37];print rx[u],ry[u]
    u=t2[38];print rx[u],ry[u]
    u=t2[39];print rx[u],ry[u]
    u=t2[40];print rx[u],ry[u]
    '''
    '''
    u=t2[50];print rx[u],ry[u]
    u=t2[29];print rx[u],ry[u]
    u=t2[32];print rx[u],ry[u]
    u=t2[28];print rx[u],ry[u]
    '''
'''
        24 6 13 132
242 657
855 658
539 736
460 631
'''

'''
#i=37;j=39
l1=reg_pair2line(50,29)
l2=reg_pair2line(32,28)

print points_exclude(l1,l2)
print vector_cross(l1,l2)
print cross(l1,l2)
'''
