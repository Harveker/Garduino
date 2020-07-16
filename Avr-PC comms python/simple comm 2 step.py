# -*- coding: utf-8 -*-
"""
Created on Tue Jul 14 22:38:50 2020

@author: franc
"""

import serial
import time

startMarker = '<'
endMarker = '>'
dataStarted = False
dataBuf = ""
message = False

#==================================
#==================================
        #the functions

def setupSerial(baudRate, serialPortName):
    
    global serialPort
    
    serialPort = serial.Serial(port= serialPortName, baudrate = baudRate, timeout = 0, rtscts = True)
    
    print("Serial port" + serialPortName + "opened Baudrate" + str(baudRate))
    
    waitForArduino()
    
#==================================
def sendToArduino(stringToSend):
        
        #this adds the start- and end-markers before sending global startMarker, endMarker, serialPort
    
    stringWithMarkers = (startMarker)
    stringWithMarkers += stringToSend
    stringWithMarkers += (endMarker)

    serialPort.write(stringWithMarkers.encode('utf-8')) #encode needed for Python3
        
#==================================

    def recvLikeArduino():
    
        global startMarker, endMarker, serialPort, dataStarted, dataBuf, messageComplete

        if serialPort.inWaiting() > 0 and messageComplete == False:
            x =serialPort.read().decode("utf-8") #decode needed for Phyton3
        
            if dataStarted == True:
                if x != endMarker:
                    dataBuf = dataBuf + x
                else:
                    dataStarted = False
                    messageComplete = True
            elif x == startMarker:
                dataBuf = ''
                dataStarted = True
            
        if (messageComplete == True):
            messageComplete = False
            return dataBuf
        else:
            return "xxx"
        
#==================================

    def waitForArduino():
    
        #wait until the Arduino sends 'Arduino is ready' - allows time for arduino reset.
        #it also ensures that any bytes left over from a previous message are discarded.
    
        print("Waiting for Arduino to reset")
    
        msg = ""
        while msg.find("Arduino is ready") == -1:
            msg = recvLikeArduino()
        if not (msg == 'XXX'):
            print(msg)

#==================================
#==================================
            #the program
            
setupSerial(115200,'com4')
count = 0
prevTime= time.time(0)
while True:
            #check for a reply
    
    arduinoReply = recvLikeArduino()
    if not (arduinoReply == 'XXX'):
        print("Time %s Reply %s" %(time.time(), arduinoReply))
        
        #send a message at intervals
    if time.time() - prevTime > 1.0:
        sendToArduino("this is a test" + str(count))
        prevTime = time.time()
        count += 1