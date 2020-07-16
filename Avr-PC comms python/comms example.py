# -*- coding: utf-8 -*-
"""
Created on Wed Jul 15 20:53:10 2020

@author: franc
"""

import serial
import time
x = 0
ser = serial.Serial('com4',baudrate = 9600, timeout = 2)
time.sleep(3)
numPoints = 3
dataList = [0]*numPoints
'''dataFile = open('dataFile.txt', 'w')'''

def getValues ():
    
    ser.write(b'g')
    arduinoData = ser.readline().decode().split('\r\n')
    
    return arduinoData[0]

while(1):
    
    userInput = input('get data?')
    
    if userInput == 'y':
        for i in range(0,numPoints):
            data = getValues()
            dataList[i] = data
    print(dataList)
    
    