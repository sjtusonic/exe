__author__ = 'jc'

#-*- coding: utf8 -*-
import xlrd
import re

fname = "Alaska_scan_plan.xlsx"
bk = xlrd.open_workbook(fname)
shxrange = range(bk.nsheets)
try:
    sh = bk.sheet_by_name("Sheet1")
except:
    print "no sheet in %s named Sheet1" % fname

nrows = sh.nrows
ncols = sh.ncols
print "nrows %d, ncols %d" % (nrows,ncols)
cell_value = sh.cell_value(1,1)
#print cell_value

item_list =[]
row_list = []
for i in range(1,nrows):
    if i==2:
        item_data= sh.row_values(i)
        print item_data

    if i==8:
        row_data = sh.row_values(i)

        print row_data
        row_list.append(row_data)

for i in range(len(item_data)):
    item=item_data[i]
    #print "%s\t=\t%s"%(item,row_data[i])
    result, number = re.subn(" ", "_", item)
    result, number = re.subn("#", "cnt", result)
    result, number = re.subn("\.", "", result)
    #print "%s\t=\t%s"%(item_data[i],row_data[i])
    print "set %s \t%s"%(result,row_data[i])