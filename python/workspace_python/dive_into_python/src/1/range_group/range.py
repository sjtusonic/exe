#    MATH:    group, ring, domain
#    calc in range

def show_range(ll):
    '''gen range by abstract form'''
    print "full form of range",ll,"is:"
    for i in range(10):
        print i,
    print ""

    out={1:1}
    for i in range(10):
        out[i]=i
        for j in ll:
            if j==i:
                index=ll.index(j)
                #print "index of",j," is",index
                length=len(ll)
                if index==length-1:
                    index=-1
                ret=ll[index+1]
                #print "return ", ret
                out[i]=ret
                
    for i in range(10):
        print out[i], 
    print ""        
    return out

def show_abs():
    pass

def mul(full1,full2):  
    print "full form of mul ",full1," x ",full2," is:"
    for i in range(10):
        print i,
    print ""
  
    out={1:1}
    for key1,values1 in full1.items():
        for key2,values2 in full2.items():
            if key1 == key2:
                continue
    for i in range(10):
        out[i]=full1[full2[i]]
            
    for i in range(10):
        print out[i], 
    print ""        
    return out

    pass
    
abs1=[1,3,5,7,8]
abs2=[2,5,8]


#show_range(abs1)
f1=show_range(abs1)
f2=show_range(abs2)

mul(f1,f2)