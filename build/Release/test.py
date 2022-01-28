#!/usr/bin/python3
import time
import moonlight

server = moonlight.moonlight()
adbPath = "C:\\adb\\adb"
deviceDict={"ServerPort":"ServerIP"}

deviceNum = 1
deviceList = [
    "1.12.225.194:5555",
    "1.12.225.194:5556",
    "1.12.225.194:5557",
    "1.12.225.194:5558",
    "1.12.225.194:5559"
]

def ServerLoop():
    server.loop()
    while(server.isRunning() == False):
        print("wait server init")
        time.sleep(1)
    server.setAdbPatch(adbPath)

def ConnectDevice():
    for device in range(deviceNum):
        deviceName = deviceList[device]
        print("well be connect : "+ deviceName)
        NewDevice = server.getLight(deviceName)
        while(NewDevice.status() == False):
            print("wait for connect :" + deviceName)
            time.sleep(1)
        deviceDict[deviceName] = NewDevice
        print("device: "+deviceName+" is connected")

def TasksLoop():
    while(True):
        print("wait for task !")
        time.sleep(5)


if __name__ == '__main__':
    ServerLoop()
    ConnectDevice()
    TasksLoop()

