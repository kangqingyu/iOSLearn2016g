# -*- coding: utf-8 -*-

"""
Script Name : gitCommit.py
Author      : LURUI
Created     : 4 April 2016
Version     : 1.1
Description : This simple script is to commit and push changes of my project to GitHub automatically.

"""

import os
import numpy as np
import subprocess
import time
import sys

if len(sys.argv) == 1:
    commitNum = np.random.randint(1,3)
elif len(sys.argv) == 2:
    commitNum = int(sys.argv[1])
else:
    print "the number of optional argument is wrong, must be 0 or 1!"

fileType = ['.txt','.html','.md','.jpg']
print 'the program will make %s commits today!' %(commitNum)
for i in range(commitNum):
    typeNum = np.random.randint(0,4)
    fileName = np.random.randint(100,1000)
    path = str(fileName)+fileType[typeNum]
    with open(path,'wb') as code:
        code.close()
    print str(fileName)+fileType[typeNum]+' have been created!'
    gitShell = subprocess.Popen('sync.sh',shell=True)
    print 'the new change is being commited and push, please wait a few seconds!'
    if gitShell.wait() == 0:
        os.remove(path)
        print str(fileName)+fileType[typeNum]+' have been deleted!'
print 'all changes have been committed!'
raw_input('press Enter to exit!')

