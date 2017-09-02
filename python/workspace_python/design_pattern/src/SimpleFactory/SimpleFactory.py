__author__ = 'jc'


'''
client
|
SimpleFactory             abstract_product
                    |
                    concrete_product1 concrete_product2
'''

class SimpleFactory:
    def getProduct(self,item):
        print 'in proc getProduct, retult='+item
        if item=='A':
            return ProductA()
        else:
            return ProductB()

class AbstractProduct:
    def say(self):
        print 'I\'m AbstractProduct!'

class ProductA(AbstractProduct):
    def say(self):
        print 'I\'m productA'

class ProductB(AbstractProduct):
    def say(self):
        print 'I\'m productB'

if __name__ == "__main__":
   sf = SimpleFactory()

   calcA=sf.getProduct('A')
   calcA.say()

   calcB=sf.getProduct('B')
   calcB.say()

