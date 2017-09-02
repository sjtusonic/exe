#   advanced topics:

#   slicing:
i=range(3,20,2)
print i
print i[5:]

#    slice of string
print 'abcdefg'[-2:]

#   Iteration:
for j in 'abcde'[:3]:
    print j

d={'a':1,'b':2,'c':3}
for j in d.itervalues():
    print j
    
d={'a':1,'b':2,'c':3}
for j in d.iteritems():
    print j

print "-------------"

for char in "user_id":
    print char
    
#   filter
print [x * x for x in range(1, 12)]
print [x * x for x in range(1, 12) if x>6]
print [d for d in 'abcde']
print [m+n for m in 'ABC' for n in 'XYZ']

import os
print [os.listdir('.')]

#   generator:
l=[x*x for x in range(5)]
g=(x*x for x in range(5))
print l 
print g 
print g.next()

for i in g:
    print i
    
#   lambda
f=lambda x:x*x
print "3 * 3 is ",f(3)

g=lambda x,y:x**y
print g(2,3)

