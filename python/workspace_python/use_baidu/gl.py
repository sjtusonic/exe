#! /usr/bin/env python
#coding=utf-8

def printGB(s):
    #s="中文" 
    if isinstance(s, unicode): 
        #s=u"中文" 
        print s.encode('gb2312') 
    else: 
        #s="中文" 
        print s.decode('utf-8').encode('gb2312')
    
