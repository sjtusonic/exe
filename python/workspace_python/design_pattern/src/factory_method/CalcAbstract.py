
class CalcAbstract:
   def calc(self):
      print 'calc'
      pass
   
class CalcAdd (CalcAbstract):
   def __init__(self):
      pass
   def calc(self,a,b):
      return a+b
   
class CalcSub (CalcAbstract):
   def __init__(self):
      pass
   def calc(self,a,b):
      return a-b
   
class CalcMul (CalcAbstract):
   def __init__(self):
      pass
   def calc(self,a,b):
      return a*b
   
class CalcDiv (CalcAbstract):
   def __init__(self):
      pass
   def calc(self,a,b):
      return a/b
   