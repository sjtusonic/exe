import re
#import xlrd
#import xlwt


def sort_by_value(d): 
    items=d.items() 
    backitems=[[v[1],v[0]] for v in items] 
    backitems.sort() 
    return [ backitems[i][1] for i in range(0,len(backitems))] 


#f=open('D:\workspace_python\dive_into_python\src\1\word_sum\liric.txt','r')
f=open('D:\liric.eng.txt','r')

#f=open('D:\\fhw.txt','r')

f_info= f.read()
f_info_LOW=f_info.lower()
tmp = re.sub(r'\'re', ' are', f_info_LOW)
tmp1= re.sub(r'don\'t', 'do not', tmp)
tmp = re.sub(r'\'ll', ' will', tmp1)
tmp1= re.sub(r'"', '', tmp)
tmp = re.sub(r',', ' ', tmp1)
tmp1= re.sub(r'\'m', ' am', tmp)
tmp = re.sub(r'\'s', ' is', tmp1)
f_info=tmp
print f_info
f_info_list=re.split(r'\s+', f_info)

print f_info_list[4]
print f_info_list
word_cnt= len(f_info_list)

#sum=None
sum={'':0}
for w in f_info_list:
    if w in sum:
        sum[w]=sum[w]+1
    else:
        sum[w]=1

print '----------'
#print sum
for k in sort_by_value(sum):
    pr_value=(float(sum[k])/word_cnt)
    if (pr_value>0.01):
        print k,":",'%6.2f'%pr_value
    
    pass

#    open read xls

#    open write xls

cntr=1 
for k in sort_by_value(sum):
    #print k,":",'%6.2f'%(float(sum[k])/word_cnt)
    value='%6.2f'%(float(sum[k])/word_cnt)
    #print table.cell(cntr,2)
    cntr=cntr+1
    
#   SAVE
#book.save('D:\workspace_python\exe_out.xlsx')