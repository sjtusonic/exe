__author__ = 'admin'

import sys

from pyocr import pyocr


print ('TEST')
tools = pyocr.get_available_tools()[:]
if len(tools) == 0:
    print("No OCR tool found")
    sys.exit(1)
print("Using '%s'" % (tools[0].get_name()))
tools[0].image_to_string(Image.open('test.png'), lang='fra',
                         builder=TextBuilder())