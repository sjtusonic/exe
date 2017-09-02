__author__ = 'jc'
#python3.3关于Tkp中的Treeview使用方法
import os
import tkinter as tk
from tkinter import ttk
class App(tk.Frame):
    def __init__(self, master, path):
        tk.Frame.__init__(self, master)
        self.tree = ttk.Treeview(self)
        ysb = ttk.Scrollbar(self, orient='vertical', command=self.tree.yview)
        xsb = ttk.Scrollbar(self, orient='horizontal', command=self.tree.xview)
        self.tree.configure(yscroll=ysb.set, xscroll=xsb.set)
        self.tree.heading('#0', text='Path', anchor='w')

        abspath = os.path.abspath(path)
        root_node = self.tree.insert('', 'end', text=abspath, open=True)
        self.process_directory(root_node, abspath)
        #构建一个grid
        self.tree.grid(row=0, column=0)
        ysb.grid(row=0, column=1, sticky='ns')
        xsb.grid(row=1, column=0, sticky='ew')
        self.grid()

    def process_directory(self, parent, path):
        #遍历路径下的子目录
        for p in os.listdir(path):
            #构建路径
            abspath = os.path.join(path, p)
            #是否存在子目录
            isdir = os.path.isdir(abspath)
            oid = self.tree.insert(parent, 'end', text=p, open=False)
            if isdir:
                self.process_directory(oid, abspath)

root = tk.Tk()
#path_to_my_project = "D:\\ex"
path_to_my_project = "D:\\StormMedia"
app = App(root, path=path_to_my_project)
app.mainloop()
