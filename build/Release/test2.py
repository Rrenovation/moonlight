#!/usr/bin/python3
import time
import moonlight

#adbPath = "C:\\Users\\Administrator\\Documents\\code\\moonlight\\build\Release\\adb"
adbPath = "C:\\Release\\adb"
deviceName = "1.12.225.194:5555"
server = moonlight.moonlight()


def task():
    while(1):
        print("task running !")
        time.sleep(1)


def loop():
    server.loop()
    while(server.isRunning() == False):
        print("wait server init")
        time.sleep(1)
    server.setAdbPatch(adbPath)


def deviceCtl():
    device = server.getLight(deviceName)
    while(device.status() == False):
        print("wait for connect :" + deviceName)
        time.sleep(1)
    while(1):
        device.capture(0,0,720,1280,"C:\\capture1.bmp")
        print(deviceName + " is connected")
        time.sleep(1)


if __name__ == '__main__':
    loop()
    deviceCtl()
    task()
