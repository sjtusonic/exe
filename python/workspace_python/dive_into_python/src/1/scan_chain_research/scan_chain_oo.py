
rname=range(10)
rx=range(10)
ry=range(10)

rx[0] = 859
ry[0] = 740
rx[1] = 134
ry[1] = 92
rx[2] = 315
ry[2] = 721
rx[3] = 840
ry[3] = 621
rx[4] = 638
ry[4] = 772
rx[5] = 690
ry[5] = 591
rx[6] = 950
ry[6] = 191
rx[7] = 606
ry[7] = 596
rx[8] = 130
ry[8] = 494
rx[9] = 687
ry[9] = 653

import random

W=1000
H=1000

r=None

class Reg(object):
    def __init__(self, name, loc_x,loc_y):
        self.name= name
        self.x=loc_x
        self.y=loc_y
        self.pre=None
        self.next=None
        self.print_loc()
    def print_loc(self):
        print 'reg: %s is located in %s, %s' %(self.name, self.x, self.y)



head=Reg('head',0,0)
lastReg=Reg('temp',0,0)
lastReg=head


for i in range(10):
    tempReg=Reg(rname[i],rx[i],ry[i])
    lastReg.next=tempReg
    tempReg.pre=lastReg
    

lastReg=head
thisReg=Reg('temp',0,0)
while lastReg.next!=None:
    thisReg=lastReg.next
    thisReg.print_loc()

