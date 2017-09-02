#   tuple
cm=("a","b","c")

print cm[1]


u=["u1","u2"]
v=["v1","v2"]
cm=(u,v,"w")
print cm
#cm[0]="change" ;# can not change, cause error
print cm
cm[0][0]="u1change";# can change, because u is list not a tuple
print cm
