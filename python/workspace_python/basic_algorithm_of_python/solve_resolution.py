__author__ = 'jc'

freshWaterAmount=10;
clothWaterRemain=10;
powderAmount=1000;

totalStep=10000;

freshWaterAmountPerStep=freshWaterAmount/totalStep;

densityList=[];

powderLeft=powderAmount
currentDensity=powderLeft/clothWaterRemain;
densityList.append(currentDensity)

for i in range(totalStep):
    print("ITER:"+str(i))
    nextDensity=clothWaterRemain*currentDensity/(clothWaterRemain+freshWaterAmountPerStep)
    print("DENSITY "+str(currentDensity)+' -> '+str(nextDensity))
    currentDensity=nextDensity

print(str(1000**0.5))