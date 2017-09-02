__author__ = 'jc'

import re

f=open('ttt')

ll=f.readlines()
hash_word_cnt=dict()

pattern_list=[]
for i in '->?()[]{}""|&^*%#@!+-~=_$,1234567890abcdefghijklmnopqrstuvwxyz/\\.:;<>`\'':
    pattern_list.append(i)

for line in ll:
    line=line.lower()
    for i in pattern_list:
        line=line.replace(i," ")
    list_words=line.split()
    for word in list_words:
        #print(word)
        #word=word.lower()
        if re.match(r'[a-z]',word) or re.match(r'^\d+$',word):
            continue
        if word in hash_word_cnt.keys():
            hash_word_cnt[word]+=1
        else:
            hash_word_cnt[word]=1

l1=sorted(hash_word_cnt.items(),key=lambda d:d[1],reverse=True)

#print (l1)

for i in l1[:1000]:
    print('%-80s%10s'%(i[0],i[1]))
'''
for word in l1:
    print('%-20s%10s'%(word,hash_word_cnt[word]))
'''

f.close()

