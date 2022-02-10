#include "moonlight.h"
#include "../log/log.hpp"

moonlight::moonlight(int _port, int argc, char **argv) : port(_port), mApp(new QCoreApplication(argc, argv)), Running(false)
{
    logs::info("moonlight init !");
}

moonlight::~moonlight()
{
    exit();
    wait();
}

void moonlight::loop()
{
    start();
}

void moonlight::run()
{
    logs::info("moonlight thread is running !");
    // deps processEvents thread
    server = new Server(); 
    monitors = new monitor();

    for (int i = 0; i < 100; i++)
    {
        port += i;
        if (server->startServer(port))
        {
            monitors->setPort(port);
            monitors->start();
            break;
        }
    }
    mApp->processEvents();
    Running = true;
    exec();
    delete server;
    delete monitors;
}

bool moonlight::isRunning() const
{
    return Running;
}

light moonlight::getLight(std::string deviceName)
{
    auto deviceN = QString::fromStdString(deviceName);
    if (deviceList.find(deviceN) == deviceList.end())
    {
        auto device = new lewone();
        device->setDeviceName(deviceN);
        monitors->pushDevice(device);
        deviceList[deviceN] = device;
        server->pushDevice(dynamic_cast<Device *>(device));
        logs::info("New device: " + deviceName +" well be connect");
    }
    return light(deviceList[deviceN]);
}

void moonlight::setAdbPatch(string _path)
{
    monitors->setAdbPatch(_path.c_str());
}