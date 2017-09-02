#   HASH:

score={'a':100,'b':99,'c':98}

print score
print score['c']

score['new']=60
print score['new']
print score

print 'somebody' in score
score['somebody']=99
print 'somebody' in score

print '======================'
print score.get('b')
print score.get('nobody')

print score
score.pop('somebody')
print score

#   SET
print '======================'
ll=[1, 1, 2, 2, 3, 3]
print ll
s = set(ll)
print s