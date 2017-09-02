import CalcAbstract
class FactoryOfCalc():
   def __init__(self):
      pass
   def get_calc(self):
      s=CalcAbstract.CalcAbstract()

class FactoryOfCalcAdd(FactoryOfCalc):
   def __init__(self):
      pass
   def get_calc(self):
      s=CalcAbstract.CalcAdd()
      return s
class FactoryOfCalcSub(FactoryOfCalc):
   def __init__(self):
      pass
   def get_calc(self):
      s=CalcAbstract.CalcSub()
      return s
class FactoryOfCalcMul(FactoryOfCalc):
   def __init__(self):
      pass
   def get_calc(self):
      s=CalcAbstract.CalcMul()
      return s
class FactoryOfCalcDiv(FactoryOfCalc):
   def __init__(self):
      pass
   def get_calc(self):
      s=CalcAbstract.CalcDiv()
      return s



if __name__ == "__main__":
   sf=FactoryOfCalcDiv()
   s=sf.get_calc()
   ans=s.calc(1, 2)
   print ans