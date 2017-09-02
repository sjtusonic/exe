'''
Created on 2014-9-27

@author: admin
'''


print 'TEST'


for i in range(0,10):
    print i
else:
    print 'loop is over'
    
#   INPUT:
#name= raw_input("What's your name:\n");
name="john"
print "Hello, "+name+"!"

#   BRANCH:
if cmp(name,'john')==0:
    print "your name is john"
else:
    print "you are not john"

#   MULTI-LINE
print '''line1
...line2
...line3'''

#   BOOLEAN
a=9
b=5
c=1

def swap(s1,s2):
    
    return s2,s1;# func can return 2 values in Python!!
    
if a>b and b>c:
    print "series is full reverse"
else:
    print "series is NOT full reverse"

if a>b:
    a,b=swap(a,b)
if b>c:
    b,c=swap(b,c)
if a>b:
    a,b=swap(a,b)
    
print a,b,c
