__author__ = 'by jc'

# Abstract Factory

'''
client
|
AbsFactory             abstract_product
|
ConcreteFactory1 ConcreteFactory2  -> concrete_product1 concrete_product2
'''

class Person:
    def say(self):
        pass

class Teacher(Person):
    def say(self):
        print 'I\'m a teacher'

class Farmer(Person):
    def say(self):
        print 'I\'m a farmer'

if __name__ == "__main__":
    i=Farmer()
    i.say()
