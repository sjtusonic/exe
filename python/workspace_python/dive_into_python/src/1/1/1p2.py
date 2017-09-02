#   LIST
classmates=['a','b','c']
print len(classmates)
print classmates[1]
print classmates[-1]

print classmates

classmates.append('d')
print classmates

classmates.extend(['e','f','g'])
print classmates

classmates.append(['e','f','g'])
print classmates

classmates.insert(1,'insert1');# insert in front of list[1]
classmates.insert(-2,'insert-2');# insert in front of list[-2]
print classmates

classmates.pop()
print classmates

classmates.sort()
print classmates

classmates.pop(3)
print classmates

L=[]
print L.__len__()