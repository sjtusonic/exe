#   FUNC:
def power(x):
    return x*x

def power_m(x,n=2):
    return x**n

print power(3)
print power_m(4)
print power_m(2,3)

def enroll(name, gender, age=6, city='Beijing'):
    print '---------'
    print 'name:', name
    print 'gender:', gender
    print 'age:', age
    print 'city:', city
    
enroll('john','M',3,'Kaifeng')

enroll('Jenny','F',city='Wuhan',age=11);# not ordered args
enroll('Jenny','F',city='Wuhan' );# single special args

#   a grammar that can cause bug:
def add_end (L=[]):
    L.append('END')
    return L
    
print add_end()
print add_end()
print add_end();# END END END...

def add_end_right (L=None):
    if L is None:
        L=[]
    L.append('END')
    return L

print add_end_right()
print add_end_right()
print add_end_right();# END END END...

#    args# can be changed
def calc(numbers):
    sum = 0
    for n in numbers:
        sum = sum + n * n
    return sum

print calc([1,2,3])

def calc2(*numbers):
    sum = 0
    for n in numbers:
        sum = sum + n * n
    return sum

print calc2(1,2)
print calc2()
    
#    a good using
nums=[1,2,3,4]
print calc2(*nums)
    
#    keyword arg:
def person(name, age, **kw):
    print 'name:', name, 'age:', age, 'other:', kw

print person('John','M')
 
print person('John','M',u1=1,u2=2,u3=3,addr='a street')


#    4 types of args

def func(a, b, c=0, *args, **kw):
    print 'a =', a, 'b =', b, 'c =', c, 'args =', args, 'kw =', kw

print func('avalue','bvalue',)


func(1, 2)
func(1, 2, c=3)
func(1, 2, 3, 'a', 'b')
func(1, 2, 3, 'a', 'b', x=99)

#    a magic way
print 'magic way:'
args = (1, 2, 3, 4)
kw = {'x': 99}
func(*args, **kw)
