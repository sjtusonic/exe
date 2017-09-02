__author__ = 'jc'
__version__='use Abstract Factory'
class Cashier:
    def getMethod(self,name):

        if name=='normal':
            return calcBasic()
        elif name=='debate':
            return calcDebate()
        elif name=='fullcut'
            return calcFullCut
        else:
            print 'illegal argument:'+name

class AbstractCalc:
    def calc(self,sumIn):
        pass

class calcBasic(AbstractCalc):
    def calcBasic(self):
        pass
    def calc(self,sumIn):
        return sumIn
class calcDebate(AbstractCalc):
    def calcDebate(debate):
        self.debate=debate
    def calc(self,sumIn):
        return sumIn*self.debate

class calcFullCut(AbstractCalc):
    def calcFullCut(bound,cut):
        self.bound=bound
        self.cut=cut
    def calc(self,sumIn):
        if sumIn>=self.bound:
            return sumIn-self.cut
        else:
            return sumIn

if __name__ == "__main__":
    cs=Cashier()
    method=cs.getMethod('normal')
    method
