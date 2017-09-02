#################################################
# kmeans: k-means cluster
# Author : zouxy
# Date   : 2013-12-25
# HomePage : http://blog.csdn.net/zouxy09
# Email  : zouxy09@qq.com
#################################################

from numpy import *
import time
import matplotlib.pyplot as plt
import k_means

## step 1: load data
print "step 1: load data..."
dataSet = []
fileIn = open('D:\workspace_python\k_means\src\sample.txt')
for line in fileIn.readlines():
   lineArr = line.strip().split('\t')
   dataSet.append([float(lineArr[0]), float(lineArr[1])])

## step 2: clustering...
print "step 2: clustering..."
dataSet = mat(dataSet)
k = 2
centroids, clusterAssment = k_means.kmeans(dataSet, k)

## step 3: show the result
print "step 3: show the result..."
k_means.showCluster(dataSet, k, centroids, clusterAssment)