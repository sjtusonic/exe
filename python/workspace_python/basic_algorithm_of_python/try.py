
# -*- coding: cp936 -*-
def strQ2B(ustring):
    """ȫ��ת���"""
    rstring = ""
    for uchar in ustring:
        inside_code=ord(uchar)
        if inside_code == 12288:                              #ȫ�ǿո�ֱ��ת��
            inside_code = 32
        elif (inside_code >= 65281 and inside_code <= 65374): #ȫ���ַ������ո񣩸��ݹ�ϵת��
            inside_code -= 65248

        rstring += chr(inside_code)
    return rstring

def strB2Q(ustring):
    """���תȫ��"""
    rstring = ""
    for uchar in ustring:
        inside_code=ord(uchar)
        if inside_code == 32:                                 #��ǿո�ֱ��ת��
            inside_code = 12288
        elif inside_code >= 32 and inside_code <= 126:        #����ַ������ո񣩸��ݹ�ϵת��
            inside_code += 65248

        rstring += unichr(inside_code)
    return rstring



b = strQ2B("���123abc����԰".decode('cp936'))
print (b)

c = strB2Q("���123abc����԰".decode('cp936'))
print (c)
