#include "monitor.h"
#include "../log/log.hpp"

monitor::monitor(/* args */) : MianthreadExit(false)
{
    logs::info("monitor init !");
}

monitor::~monitor()
{
    MianthreadExit = true;
    quit();
    wait();
    for (auto adb : adbList)
    {
        adb->terminate();
    }
}

void monitor::run()
{
    logs::info("monitor thread is running !");
    while (!MianthreadExit)
    {
        for (auto device : deviceList)
        {
            auto deviceName = device->getDeviceName();
            if (adbList.find(deviceName) == adbList.end())
            {
                auto adb = new Adbprocess();
                adb->setSerial(device->getDeviceName());
                adb->setAdbPatch(path);
                adbList[deviceName] = adb;
            }

            if (!device->getStatus() && conectTimeList[device->getDeviceName()])
            {
                for (size_t i = 0; i < 10; i++)
                {
                    if (adbList[deviceName]->autoConnect(port))
                    {
                        logs::info(deviceName.toStdString() + ": connected");
                        sleep(5);
                        break;
                    }
                    msleep(100);
                }
                if(!device->getStatus())
                {
                    conectTimeList[device->getDeviceName()]--;
                    logs::info(deviceName.toStdString() + " connecting time {:d}", conectTimeList[device->getDeviceName()]);
                }
            }

            if (device->getReStart())
            {
                auto adb = adbList[device->getDeviceName()];
                if (adb->isRuning())
                {
                    adb->stopApp();
                }
                device->setRest(false);
                conectTimeList[device->getDeviceName()] = MaxConnectTime;
                // delete adb;
                // adbList.remove(device->getDeviceName());
            }
        }
        sleep(1);
    }
}

void monitor::pushDevice(lewone *device)
{
    conectTimeList[device->getDeviceName()] = MaxConnectTime;
    deviceList.insert(device);
}

void monitor::setPort(int _port)
{
    port = _port;
}

void monitor::setAdbPatch(QString _path)
{
    path = _path;
}