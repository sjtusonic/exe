import win32com.client, time, pythoncom

"""
MSOffice2PS - Microsoft Office to Postscript Converter 1.1
Makes a Postscript file from Word-, Excel- or Powerpoint.

Now with mutex support for Powerpoint. Because Powerpoint can
only run as a single instance.

usage:
first: import msoffice2ps in the script, where it should be used
then call the convert-function. 

import msoffice2ps
msoffice2ps.word('wordfilename', 'psfilename', 'ps_printername')
msoffice2ps.excel('excelfilename', 'psfilename', 'ps_printername')
msoffice2ps.powerpoint('powerpointfilename', 'psfilename', 'ps_printername')

Dipl.-Ing. Mustafa Goermezer -> http://www.goermezer.de
"""

def word(wordfile, psfile, printer):
    pythoncom.CoInitializeEx(pythoncom.COINIT_APARTMENTTHREADED)
    myWord = win32com.client.DispatchEx('Word.Application')
    myWord.Application.ActivePrinter = printer
    myDoc = myWord.Documents.Open(wordfile, False, False, False)
    myDoc.Saved=1
    myWord.Application.NormalTemplate.Saved = 1
    myWord.PrintOut(True, False, 0, psfile)
    while myWord.BackgroundPrintingStatus > 0:
        time.sleep(0.1)
    myDoc.Close()
    myWord.Quit()
    del myDoc
    del myWord
    pythoncom.CoUninitialize()

def excel(excelfile, psfile, printer):
    pythoncom.CoInitializeEx(pythoncom.COINIT_APARTMENTTHREADED)
    myExcel = win32com.client.DispatchEx('Excel.Application')
    myExcel.Application.AskToUpdateLinks = 0
    Excel = myExcel.Workbooks.Open(excelfile, 0, False, 2)
    Excel.Saved = 1
    Excel.PrintOut(1, 5000, 1, False, printer, True, False, psfile)
    Excel.Close()
    myExcel.Quit()
    del myExcel
    del Excel
    pythoncom.CoUninitialize()

def powerpoint(powerpointfile, psfile, printer):
    from win32event import CreateMutex
    from win32api import GetLastError
    from winerror import ERROR_ALREADY_EXISTS
    from sys import exit
    #the guid in the next line must be unique !!!
    handle = CreateMutex ( None, 1, '{D0E858DF-985E-4907-B7FB-8D732C3FC3B9}' )
    if GetLastError ( ) == ERROR_ALREADY_EXISTS:
        print 'Powerpoint conversion already working'
        exit ( 1 )
    pythoncom.CoInitializeEx(pythoncom.COINIT_APARTMENTTHREADED)
    myPowerpoint = win32com.client.DispatchEx('Powerpoint.Application')
    myPpt = myPowerpoint.Presentations.Open(powerpointfile, False, False, False)
    myPpt.PrintOptions.PrintInBackground = 0
    myPpt.PrintOptions.ActivePrinter = printer
    myPpt.Saved = 1
    myPpt.PrintOut(1, 5000, psfile, 0, False)
    myPpt.Close()
    #myPowerpoint.Quit()
    del myPpt
    #del myPowerpoint
    pythoncom.CoUninitialize()
