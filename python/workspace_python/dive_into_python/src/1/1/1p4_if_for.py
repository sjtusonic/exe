#   if

#c=raw_input("input 3 num:")

u=1
v=2
w=3

if u>v and u>w:
    print str(u)+" large"
elif w>v and u<w:
    print str(w)+" large"
else:
    print str(v)+" large"


#   for
print ""
print "TEST of for"
t=range(3,14,2)
for i in t:
    print i
    
print ""
print "SUM:"
sum = 0
n = 99
while n > 0:
    sum = sum + n
    n = n - 2
print sum
